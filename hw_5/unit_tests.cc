#include <gtest/gtest.h>
#include "utilities.h"
#include <algorithm>  // for std::is_sorted
#include <cmath>      // for std::abs

// 测试 sort_by_magnitude 函数
TEST(SortByMagnitude, HandlesPositiveAndNegativeValues) {
    std::vector<double> vec = {-3, 10, -1.5, 4, -7.2, 3.5};
    sort_by_magnitude(vec);

    // 使用 lambda 表达式检查向量是否按绝对值升序排列
    bool is_sorted_by_magnitude = std::is_sorted(vec.begin(), vec.end(), [](double a, double b) {
        return std::abs(a) < std::abs(b);
    });
    EXPECT_TRUE(is_sorted_by_magnitude);
}

// 测试 sort_by_magnitude 函数是否正确处理空向量
TEST(SortByMagnitude, HandlesEmptyVector) {
    std::vector<double> vec = {};
    sort_by_magnitude(vec);
    EXPECT_TRUE(vec.empty());  // 确保向量仍然为空
}

// 测试 sort_by_magnitude 函数是否在只有一个元素的向量上正确无误
TEST(SortByMagnitude, HandlesSingleElementVector) {
    std::vector<double> vec = {42.0};
    sort_by_magnitude(vec);
    EXPECT_EQ(vec.size(), 1u);  // 检查向量大小仍然为 1
    EXPECT_EQ(vec[0], 42.0);    // 检查向量的唯一元素未改变
}

// 主函数
//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
