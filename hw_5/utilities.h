#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <map>
#include <string>

// 声明一个函数，它接收一个 double 类型的 vector 引用，并根据各元素的绝对值大小进行排序
void sort_by_magnitude(std::vector<double>& vec);

// 声明一个函数，它读取一个 CSV 文件路径，并返回一个包含 CSV 数据的二维 vector
std::vector<std::vector<double>> read_matrix_csv(const std::string& path);

// 声明一个函数，它接收一个二维 vector 和一个文件路径，将二维 vector 数据写入该 CSV 文件
void write_matrix_csv(const std::vector<std::vector<double>>& matrix, const std::string& path);

// 声明一个函数，它读取一个文本文件并返回一个 map，其中 key 是文件中出现的每个单词，value 是该单词出现的次数
std::map<std::string, int> occurrence_map(const std::string& path);

#endif // UTILITIES_H
