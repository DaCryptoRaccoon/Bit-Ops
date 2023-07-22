#include <iostream>
#include <bitset>
#include <thread>
#include <chrono>

// Shift Right function
uint32_t shr(uint32_t x, int n) {
    return x >> n;
}

int main(int argc, char* argv[]) {
    // Input
    // Defaults
    uint32_t x = 0b11111111000000001111111100000000;
    int n = 32;

    // Arguments passed
    if (argc >= 2) {
        x = std::stoi(argv[1], nullptr, 2); // binary
    }
    if (argc >= 3) {
        n = std::stoi(argv[2]); // integer
    }

    // Check arguments
    if (argc >= 2 && strlen(argv[1]) > 32) {
        std::cout << "We only operate on 32-bit words in SHA-256. Your x is " << strlen(argv[1]) << " bits." << std::endl;
        return 1;
    }

    // Animation
    std::string s = std::to_string(n);
    for (int i = 0; i < n; ++i) {
        system("clear");
        std::cout << "      x: " << std::bitset<32>(x) << std::endl;
        std::cout << " SHR " << s << ": " << std::bitset<32>(shr(x, i)) << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    return 0;
}
