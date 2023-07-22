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

// Function to print animation for computing Σ0(x)
void animateSigma0(uint32_t x) {
    system("clear");
    std::cout << "x:       " << bits(x) << std::endl;
    std::cout << "         " << std::string(32, '-') << std::endl;

    uint32_t rot2, rot13, rot22;
    for (int i = 0; i < 3; ++i) {
        rot2 = rotr(2, x);
        rot13 = rotr(13, x);
        rot22 = rotr(22, x);

        system("clear");
        std::cout << "x:       " << bits(x) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::cout << "ROTR 2:  " << bits(rot2) << std::endl;
        std::cout << "ROTR 13: " << bits(rot13) << std::endl;
        std::cout << "ROTR 22: " << bits(rot22) << std::endl;
        std::cout << "         " << std::string(32, '-') << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        x = rot2 ^ rot13 ^ rot22;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int main(int argc, char* argv[]) {
    uint32_t x = 0b00000000000000000011111111111111; // 0b11101001101101011101101110100101

    if (argc > 1) {
        x = std::stoi(argv[1], nullptr, 2);
    }

    if (argc > 1 && std::string(argv[1]).size() > 32) {
        std::cout << "We only operate on 32-bit words in SHA-256. Your x is " << std::string(argv[1]).size() << " bits.\n";
        return 1;
    }

    animateSigma0(x);

    return 0;
}
