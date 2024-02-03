#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* private functions *********************************************************/

/* Position in the buffer of the array element at position index */
static int index_to_offset ( const DynamicArray * da, int index ) {
    return index + da->origin;
}

/* Position of the element at buffer position 'offset' */
static int offset_to_index ( const DynamicArray * da, int offset ) {
    return offset - da->origin;
}

/* Non-zero if and only if offset lies ouside the buffer */
static int out_of_buffer ( DynamicArray * da, int offset ) {
    return offset < 0 || offset >= da->capacity;
}

/* Makes a new buffer that is twice the size of the old buffer,
   copies the old information into the new buffer, and deletes
   the old buffer */
static void extend_buffer ( DynamicArray * da ) {

    double * temp = (double *) calloc ( 2 * da->capacity, sizeof(double) );
    int new_origin = da->capacity - (da->end - da->origin)/2,
           new_end = new_origin + (da->end - da->origin);

    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        temp[new_origin+i] = DynamicArray_get(da,i);
    }

    free(da->buffer);
    da->buffer = temp;

    da->capacity = 2 * da->capacity;
    da->origin = new_origin;
    da->end = new_end;

    return;

}

/* public functions **********************************************************/

DynamicArray * DynamicArray_new(void) {
    DynamicArray * da = (DynamicArray *) malloc(sizeof(DynamicArray));
    da->capacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;    
    da->buffer = (double *) calloc ( da->capacity, sizeof(double) ); 
    da->origin = da->capacity / 2;
    da->end = da->origin;
    return da;
}

void DynamicArray_destroy(DynamicArray * da) {
    free(da->buffer);
    da->buffer = NULL;
    return;
}

int DynamicArray_size(const DynamicArray * da) {
    assert(da->buffer != NULL);
    return da->end - da->origin;
}

char * DynamicArray_to_string(const DynamicArray * da) {
    assert(da->buffer != NULL);
    char * str = (char *) calloc (20,DynamicArray_size(da)),
         temp[20];
    int j = 1;
    str[0] = '[';
    for ( int i=0; i < DynamicArray_size(da); i++ ) {
        if ( DynamicArray_get(da,i) == 0 ) {
            snprintf ( temp, 20, "0" );
        } else {
            snprintf ( temp, 20, "%.5lf", DynamicArray_get(da,i) ); 
        }
        if ( i < DynamicArray_size(da) - 1 ) {
            sprintf( str + j, "%s,", temp);
            j += strlen(temp) + 1;
        } else {
            sprintf( str + j, "%s", temp);
            j += strlen(temp);
        }

    }
    str[j] = ']';
    return str;
}

void DynamicArray_print_debug_info(const DynamicArray * da) {

    char * s = DynamicArray_to_string(da);
    printf ( "  %s\n", s);
    printf ( "  capacity: %d\n  origin: %d\n  end: %d\n  size: %d\n\n",
      da->capacity, 
      da->origin, 
      da->end,
      DynamicArray_size(da));

    free(s);

}

void DynamicArray_set(DynamicArray * da, int index, double value) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    while ( out_of_buffer(da, index_to_offset(da, index) ) ) {
        extend_buffer(da);
    }
    da->buffer[index_to_offset(da, index)] = value;
    if ( index >= DynamicArray_size(da) ) {
        da->end = index_to_offset(da,index+1);
    }

}

double DynamicArray_get(const DynamicArray * da, int index) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    if ( index >= DynamicArray_size(da) ) {
        return 0;
    } else {
        return da->buffer[index_to_offset(da,index)];
    }
}

void DynamicArray_push(DynamicArray * da, double value ) {
    DynamicArray_set(da, DynamicArray_size(da), value );
}

void DynamicArray_push_front(DynamicArray * da, double value) {
    assert(da->buffer != NULL);
    while ( da->origin == 0 ) {
        extend_buffer(da);
    }
    da->origin--;
    DynamicArray_set(da,0,value);
}

double DynamicArray_pop(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, DynamicArray_size(da)-1);
    DynamicArray_set(da, DynamicArray_size(da)-1, 0.0);
    da->end--;
    return value;
}

double DynamicArray_pop_front(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, 0);
    da->origin++;
    return value;    
}

DynamicArray * DynamicArray_map(const DynamicArray * da, double (*f) (double)) {
    assert(da->buffer != NULL);
    DynamicArray * result = DynamicArray_new();
    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        DynamicArray_set(result, i, f(DynamicArray_get(da, i)));
    }
    return result;
}

DynamicArray * DynamicArray_subarray(DynamicArray * da, int a, int b) {

  assert(da->buffer != NULL);
  assert(b >= a);

  DynamicArray * result = DynamicArray_new();

  for (int i=a; i<b; i++) {
      DynamicArray_push(result,DynamicArray_get(da, i));
  }

  return result;

}

// hw3 start
// Function to check if DynamicArray is empty
int DynamicArray_is_empty(const DynamicArray *da) {
    assert(da != NULL);
    return da->end == da->origin;
}

// Function to get the minimum value in DynamicArray
double DynamicArray_min(const DynamicArray *da) {
    assert(!DynamicArray_is_empty(da));

    double min_value = da->buffer[da->origin];
    for (int i = da->origin + 1; i < da->end; i++) {
        if (da->buffer[i] < min_value) {
            min_value = da->buffer[i];
        }
    }
    return min_value;
}

// Function to get the maximum value in DynamicArray
double DynamicArray_max(const DynamicArray *da) {
    assert(!DynamicArray_is_empty(da));

    double max_value = da->buffer[da->origin];
    for (int i = da->origin + 1; i < da->end; i++) {
        if (da->buffer[i] > max_value) {
            max_value = da->buffer[i];
        }
    }
    return max_value;
}

// Function to calculate the mean (average) of DynamicArray
double DynamicArray_mean(const DynamicArray *da) {
    assert(!DynamicArray_is_empty(da));

    double sum = 0;
    for (int i = da->origin; i < da->end; i++) {
        sum += da->buffer[i];
    }
    return sum / (da->end - da->origin);
}

// Function to compare values for sorting
int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

// Function to get the median value in DynamicArray
double DynamicArray_median(const DynamicArray *da) {
    assert(!DynamicArray_is_empty(da));

    int size = da->end - da->origin;
    double *copy = (double *)malloc(size * sizeof(double));
    assert(copy != NULL);

    // Copy the elements to an array
    for (int i = da->origin, j = 0; i < da->end; i++, j++) {
        copy[j] = da->buffer[i];
    }

    qsort(copy, size, sizeof(double), compare);

    // Calculate the median
    if (size % 2 == 0) {
        // If even number of elements, average the middle two
        int mid = size / 2;
        double median = (copy[mid - 1] + copy[mid]) / 2.0;
        free(copy);
        return median;
    } else {
        // If odd number of elements, return the middle one
        double median = copy[size / 2];
        free(copy);
        return median;
    }
}

// Function to calculate the sum of values in DynamicArray
double DynamicArray_sum(const DynamicArray *da) {
    assert(da != NULL);

    double sum = 0;
    for (int i = da->origin; i < da->end; i++) {
        sum += da->buffer[i];
    }
    return sum;
}

// Function to get the last value in DynamicArray
double DynamicArray_last(const DynamicArray * da) {
    assert(!DynamicArray_is_empty(da));

    return da->buffer[da->end - 1];
}

// Function to get the first value in DynamicArray
double DynamicArray_first(const DynamicArray *da) {
    assert(!DynamicArray_is_empty(da));

    return da->buffer[da->origin];
}

// Function to create a copy of a DynamicArray
DynamicArray *DynamicArray_copy(const DynamicArray *da) {
    DynamicArray *copy = DynamicArray_new();

    // Copy capacity and adjust origin and end
    copy->capacity = da->capacity;
    copy->origin = da->origin;
    copy->end = da->end;

    // Allocate memory for the buffer and copy data
    copy->buffer = (double *)malloc(sizeof(double) * da->capacity);
    assert(copy->buffer != NULL);

    for (int i = da->origin; i < da->end; i++) {
        copy->buffer[i] = da->buffer[i];
    }

    return copy;
}

// Function to create a new DynamicArray with a range of values
DynamicArray *DynamicArray_range(double start, double end, double step) {
    // Calculate the number of elements needed based on the range and step
    int num_elements = (int)((end - start) / step) + 1;

    // Create a new DynamicArray
    DynamicArray *da = DynamicArray_new();

    // Resize the buffer to accommodate the required number of elements
    if (num_elements <= 0) {
        num_elements = 1;  // Ensure capacity is at least 1
    }

    // Reallocate the buffer with the new capacity
    double *new_buffer = (double *)realloc(da->buffer, num_elements * sizeof(double));

    if (new_buffer != NULL) {
        da->buffer = new_buffer;
        da->capacity = num_elements;
    } else {
        // Handle memory allocation error here
    }

    // Populate the DynamicArray with values in the specified range
    double value = start;
    for (int i = 0; i < num_elements; i++) {
        DynamicArray_set(da, i, value);
        value += step;
    }

    return da;
}

// Function to concatenate two DynamicArrays
DynamicArray *DynamicArray_concat(const DynamicArray *arr1, const DynamicArray *arr2) {
    // Create a new DynamicArray for the result
    DynamicArray *result = DynamicArray_new();

    // Calculate the total number of elements in the concatenated array
    int total_elements = DynamicArray_size(arr1) + DynamicArray_size(arr2);

    // Resize the buffer to accommodate the required number of elements
    if (total_elements <= 0) {
        total_elements = 1;  // Ensure capacity is at least 1
    }

    // Reallocate the buffer with the new capacity
    double *new_buffer = (double *)realloc(result->buffer, total_elements * sizeof(double));

    if (new_buffer != NULL) {
        result->buffer = new_buffer;
        result->capacity = total_elements;
    } else {
        // Handle memory allocation error here
    }

    // Copy elements from arr1 to the result array
    for (int i = 0; i < DynamicArray_size(arr1); i++) {
        double value = DynamicArray_get(arr1, i);
        DynamicArray_set(result, i, value);
    }

    // Copy elements from arr2 to the result array
    for (int i = 0; i < DynamicArray_size(arr2); i++) {
        double value = DynamicArray_get(arr2, i);
        DynamicArray_set(result, i + DynamicArray_size(arr1), value);
    }

    return result;
}

// Function to take a sub-array of n elements from a DynamicArray
DynamicArray *DynamicArray_take(const DynamicArray *arr, int n) {
    // Check if the array is empty
    if (DynamicArray_is_empty(arr)) {
        return NULL;
    }

    // Calculate the starting index based on the value of n
    int start_index;
    if (n >= 0) {
        start_index = 0;
    } else {
        start_index = DynamicArray_size(arr) + n;
        if (start_index < 0) {
            start_index = 0;
        }
    }

    // Calculate the number of elements to take
    int num_elements = abs(n);

    // Create a new DynamicArray for the result
    DynamicArray *result = DynamicArray_new();

    // Resize the buffer to accommodate the required number of elements
    if (num_elements <= 0) {
        num_elements = 1;  // Ensure capacity is at least 1
    }

    // Reallocate the buffer with the new capacity
    double *new_buffer = (double *)realloc(result->buffer, num_elements * sizeof(double));

    if (new_buffer != NULL) {
        result->buffer = new_buffer;
        result->capacity = num_elements;
    } else {
        // Handle memory allocation error here
    }

    // Copy elements from the original array to the result
    for (int i = 0; i < num_elements; i++) {
        if (start_index + i < DynamicArray_size(arr)) {
            double value = DynamicArray_get(arr, start_index + i);
            DynamicArray_set(result, i, value);
        } else {
            // If there are not enough elements, set the rest to zero
            DynamicArray_set(result, i, 0.0);
        }
    }

    return result;
}
