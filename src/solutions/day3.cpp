#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

namespace day3 {

std::vector<std::string> read_lines(std::string file_name) {
    std::vector<std::string> lines;

    std::ifstream input(file_name);
    for (std::string line; std::getline(input, line);) {
        lines.push_back(line);
    }

    return lines;
}

std::pair<int, int> gamma_epsilon(const std::vector<std::string>& lines) {
    // How many ones in each position?
    auto line_len = lines[0].size();
    std::vector<int> num_ones(line_len, 0);
    for (auto line : lines) {
        assert(line.size() == line_len);
        for (int i = 0; i < line_len; i++) {
            if (line[i] == '1') {
                num_ones[i]++;
            } else {
                assert(line[i] == '0');
            }
        }
    }

    // What's the majority in each position?
    auto num_lines = lines.size();
    std::string gamma, epsilon;
    for (int i = 0; i < line_len; i++) {
        // Strict majority? (Ties broken in favor of 0.)
        if (num_ones[i] * 2 > num_lines) {
            gamma.push_back('1');
            epsilon.push_back('0');
        } else {
            gamma.push_back('0');
            epsilon.push_back('1');
        }
    }

    return std::pair(std::stoi(gamma, nullptr, 2), std::stoi(epsilon, nullptr, 2));
}

void main() {
    auto lines = read_lines("inputs/3");

    auto [gamma, epsilon] = gamma_epsilon(lines);
    std::cout << gamma * epsilon << std::endl;
}

}
