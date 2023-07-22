#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <thread>
#include <chrono>

// Function to perform right rotation on a 32-bit binary number x
uint32_t rotr(int n, uint32_t x) {
    const uint32_t mask = (1 << 32) - 1;
    uint32_t right = (x >> n) & mask;
    uint32_t left = (x << (32 - n)) & mask;
    uint32_t result = right | left;
    return result;
}

// Function to add four 32-bit binary numbers
uint32_t add(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    return a + b + c + d;
}

// Function to perform the σ0 operation on a 32-bit binary number x
uint32_t sigma0(uint32_t x) {
    return rotr(7, x) ^ rotr(18, x) ^ (x >> 3);
}

// Function to perform the σ1 operation on a 32-bit binary number x
uint32_t sigma1(uint32_t x) {
    return rotr(17, x) ^ rotr(19, x) ^ (x >> 10);
}

// Function to split the input string into blocks of the specified size
std::vector<std::string> split(const std::string& str, int blockSize) {
    std::vector<std::string> blocks;
    for (size_t i = 0; i < str.size(); i += blockSize) {
        blocks.push_back(str.substr(i, blockSize));
    }
    return blocks;
}

// Function to convert a 32-bit binary number to a binary string representation
std::string bits(uint32_t x) {
    return std::bitset<32>(x).to_string();
}

// Function to calculate the message schedule from a 512-bit binary message block
void calculateMessageSchedule(const std::string& block) {
    int size = block.size();

    // The message block provides the first 16 words for the message schedule (512 bits / 32 bits = 16 words)
    std::vector<uint32_t> schedule;
    for (int i = 0; i < 16; ++i) {
        schedule.push_back(std::stoi(block.substr(i * 32, 32), nullptr, 2));
    }

    std::vector<std::vector<uint32_t>> memory(16, std::vector<uint32_t>(4)); // leave first 16 blank because they were not calculated from previous values

    // Calculate remaining 48 words
    for (int i = 16; i < 64; ++i) {
        uint32_t newWord = add(sigma1(schedule[i - 2]), schedule[i - 7], sigma0(schedule[i - 15]), schedule[i - 16]);
        schedule.push_back(newWord);
        memory.push_back({ sigma1(schedule[i - 2]), schedule[i - 7], sigma0(schedule[i - 15]), schedule[i - 16] });
    }

    // Animation
    system("clear");
    std::cout << "block:     " << block << std::endl;
    std::cout << std::string(12, ' ') << std::string(32, '-') << std::endl;
    std::cout << std::string(12, ' ') << block.substr(0, 32).ljust(size, ' ') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    for (int i = 0; i < 64; ++i) {
        system("clear");
        std::cout << "block:     " << block << std::endl;
        std::cout << std::string(12, ' ') << std::string(32, '-') << std::endl;
        std::cout << std::string(12, ' ') << block.substr(0, 32).ljust(size, ' ') << std::endl;
        std::cout << std::endl;
        std::cout << "message schedule:" << std::endl;

        for (int j = 0; j <= i; ++j) {
            if (j <= 15) {
                std::cout << "W" << std::to_string(j).ljust(2, ' ') << " " << bits(schedule[j]) << std::endl;
            }
            else {
                std::cout << "W" << std::to_string(j).ljust(2, ' ') << " " << bits(schedule[j]);
                if (j == i - 16) {
                    std::cout << " ->    " << bits(memory[i][3]);
                }
                else if (j == i - 15) {
                    std::cout << " -> σ0 " << bits(memory[i][2]);
                }
                else if (j == i - 7) {
                    std::cout << " ->    " << bits(memory[i][1]);
                }
                else if (j == i - 2) {
                    std::cout << " -> σ1 " << bits(memory[i][0]);
                }
                else if (j == i) {
                    std::cout << " = σ1(t-2) + (t-7) + σ0(t-15) + (t-16)";
                }
                std::cout << std::endl;
            }
        }

        if (i < 15) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        else {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }
}

int main(int argc, char* argv[]) {
    std::string input = "abc";
    if (argc > 1) {
        input = argv[1];
    }

    std::string padded = padding(input);
    std::vector<std::string> blocks = split(padded, 512);
    int blockNumber = 0;
    std::string block = blocks[blockNumber];

    if (argc > 1) {
        block = argv[1];
        blockNumber = 0;
    }

    calculateMessageSchedule(block);

    return 0;
}
