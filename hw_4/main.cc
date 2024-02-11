#include <stdio.h>
#include "gtest/gtest.h"
#include "complex.h"

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
Complex a(0.0, 0.0);
Complex b(1.0, 2.0);
Complex c(3.0, 4.0);
