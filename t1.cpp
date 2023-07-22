#include <iostream>
#include <vector>
#include <bitset>
#include "sha256lib.hpp"

using namespace std;

// Default
string input = "abc";
string message = bitset<8>(input.c_str()[0]).to_string(); // 011000010110001001100011
string padded = padding(message);
vector<string> blocks = split(padded, 512);

// Message block
size_t block_number = 0; // message block number
string block = blocks[block_number];

// Message schedule
vector<string> schedule = calculate_schedule(block);

// Schedule (Wt)
vector<string> w = schedule;

// Constants (Kt)
vector<string> k = K;

// Initial Hash Values
vector<string> initial = IV;
vector<string> hash = initial;

// Settings
string indent = "  ";

// Function to display hash state
void displayState() {
    system("clear");
    cout << "\n" << $state << "\n";
    cout << indent << "-----------\n";
    cout << indent << "compression: (T1)\n";
    cout << indent << "-----------\n";
    cout << "\n\n\n\n\n\n\n\n";
    cout << indent << "a = " << bits(hash[0]) << "\n";
    cout << indent << "b = " << bits(hash[1]) << "\n";
    cout << indent << "c = " << bits(hash[2]) << "\n";
    cout << indent << "d = " << bits(hash[3]) << "\n";
    cout << indent << "e = " << bits(hash[4]) << "\n";
    cout << indent << "f = " << bits(hash[5]) << "\n";
    cout << indent << "g = " << bits(hash[6]) << "\n";
    cout << indent << "h = " << bits(hash[7]) << "\n";
}

// Animation delay function
void delay(int milliseconds) {
    // Implement the delay function in C++
}

// Main animation loop
int main() {
    // Start animation
    displayState();
    delay(1000);

    // Start
    displayState();
    cout << indent << "-----------\n";
    cout << indent << "compression: (T1)\n";
    cout << indent << "-----------\n";
    cout << indent << "W0 = " << bits(w[0]) << " (message schedule)\n";
    cout << "\n\n\n\n\n";
    cout << indent << "a = " << bits(hash[0]) << "\n";
    cout << indent << "b = " << bits(hash[1]) << "\n";
    cout << indent << "c = " << bits(hash[2]) << "\n";
    cout << indent << "d = " << bits(hash[3]) << "\n";
    cout << indent << "e = " << bits(hash[4]) << "\n";
    cout << indent << "f = " << bits(hash[5]) << "\n";
    cout << indent << "g = " << bits(hash[6]) << "\n";
    cout << indent << "h = " << bits(hash[7]) << "\n";
    delay(1000);

    // Continue the animation for the rest of the code...

    return 0;
}
