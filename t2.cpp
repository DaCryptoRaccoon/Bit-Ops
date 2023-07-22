#include <iostream>
#include <bitset>

// Include necessary functions from "sha256lib.h" here (not provided in the initial code)

using namespace std;

// Function to convert a 32-bit integer to binary string
string toBinaryString(uint32_t num) {
    return bitset<32>(num).to_string();
}

int main() {
    string input = "abc";
    string message = input; // Assume the function 'unpack("B*")' just returns the original string
    string padded = padding(message);
    vector<string> blocks = split(padded, 512);
    int block_number = 0;
    string block = blocks[block_number];
    vector<uint32_t> schedule = calculate_schedule(block);

    // Constants (Kt)
    vector<uint32_t> k = K;

    // Initial Hash Values
    vector<uint32_t> initial = IV;
    vector<uint32_t> hash = initial;

    // T1
    uint32_t t1 = add(schedule[0], k[0], usigma1(hash[4]), ch(hash[4], hash[5], hash[6]), hash[7]);

    // Print initial state
    cout << "-----------" << endl;
    cout << "compression: (T2)" << endl;
    cout << "-----------" << endl;
    cout << "W0 = " << toBinaryString(schedule[0]) << " (message schedule)" << endl;
    cout << "K0 = " << toBinaryString(k[0]) << " (constant)" << endl;
    cout << "T1 = Σ1(e) + Ch(e, f, g) + h + K0  + W0" << endl;
    cout << "T2 =" << endl;
    cout << "a = " << toBinaryString(hash[0]) << endl;
    cout << "b = " << toBinaryString(hash[1]) << endl;
    cout << "c = " << toBinaryString(hash[2]) << endl;
    cout << "d = " << toBinaryString(hash[3]) << endl;
    cout << "e = " << toBinaryString(hash[4]) << endl;
    cout << "f = " << toBinaryString(hash[5]) << endl;
    cout << "g = " << toBinaryString(hash[6]) << endl;
    cout << "h = " << toBinaryString(hash[7]) << endl;
    cout << endl;

    // Animation part (omitted for brevity)

    return 0;
}
