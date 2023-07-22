#include <iostream>
#include <bitset>
#include <thread>
#include <chrono>

// Shift Right function
uint32_t shr(uint32_t x, int n) {
    return x >> n;
}

// Rotate Right function
uint32_t rotr(uint32_t x, int n) {
    return (x >> n) | (x << (32 - n));
}

int main(int argc, char* argv[]) {
    // Input
    uint32_t x = 0b00000000000000000011111111111111; // Default value
    // Arguments passed
    if (argc >= 2) {
        x = std::stoi(argv[1], nullptr, 2); // binary
    }

    // Check arguments
    if (argc >= 2 && strlen(argv[1]) > 32) {
        std::cout << "We only operate on 32-bit words in SHA-256. Your x is " << strlen(argv[1]) << " bits." << std::endl;
        return 1;
    }

    // Animation
    std::cout << "x:       " << std::bitset<32>(x) << std::endl;
    std::cout << "         " << std::string(32, '-') << std::endl;
    std::cout << "ROTR 17: " << std::bitset<32>(x) << std::endl;
    std::cout << "ROTR 19: " << std::bitset<32>(x) << std::endl;
    std::cout << " SHR 10: " << std::bitset<32>(x) << std::endl;
    std::cout << "         " << std::string(32, '-') << std::endl;
    std::cout << "σ1(x):" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // ROTR(17, x)
    for (int i = 0; i <= 17; ++i) {
        system("clear");
        std::cout << "x:       " << std::bitset<32>(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "ROTR 17: " << std::bitset<32>(rotr(x, i)) << std::endl;
        std::cout << "ROTR 19: " << std::bitset<32>(x) << std::endl;
        std::cout << " SHR 10: " << std::bitset<32>(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "σ1(x):" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // ROTR(19, x)
    for (int i = 0; i <= 19; ++i) {
        system("clear");
        std::cout << "x:       " << std::bitset<32>(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "ROTR 17: " << std::bitset<32>(rotr(x, 17)) << std::endl;
        std::cout << "ROTR 19: " << std::bitset<32>(rotr(x, i)) << std::endl;
        std::cout << " SHR 10: " << std::bitset<32>(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "σ1(x):" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // SHR(10, x)
    for (int i = 0; i <= 10; ++i) {
        system("clear");
        std::cout << "x:       " << std::bitset<32>(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "ROTR 17: " << std::bitset<32>(rotr(x, 17)) << std::endl;
        std::cout << "ROTR 19: " << std::bitset<32>(rotr(x, 19)) << std::endl;
        std::cout << " SHR 10: " << std::bitset<32>(shr(x, i)) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "σ1(x):" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // ROTR(17, x) ^ ROTR(19, x) ^ SHR(10, x)
    for (int i = 32; i >= 1; --i) {
        system("clear");
        std::cout << "x:       " << std::bitset<32>(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "ROTR 17: " << std::bitset<32>(rotr(x, 17)) << std::endl;
        std::cout << "ROTR 19: " << std::bitset<32>(rotr(x, 19)) << " XOR" << std::endl;
        std::cout << " SHR 10: " << std::bitset<32>(shr(x, 10)) << " XOR" << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "σ1(x):   " << std::bitset<32>(rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10)).to_string().substr(i - 1, 32).rjust(32, ' ') << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}
