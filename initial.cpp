#include <iostream>
#include <vector>
#include <bitset>
#include <thread>
#include <chrono>

using namespace std;

// Function to convert a number to binary representation (32-bit)
string bits(uint32_t num) {
    return bitset<32>(num).to_string();
}

int main() {
    // -------------------
    // Initial Hash Values - H0
    // -------------------
    // The first thirty-two bits of the fractional parts of the square roots of the first eight prime numbers.

    vector<uint32_t> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    vector<uint32_t> registers(8, 0);

    // Animation settings
    const string indent = "  ";

    // Frame function to display animation frames
    auto frame = [&registers, &indent]() {
        system("clear");
        for (size_t i = 0; i < registers.size(); ++i) {
            cout << indent << registers[i] << " = " << bits(registers[i]) << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    };

    // Frame
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        registers[i] = (uint32_t)(sqrt(primes[i]) * (1ULL << 32)); // Using 64-bit integer for precision
    }
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        registers[i] = (uint32_t)(sqrt(primes[i]) * (1ULL << 32));
        cout << indent << registers[i] << " = √" << primes[i] << endl;
    }
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        registers[i] = (uint32_t)(sqrt(primes[i]) * (1ULL << 32));
        cout << indent << registers[i] << " = " << sqrt(primes[i]) << endl;
    }
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        registers[i] = (uint32_t)(sqrt(primes[i]) * (1ULL << 32));
        cout << indent << registers[i] << " = " << (sqrt(primes[i]) - floor(sqrt(primes[i]))) << endl;
    }
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        registers[i] = (uint32_t)(sqrt(primes[i]) * (1ULL << 32));
        cout << indent << registers[i] << " = " << (sqrt(primes[i]) - floor(sqrt(primes[i]))) * (1ULL << 32) << endl;
    }
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0) (initial hash value)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        registers[i] = (uint32_t)(sqrt(primes[i]) * (1ULL << 32));
        cout << indent << registers[i] << " = " << (uint32_t)((sqrt(primes[i]) - floor(sqrt(primes[i]))) * (1ULL << 32)) << endl;
    }
    frame();

    // Frame
    cout << indent << "-----------" << endl;
    cout << indent << "compression: (H0)" << endl;
    cout << indent << "-----------" << endl;
    for (size_t i = 0; i < registers.size(); ++i) {
        cout << indent << registers[i] << " = " << bits(registers[i]) << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(1000));

    return 0;
}
