#include "solutions.h"
#include "stdlib.h"

static int total = 0;

int running_total(int value) {
    total += value;
    return total;
}

int* reverse(int* array, int length) {
    int* reversed = (int*)calloc(length, sizeof(int));
    int i;
    for (i = 0; i < length; i++) {
        reversed[i] = array[length - i - 1];
    }
    return reversed;
}

void reverse_in_place(int* array, int length) {
    int s = 0, e = length-1;
    while (s < e) {
        int temp = array[s];
        array[s] = array[e];
        array[e] = temp;
        s++;
        e--;
    }
}

int num_occurences(int* array, int length, int value) {
    int count = 0, i;
    for (i = 0; i < length; i++) {
        if (array[i] == value) {
            count++;
        }
    }
    return count;
}
