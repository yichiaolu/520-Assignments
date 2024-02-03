#include <math.h>
#include "dynamic_array.h"
#include "gtest/gtest.h"

namespace {


//////////////////////////////////////////////////

    // min(), comprehensive
    TEST(DynamicArray,  min_comprehensive) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, -2.4);
        ASSERT_NEAR(-5.56, DynamicArray_min(da), 0.01);
        DynamicArray_destroy(da);
    }

    // min(), array of all positive integers
    TEST(DynamicArray, min_int_pos) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, 2);
        DynamicArray_push( da, 5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 3);
        ASSERT_EQ(2, DynamicArray_min(da));
        DynamicArray_destroy(da);
    }

    // min(), array with some negative integers
    TEST(DynamicArray, min_int_neg) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, -2);
        DynamicArray_push( da, -5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 3);
        ASSERT_EQ(-5, DynamicArray_min(da));
        DynamicArray_destroy(da);
    }

    // min(), array with doubles
    TEST(DynamicArray,  min_double) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(-5.56, DynamicArray_min(da), 0.01);
        DynamicArray_destroy(da);
    }

    // min(), empty array
    TEST(DynamicArray, min_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_min(da), ".*Assertion.*");
        DynamicArray_destroy(da);
    }    

//////////////////////////////////////////////////

// max(), comprehensive
    TEST(DynamicArray,  max_comprehensive) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, -2.4);
        ASSERT_NEAR(24.7, DynamicArray_max(da), 0.001);
        DynamicArray_destroy(da);
    }

    // max(), array of all positive integers
    TEST(DynamicArray, max_int_pos) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, 2);
        DynamicArray_push( da, 5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 3);
        ASSERT_EQ(24, DynamicArray_max(da));
        DynamicArray_destroy(da);
    }

    // max(), array with some negative integers
    TEST(DynamicArray, max_int_neg) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, -2);
        DynamicArray_push( da, -5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 3);
        ASSERT_EQ(24, DynamicArray_max(da));
        DynamicArray_destroy(da);
    }

    // max(), array with doubles
    TEST(DynamicArray,  max_double) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(24.7, DynamicArray_max(da), 0.01);
        DynamicArray_destroy(da);
    }

    // max(), empty array
    TEST(DynamicArray, max_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_max(da), ".*Assertion.*");
        DynamicArray_destroy(da);
    }    
//////////////////////////////////////////////////

// mean(), comprehensive
    TEST(DynamicArray,  mean_comprehensive) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, -24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, -2.4);
        ASSERT_NEAR(-4.67, DynamicArray_mean(da), 0.01);
        DynamicArray_destroy(da);
    }

    // mean(), array of all positive integers
    TEST(DynamicArray, mean_int_pos) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, 2);
        DynamicArray_push( da, 5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 13);
        ASSERT_NEAR(10, DynamicArray_mean(da), 0.01);
        DynamicArray_destroy(da);
    }

    // mean(), array with some negative integers
    TEST(DynamicArray, mean_int_neg) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, -2);
        DynamicArray_push( da, -5);
        DynamicArray_push( da, -24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, -23);
        ASSERT_NEAR(-6.33, DynamicArray_mean(da), 0.01);
        DynamicArray_destroy(da);
    }

    // mean(), array with doubles
    TEST(DynamicArray,  mean_double) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(4.53, DynamicArray_mean(da), 0.01);
        DynamicArray_destroy(da);
    }

    // mean(), empty array
    TEST(DynamicArray, mean_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_mean(da), ".*Assertion.*");
        DynamicArray_destroy(da);
    }    
//////////////////////////////////////////////////

// median(), comprehensive, even num of elements
    TEST(DynamicArray,  median_comprehensive_even) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, -24.7);
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, 1.04);
        ASSERT_NEAR(-0.68, DynamicArray_median(da), 0.01);
        DynamicArray_destroy(da);
    }

// median(), comprehensive, odd num of elements
    TEST(DynamicArray,  median_comprehensive_odd) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, -24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, 2.4);
        ASSERT_NEAR(1.04, DynamicArray_median(da), 0.01);
        DynamicArray_destroy(da);
    }

    // median(), array of all positive integers, even num of elements
    TEST(DynamicArray, median_int_pos_even) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, 2);
        DynamicArray_push( da, 5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 13);
        ASSERT_EQ(8, DynamicArray_median(da));
        DynamicArray_destroy(da);
    }

    // median(), array of all positive integers, odd num of elements
    TEST(DynamicArray, median_int_pos_odd) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, 2);
        DynamicArray_push( da, 5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 7);
        DynamicArray_push( da, 13);
        ASSERT_EQ(7, DynamicArray_median(da));
        DynamicArray_destroy(da);
    }

    // median(), array with some negative integers, even num of elements
    TEST(DynamicArray, median_int_neg_even) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, -2);
        DynamicArray_push( da, -5);
        DynamicArray_push( da, -24);
        DynamicArray_push( da, -1);
        DynamicArray_push( da, 1);
        ASSERT_NEAR(-1.5, DynamicArray_median(da), 0.01);
        DynamicArray_destroy(da);
    }

    // median(), array with some repeated integers
    TEST(DynamicArray, median_int_repeated) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 13);
        DynamicArray_push( da, -2);
        DynamicArray_push( da, -5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 24);
        ASSERT_NEAR(9.5, DynamicArray_median(da), 0.01);
        DynamicArray_destroy(da);
    }

    // median(), array with doubles
    TEST(DynamicArray,  median_double) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(2.22, DynamicArray_median(da), 0.01);
        DynamicArray_destroy(da);
    }

    // median(), empty array
    TEST(DynamicArray, median_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_median(da), ".*Assertion.*");
        DynamicArray_destroy(da);
    }    

//////////////////////////////////////////////////

    // sum(), comprehensive
    TEST(DynamicArray,  sum_comprehensive_even) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, -24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, 2.4);
        ASSERT_NEAR(-22.18, DynamicArray_sum(da), 0.01);
        DynamicArray_destroy(da);
    }

    // sum(), array of all positive integers
    TEST(DynamicArray, sum_int_pos) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, 2);
        DynamicArray_push( da, 5);
        DynamicArray_push( da, 24);
        DynamicArray_push( da, 6);
        DynamicArray_push( da, 7);
        DynamicArray_push( da, 13);
        ASSERT_EQ(67, DynamicArray_sum(da));
        DynamicArray_destroy(da);
    }

    // sum(), array with some negative integers, even num of elements
    TEST(DynamicArray, sum_int_neg) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 10);
        DynamicArray_push( da, -2);
        DynamicArray_push( da, -5);
        DynamicArray_push( da, -24);
        DynamicArray_push( da, -1);
        DynamicArray_push( da, 1);
        ASSERT_EQ(-21, DynamicArray_sum(da));
        DynamicArray_destroy(da);
    }

    // sum(), array with doubles
    TEST(DynamicArray,  sum_double) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(27.18, DynamicArray_sum(da), 0.01);
        DynamicArray_destroy(da);
    }

/*    // sum(), empty array
    TEST(DynamicArray,  sum_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_NEAR(0, DynamicArray_sum(da), 0.01);
        DynamicArray_destroy(da);
    }
*/
//////////////////////////////////////////////////

    // last(), comprehensive
    TEST(DynamicArray,  last_comprehensive) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(3.4, DynamicArray_last(da), 0.01);
        DynamicArray_destroy(da);
    }

    // last(), empty array
    TEST(DynamicArray, last_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_last(da), ".*Assertion.*");
        DynamicArray_destroy(da);
    }

//////////////////////////////////////////////////

    // first(), comprehensive
    TEST(DynamicArray,  first_comprehensive) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        ASSERT_NEAR(1.04, DynamicArray_first(da), 0.01);
        DynamicArray_destroy(da);
    }

    // first(), empty array
    TEST(DynamicArray, first_empty) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_first(da), ".*Assertion.*");
        DynamicArray_destroy(da);
    }

//////////////////////////////////////////////////

    // copy(), comprehensive
    TEST(DynamicArray,  copy_comprehensive) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push( da, 1.04);
        DynamicArray_push( da, -2.4);
        DynamicArray_push( da, -5.56);
        DynamicArray_push( da, 24.7);
        DynamicArray_push( da, 6.0);
        DynamicArray_push( da, 3.4);
        DynamicArray * da_copy = DynamicArray_copy(da);
        for(int i=0; i < DynamicArray_size(da); i++){
            ASSERT_NEAR(DynamicArray_get(da_copy, i), DynamicArray_get(da, i), 0.01);
        }
        DynamicArray_destroy(da);
        DynamicArray_destroy(da_copy);
    }

//////////////////////////////////////////////////

    // range(), integers
    TEST(DynamicArray, range_int) {
        DynamicArray * da = DynamicArray_range(1, 5, 1);
        char * s = DynamicArray_to_string(da);
        printf ( "  %s\n", s);
        int element = 1;
        for(int i=0; i < DynamicArray_size(da); i++){
            ASSERT_EQ(element, DynamicArray_get(da, i));
            element += 1;
        }
        DynamicArray_destroy(da);
    }

    // range(), double
    TEST(DynamicArray, range_double) {
        DynamicArray * da = DynamicArray_range(0, 3, 0.1);
        char * s = DynamicArray_to_string(da);
        printf ( "  %s\n", s);
        double element = 0;
        for(int i=0; i < DynamicArray_size(da); i++){
            ASSERT_NEAR(element, DynamicArray_get(da, i), 0.01);
            element += 0.1;
        }
        DynamicArray_destroy(da);
    }

//////////////////////////////////////////////////

    // concat(), comprehensive
    TEST(DynamicArray, concat_comprehensive) {
        DynamicArray * a = DynamicArray_range(1, 3, 0.1);
        DynamicArray * b = DynamicArray_range(3.1, 5, 0.1);
        DynamicArray * c = DynamicArray_concat(a, b);
        char * s = DynamicArray_to_string(c);
        printf ( "  %s\n", s);
        double element = 1;
        for(int i=0; i < DynamicArray_size(a) + DynamicArray_size(b); i++){
            ASSERT_NEAR(element, DynamicArray_get(c, i), 0.01);
            element += 0.1;
        }
        DynamicArray_destroy(a);
        DynamicArray_destroy(b);
        DynamicArray_destroy(c);
    }

//////////////////////////////////////////////////

    // take(), positive
    TEST(DynamicArray, take_positive) {
        DynamicArray * a = DynamicArray_range(1, 5, 0.1);
        DynamicArray * b = DynamicArray_take(a, 3);
        char * s = DynamicArray_to_string(b);
        printf ( "  %s\n", s);
        double element = 1;
        for(int i=0; i < 3; i++){
            ASSERT_NEAR(element, DynamicArray_get(b, i), 0.01);
            element += 0.1;
        }
        DynamicArray_destroy(a);
        DynamicArray_destroy(b);
    }

    // take(), negative
    TEST(DynamicArray, take_negative) {
        DynamicArray * a = DynamicArray_range(1, 5, 0.1);
        DynamicArray * b = DynamicArray_take(a, -5);
        char * s = DynamicArray_to_string(b);
        printf ( "  %s\n", s);
        double element = 4.6;
        for(int i=0; i < 5; i++){
            ASSERT_NEAR(element, DynamicArray_get(b, i), 0.01);
            element += 0.1;
        }
        DynamicArray_destroy(a);
        DynamicArray_destroy(b);
    }

    // take(), oversize
    TEST(DynamicArray, take_oversize) {
        DynamicArray * a = DynamicArray_range(1, 3, 0.5);
        DynamicArray * b = DynamicArray_take(a, 7);
        char * s = DynamicArray_to_string(b);
        printf ( "  %s\n", s);
        double element = 1;
        for(int i=0; i < 7; i++){
            if (i < DynamicArray_size(a)){
                ASSERT_NEAR(element, DynamicArray_get(b, i), 0.01);
                element += 0.5;
            }
            else {
                ASSERT_NEAR(0, DynamicArray_get(b, i), 0.01);
            }
        }
        DynamicArray_destroy(a);
        DynamicArray_destroy(b);
    }

    /////////////////////////////////////////////////
//    TEST(DynamicArray, extra_credit_num_arrays) {        DynamicArray * a = DynamicArray_range(0, 1, 0.1);        DynamicArray * b = DynamicArray_range(1.1, 2, 0.1);        DynamicArray * c = DynamicArray_concat(a, b);        ASSERT_EQ(DynamicArray_num_arrays(), 3);        DynamicArray_destroy(a);        DynamicArray_destroy(b);        DynamicArray_destroy(c);        ASSERT_EQ(DynamicArray_num_arrays(), 0);        free(a);        free(b);        free(c);    }    TEST(DynamicArray, extra_credit_is_valid) {        DynamicArray * a = DynamicArray_range(0, 1, 0.1);        DynamicArray * b = DynamicArray_range(1.1, 2, 0.1);        DynamicArray * c = DynamicArray_concat(a, b);        ASSERT_EQ(DynamicArray_is_valid(a), 1);        DynamicArray_destroy(a);        ASSERT_EQ(DynamicArray_is_valid(a), 0);        free(a);        free(b);        free(c);    }    TEST(DynamicArray, extra_credit_destroy_all) {        DynamicArray * a = DynamicArray_range(0, 1, 0.1);        DynamicArray * b = DynamicArray_range(1.1, 2, 0.1);        DynamicArray * c = DynamicArray_concat(a, b);        DynamicArray_destroy_all();        ASSERT_EQ(a->buffer!=NULL, 0);        ASSERT_EQ(b->buffer!=NULL, 0);        ASSERT_EQ(c->buffer!=NULL, 0);        free(a);        free(b);        free(c);    }
}
