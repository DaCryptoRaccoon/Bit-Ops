/**
 * SHA-256 σ1(x) Animation
 * -----------------------
 * This C++ program simulates the σ1(x) operation in SHA-256. σ1(x) is a combination of bitwise right
 * rotations and XOR operations on a 32-bit input word (x). The program visually demonstrates each step
 * of the operation and outputs the intermediate results.
 */

#include <iostream>    // For input/output operations
#include <bitset>      // For bitwise operations and visualization
#include <chrono>      // For sleep functionality (animation)
#include <thread>      // For sleep functionality (animation)
using namespace std;

// Constants for bitwise operations
const int ROTR_SHIFT_17 = 17;
const int ROTR_SHIFT_19 = 19;
const int SHR_SHIFT_10 = 10;
const int BIT_LENGTH = 32;

/**
 * Function to perform the right rotate (ROTR) operation.
 * It rotates the bits of the given 32-bit input 'x' to the right by 'shift' bits.
 * @param shift The number of bits to rotate.
 * @param x The input 32-bit word to be rotated.
 * @return The result of the right rotate operation.
 */
unsigned int rotr(int shift, unsigned int x) {
    return (x >> shift) | (x << (BIT_LENGTH - shift));
}

/**
 * Function to perform the right shift (SHR) operation.
 * It shifts the bits of the given 32-bit input 'x' to the right by 'shift' bits.
 * @param shift The number of bits to shift.
 * @param x The input 32-bit word to be shifted.
 * @return The result of the right shift operation.
 */
unsigned int shr(int shift, unsigned int x) {
    return x >> shift;
}

int main(int argc, char* argv[]) {
    // Default input (32-bit binary): 0b00000000000000000011111111111111 (binary for 487587725)
    unsigned int x = 0b00000000000000000011111111111111;

    // Read binary argument passed in the command line
    if (argc > 1) {
        x = strtol(argv[1], nullptr, 2);
        if (argc > 2 || to_string(x).size() > BIT_LENGTH) {
            cout << "We only operate on 32-bit words in SHA-256. Your x is " << to_string(x).size() << " bits." << endl;
            return 1;
        }
    }

    // Output original value of x
    cout << "x:       " << bitset<BIT_LENGTH>(x) << endl;
    cout << "         " << string(BIT_LENGTH, '-') << endl;

    // Animation of σ1(x) operation

    // ROTR(17, x)
    for (int i = 0; i <= ROTR_SHIFT_17; i++) {
        // Display intermediate results
        unsigned int rotX = rotr(i, x);
        cout << "ROTR 17: " << bitset<BIT_LENGTH>(rotX) << endl;
        cout << "ROTR 19: " << bitset<BIT_LENGTH>(x) << endl;
        cout << " SHR 10: " << bitset<BIT_LENGTH>(x) << endl;
        cout << "         " << string(BIT_LENGTH, '-') << endl;
        cout << "σ1(x):" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    // ROTR(19, x)
    for (int i = 0; i <= ROTR_SHIFT_19; i++) {
        // Display intermediate results
        unsigned int rotX19 = rotr(ROTR_SHIFT_19, x);
        unsigned int rotX = rotr(i, x);
        cout << "ROTR 17: " << bitset<BIT_LENGTH>(rotX) << endl;
        cout << "ROTR 19: " << bitset<BIT_LENGTH>(rotX19) << endl;
        cout << " SHR 10: " << bitset<BIT_LENGTH>(x) << endl;
        cout << "         " << string(BIT_LENGTH, '-') << endl;
        cout << "σ1(x):" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    // SHR(10, x)
    for (int i = 0; i <= SHR_SHIFT_10; i++) {
        // Display intermediate results
        unsigned int shrX = shr(i, x);
        unsigned int rotX19 = rotr(ROTR_SHIFT_19, x);
        unsigned int rotX = rotr(ROTR_SHIFT_17, x);
        cout << "ROTR 17: " << bitset<BIT_LENGTH>(rotX) << endl;
        cout << "ROTR 19: " << bitset<BIT_LENGTH>(rotX19) << endl;
        cout << " SHR 10: " << bitset<BIT_LENGTH>(shrX) << endl;
        cout << "         " << string(BIT_LENGTH, '-') << endl;
        cout << "σ1(x):" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    // ROTR(17, x) ^ ROTR(19, x) ^ SHR(10, x)
    for (int i = BIT_LENGTH; i >= 1; i--) {
        // Display intermediate results
        unsigned int shrX = shr(SHR_SHIFT_10, x);
        unsigned int rotX19 = rotr(ROTR_SHIFT_19, x);
        unsigned int rotX = rotr(ROTR_SHIFT_17, x);
        unsigned int sigma1X = rotX ^ rotX19 ^ shrX;
        cout << "ROTR 17: " << bitset<BIT_LENGTH>(rotX) << endl;
        cout << "ROTR 19: " << bitset<BIT_LENGTH>(rotX19) << " XOR" << endl;
        cout << " SHR 10: " << bitset<BIT_LENGTH>(shrX) << " XOR" << endl;
        cout << "         " << string(BIT_LENGTH, '-') << endl;
        cout << "σ1(x):   " << bitset<BIT_LENGTH>(sigma1X).to_string().substr(BIT_LENGTH - i, BIT_LENGTH).rjust(BIT_LENGTH, ' ') << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    this_thread::sleep_for(chrono::seconds(1));

    return 0;
}