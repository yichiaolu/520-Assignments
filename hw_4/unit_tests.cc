#include <math.h>
#include <float.h> /* defines DBL_EPSILON */
#include <assert.h>
#include "typed_array.h"
#include "point.h"
#include "gtest/gtest.h"
#include "complex.h"


namespace {

    TEST(TypedArray, Construction) {
        TypedArray<Point> b;
        b.set(0, Point(1,2,3));
        b.set(1, Point(2,3,4));
        b.set(20, Point(3,4,5));
        EXPECT_EQ(b.get(0).x, 1);
        EXPECT_EQ(b.get(1).y, 3);
        EXPECT_EQ(b.get(20).z, 5);
    }

    TEST(TypedArray, Defaults) {
        TypedArray<Point> x;
        Point& y = x.get(3);
        std::cout << x << "\n";
        EXPECT_DOUBLE_EQ(y.magnitude(), 0.0);
    }

    TEST(TypedArray, Matrix) {

        TypedArray<TypedArray<double>> m;

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                m.get(i).set(j,3*i+j);
            }
        }

        std::cout << m << "\n"; 

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                EXPECT_DOUBLE_EQ(m.get(i).get(j),3*i+j);
            }
        }

    }

    TEST(TypedArray,CopyElementsInSet1) {
        TypedArray<Point> b;
        Point p(1,2,3);
        b.set(0, p);
        p.x = 4;
        EXPECT_DOUBLE_EQ(b.get(0).x, 1);
    }

    TEST(TypedArray,CopyElementsInSet2) {
        TypedArray<TypedArray<double>> m;
        TypedArray<double> x;
        x.set(0,0);
        m.set(0,x);
        x.set(0,-1);
        EXPECT_DOUBLE_EQ(m.get(0).get(0),0.0); // If set didn't make a copy
                                               // then we would expect m[0][0]
                                               // to be x[0], which we changed 
                                               // to -1.
    }    

    TEST(Examples,Complex) {
            Complex x(1,2), y(3);
        }

        template<typename T>
        int compare(const T& x, const T& y) {
            if ( x < y ) {
                return -1;
            } else if ( y < x ) {
                return 1;
            } else {
                return 0;
            }
        }

        TEST(Examples,Templates) {
            EXPECT_EQ(compare(1.0, 2.0), -1);
            EXPECT_EQ(compare(Complex(5,4), Complex(-3,4)), 1);
    }
//push pop
    TEST(TypedArray, PushPop) {
        TypedArray<int> arr;
        arr.push(1);
        arr.push(2);
        EXPECT_EQ(arr.get(0), 1);
        EXPECT_EQ(arr.get(1), 2);

        int popValue = arr.pop();
        EXPECT_EQ(popValue, 2);
        EXPECT_EQ(arr.size(), 1);

        popValue = arr.pop();
        EXPECT_EQ(popValue, 1);
        EXPECT_EQ(arr.size(), 0);

        EXPECT_THROW(arr.pop(), std::range_error);
    }
//push_front  pop_front
    TEST(TypedArray, PushFrontPopFront) {
        TypedArray<int> arr;
        arr.push_front(2);
        arr.push_front(1);
        EXPECT_EQ(arr.get(0), 1);
        EXPECT_EQ(arr.get(1), 2);

        int popValue = arr.pop_front();
        EXPECT_EQ(popValue, 1);
        EXPECT_EQ(arr.size(), 1);

        popValue = arr.pop_front();
        EXPECT_EQ(popValue, 2);
        EXPECT_EQ(arr.size(), 0);

        EXPECT_THROW(arr.pop_front(), std::range_error);
    }
    TEST(Complex, Properties) {
        Complex c(3.5, 2.5);
        EXPECT_DOUBLE_EQ(c.real(), 3.5);
        EXPECT_DOUBLE_EQ(c.imaginary(), 2.5);
    }
    TEST(Complex, Conjugate) {
        Complex c(3.5, 2.5);
        Complex conj = c.conjugate();
        EXPECT_DOUBLE_EQ(conj.real(), 3.5);
        EXPECT_DOUBLE_EQ(conj.imaginary(), -2.5);
    }
    TEST(Complex, Addition) {
        Complex c1(1, 2);
        Complex c2(3, 4);
        Complex result = c1 + c2;
        EXPECT_DOUBLE_EQ(result.real(), 4);
        EXPECT_DOUBLE_EQ(result.imaginary(), 6);
    }

    TEST(Complex, Multiplication) {
        Complex c1(1, 2);
        Complex c2(3, 4);
        Complex result = c1 * c2;
        EXPECT_DOUBLE_EQ(result.real(), -5);
        EXPECT_DOUBLE_EQ(result.imaginary(), 10);
    }
    TEST(Complex, Equality) {
        Complex c1(3.5, 2.5);
        Complex c2(3.5, 2.5);
        Complex c3(3.5, 3.5);
        EXPECT_TRUE(c1 == c2);
        EXPECT_FALSE(c1 == c3);
    }
    TEST(Complex, LessThan) {
        Complex c1(1, 2);
        Complex c2(3, 4);
        EXPECT_TRUE(c1 < c2);
        EXPECT_FALSE(c2 < c1);
    }


}
