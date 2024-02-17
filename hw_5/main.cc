#include "utilities.h"
#include <iostream>
#include <vector>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
    // 演示 sort_by_magnitude 函数
    std::vector<double> vec = {-3, 10, -1.5, 4, -7.2, 3.5};
    sort_by_magnitude(vec);

    std::cout << "Sorted by magnitude: ";
    for (double v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
