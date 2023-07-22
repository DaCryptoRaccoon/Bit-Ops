#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

// Function prototypes
string padding(const string& message);
vector<uint32_t> split(const string& padded, int size);
uint32_t sigma1(uint32_t x);
uint32_t sigma0(uint32_t x);
uint32_t shr(uint32_t x, int n);
uint32_t rotr(uint32_t x, int n);
uint32_t add(uint32_t a, uint32_t b, uint32_t c, uint32_t d);

// Function definitions
string padding(const string& message) {
    // Implementation of the padding function
    // ...
}

vector<uint32_t> split(const string& padded, int size) {
    // Implementation of the split function
    // ...
}

uint32_t sigma1(uint32_t x) {
    // Implementation of the sigma1 function
    // ...
}

uint32_t sigma0(uint32_t x) {
    // Implementation of the sigma0 function
    // ...
}

uint32_t shr(uint32_t x, int n) {
    // Implementation of the SHR function (right shift)
    // ...
}

uint32_t rotr(uint32_t x, int n) {
    // Implementation of the ROTR function (right rotation)
    // ...
}

uint32_t add(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    // Implementation of the ADD function
    // ...
}

int main(int argc, char* argv[]) {
    // Default values
    string input = "abc";
    string message = bitset<8>(input).to_string();
    string padded = padding(message);
    vector<uint32_t> blocks = split(padded, 512);
    int block_number = 0; // message block number
    vector<uint32_t> schedule(64, 0); // Initialize schedule with 64 zeros

    int t = 63; // the word in the message schedule we want to calculate

    // Arguments passed
    if (argc > 1) {
        // message block
        string block_str = argv[1];
        block_str = block_str.insert(0, 512 - block_str.length(), '0'); // Pad with zeros if necessary
        blocks[0] = bitset<32>(block_str.substr(0, 32)).to_ulong();
        blocks[1] = bitset<32>(block_str.substr(32)).to_ulong();
    }

    if (argc > 2) {
        // word number
        t = stoi(argv[2]);
    }

    // Copy first 16 words to schedule from the blocks
    for (int i = 0; i < 16; ++i) {
        schedule[i] = blocks[block_number * 16 + i];
    }

    // Calculate remaining 48 words
    for (int i = 16; i < 64; ++i) {
        schedule[i] = add(sigma1(schedule[i - 2]), schedule[i - 7], sigma0(schedule[i - 15]), schedule[i - 16]);
    }

    // Convenient variables for word numbers in the schedule
    string t_str = to_string(t);
    string t_1_str = to_string(t - 1);
    string t_2_str = to_string(t - 2);
    string t_3_str = to_string(t - 3);
    string t_4_str = to_string(t - 4);
    string t_5_str = to_string(t - 5);
    string t_6_str = to_string(t - 6);
    string t_7_str = to_string(t - 7);
    string t_8_str = to_string(t - 8);
    string t_9_str = to_string(t - 9);
    string t_10_str = to_string(t - 10);
    string t_11_str = to_string(t - 11);
    string t_12_str = to_string(t - 12);
    string t_13_str = to_string(t - 13);
    string t_14_str = to_string(t - 14);
    string t_15_str = to_string(t - 15);
    string t_16_str = to_string(t - 16);

    // Print animation frames (replace system("clear") with appropriate clear screen command for your system)
    cout << "----------------\n";
    cout << "message schedule: (expansion)\n";
    cout << "----------------\n";
    cout << "W" << t_16_str << " " << bitset<32>(schedule[t - 16]).to_string() << endl;
    cout << "W" << t_15_str << " " << bitset<32>(sigma0(schedule[t - 15])).to_string() << " σ0" << endl;
    cout << "W" << t_14_str << " " << bitset<32>(rotr(7, schedule[t - 15])).to_string() << " ROTR 7" << endl;
    cout << "W" << t_13_str << " " << bitset<32>(rotr(18, schedule[t - 15])).to_string() << " ROTR 18" << endl;
    cout << "W" << t_12_str << " " << bitset<32>(shr(3, schedule[t - 15])).to_string() << " SHR 3" << endl;
    // Add more lines for other Wt_11, Wt_10, ..., Wt_1, Wt

    return 0;
}
