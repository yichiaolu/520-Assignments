#include "utilities.h"
#include <algorithm> // for std::sort
#include <cmath>     // for std::abs
#include <fstream>   // for file I/O
#include <sstream>   // for std::stringstream
#include <cctype>    // for std::tolower

void sort_by_magnitude(std::vector<double>& vec) {
    std::sort(vec.begin(), vec.end(), [](double x, double y) {
        return std::abs(x) < std::abs(y);
    });
}

std::vector<std::vector<double>> read_matrix_csv(const std::string& path) {
    std::vector<std::vector<double>> matrix;
    std::ifstream file(path);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) { // Assuming comma is the delimiter
            row.push_back(std::stod(value)); // Convert string to double and add to row
        }

        matrix.push_back(row);
    }

    return matrix;
}

void write_matrix_csv(const std::vector<std::vector<double>>& matrix, const std::string& path) {
    std::ofstream file(path);

    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << ","; // Add comma after all elements but the last
        }
        file << "\n"; // New line at the end of each row
    }
}

std::map<std::string, int> occurrence_map(const std::string& path) {
    std::map<std::string, int> wordCount;
    std::ifstream file(path);
    std::string word;

    while (file >> word) {
        // Process the word to remove punctuation, convert to lowercase, etc.
        // This is a simplified example; you'll need to expand it to handle all the requirements.
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    return wordCount;
}
