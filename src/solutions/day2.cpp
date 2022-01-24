#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <charconv>

namespace day2 {

enum class Direction {
    Forward,
    Down,
    Up,
};

Direction read_dir(std::string_view s) {
    if (s == "forward") return Direction::Forward;
    if (s == "down") return Direction::Down;
    if (s == "up") return Direction::Up;
    assert(false);
}

int read_int(std::string_view s) {
    int n;

    auto start = s.data();
    auto end = start + s.size();
    auto [ptr, ec] { std::from_chars(start, end, n) };
    assert(ptr == end);
    assert(ec == std::errc());

    return n;
}

using Command = std::pair<Direction, int>;

Command read_line(std::string_view line) {
    auto space = line.find(' ');
    assert(space != std::string::npos);
    auto first = line.substr(0, space);
    auto second = line.substr(space + 1);

    auto dir = read_dir(first);
    auto n = read_int(second);

    return std::pair(dir, n);
}

std::vector<Command> read_input(std::string file_name) {
    std::vector<Command> commands;

    std::ifstream input(file_name);
    for (std::string line; std::getline(input, line);) {
        commands.push_back(read_line(line));
    }

    return commands;
}

std::pair<int, int> final_hpos_depth_1(const std::vector<Command>& commands) {
    auto hpos = 0;
    auto depth = 0;

    for (auto [dir, n] : commands) {
        switch (dir) {
            case Direction::Forward:
                hpos += n;
                break;
            case Direction::Down:
                depth += n;
                break;
            case Direction::Up:
                depth -= n;
                break;
            default:
                assert(false);
        }
    }

    return std::pair(hpos, depth);
}

std::pair<int, int> final_hpos_depth_2(const std::vector<Command>& commands) {
    auto hpos = 0;
    auto depth = 0;
    auto aim = 0;

    for (auto [dir, n] : commands) {
        switch (dir) {
            case Direction::Down:
                aim += n;
                break;
            case Direction::Up:
                aim -= n;
                break;
            case Direction::Forward:
                hpos += n;
                depth += aim * n;
                break;
            default:
                assert(false);
        }
    }

    return std::pair(hpos, depth);
}

void main() {
    auto commands = read_input("inputs/2");

    auto [hpos1, depth1] = final_hpos_depth_1(commands);
    std::cout << hpos1 * depth1 << std::endl;

    auto [hpos2, depth2] = final_hpos_depth_2(commands);
    std::cout << hpos2 * depth2 << std::endl;
}

}
