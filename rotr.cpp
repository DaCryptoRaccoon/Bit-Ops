#include <iostream>
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

// Function to print animation for right rotation
void animateRotation(uint32_t x, int n) {
    std::string s(n, ' ');
    for (int i = 0; i < n; ++i) {
        system("clear");
        std::cout << "      x: " << std::bitset<32>(x) << std::endl;
        std::cout << "ROTR " << s << ": " << std::bitset<32>(rotr(i + 1, x)) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

int main(int argc, char* argv[]) {
    uint32_t x = 0b11111111000000001111111100000000;
    int n = 32;

    if (argc > 1) {
        x = std::stoi(argv[1], nullptr, 2);
    }
    if (argc > 2) {
        n = std::stoi(argv[2]);
    }

    if (argc > 1 && std::string(argv[1]).size() > 32) {
        std::cout << "We only operate on 32-bit words in SHA-256. Your x is " << std::string(argv[1]).size() << " bits.\n";
        return 1;
    }

    animateRotation(x, n);

    return 0;
}
