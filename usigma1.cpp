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

// Function to convert a 32-bit binary number to a binary string representation
std::string bits(uint32_t x) {
    return std::bitset<32>(x).to_string();
}

// Function to print animation for computing Σ1(x)
void animateSigma1(uint32_t x) {
    system("clear");
    std::cout << "x:       " << bits(x) << std::endl;
    std::cout << "         " << std::string(32, '-') << std::endl;

    uint32_t rot6, rot11, rot25;
    for (int i = 0; i < 3; ++i) {
        rot6 = rotr(6, x);
        rot11 = rotr(11, x);
        rot25 = rotr(25, x);

        system("clear");
        std::cout << "x:       " << bits(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "ROTR 6:  " << bits(rot6) << std::endl;
        std::cout << "ROTR 11: " << bits(rot11) << std::endl;
        std::cout << "ROTR 25: " << bits(rot25) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        x = rot6 ^ rot11 ^ rot25;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main(int argc, char* argv[]) {
    uint32_t x = 0b00000000000000000011111111111111; // 0b01010001000011100101001001111111

    if (argc > 1) {
        x = std::stoi(argv[1], nullptr, 2);
    }

    if (argc > 1 && std::string(argv[1]).size() > 32) {
        std::cout << "We only operate on 32-bit words in SHA-256. Your x is " << std::string(argv[1]).size() << " bits.\n";
        return 1;
    }

    animateSigma1(x);

    return 0;
}
