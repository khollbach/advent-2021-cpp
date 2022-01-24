#include <iostream>
#include <fstream>
#include <vector>

namespace day1 {

std::vector<int> read_input(std::string file_name) {
    std::ifstream input(file_name);

    std::vector<int> nums;
    for (int n; input >> n;) {
        nums.push_back(n);
    }
    return nums;
}

int num_increases(const std::vector<int> &nums) {
    auto num_increases = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            num_increases++;
        }
    }

    return num_increases;
}

std::vector<int> triple_sums(const std::vector<int> &nums) {
    std::vector<int> sums;

    for (int i = 0; i < nums.size() - 2; i++) {
        auto sum = nums[i] + nums[i + 1] + nums[i + 2];
        sums.push_back(sum);
    }

    return sums;
}

void main() {
    auto nums = read_input("inputs/1");

    auto ans1 = num_increases(nums);
    std::cout << ans1 << std::endl;

    auto ans2 = num_increases(triple_sums(nums));
    std::cout << ans2 << std::endl;
}

}
