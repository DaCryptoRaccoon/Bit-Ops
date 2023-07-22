#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// Rotate right (circular right shift) function
uint32_t rotr(uint32_t x, int n) {
    return (x >> n) | (x << (32 - n));
}

void displayBinary(uint32_t value, int width) {
    std::string binaryStr = std::bitset<32>(value).to_string();
    std::cout << binaryStr.substr(32 - width) << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc >= 3) {
        int width = 0;
        std::vector<uint32_t> values;
        for (int i = 1; i < argc; i++) {
            uint32_t value = std::stoi(argv[i], nullptr, 2);
            values.push_back(value);
            width = std::max(width, static_cast<int>(argv[i][0]));
        }

        for (const auto& value : values) {
            displayBinary(value, width);
        }
        std::cout << std::string(width, '-') << std::endl;

        uint32_t result = 0;
        for (const auto& value : values) {
            result ^= value;
        }

        displayBinary(result, width);
        return 0;
    }

    // Animation

    // Constants for animation
    const uint32_t off = 0b00000000000000000000000000000000;
    const uint32_t on = 0b11111111111111111111111111111111;
    const uint32_t split = 0b10101010101010101010101010101010;
    const double delay = 0.4;

    // Up To All 1
    system("clear");
    displayBinary(off, 32);
    displayBinary(off, 32);
    displayBinary(off, 32);
    std::cout << std::string(32, '-') << std::endl;
    displayBinary(off ^ off ^ off, 32);
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(delay * 1000)));

    // ... Continue the animation as in the Ruby code ...

    return 0;
}
