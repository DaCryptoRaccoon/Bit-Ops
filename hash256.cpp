#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "sha256lib.hpp" // Assuming you have a sha256lib.hpp header with the necessary functions

using namespace std;

// Global variables
string input;
vector<unsigned int> bytes;
string message;
string digest;

// Function to convert hexadecimal input to bytes
vector<unsigned int> hexToBytes(const string& hex) {
    vector<unsigned int> bytes;
    for (size_t i = 2; i < hex.size(); i += 2) {
        stringstream ss;
        ss << hex.substr(i, 2);
        unsigned int byte;
        ss >> hex >> byte;
        bytes.push_back(byte);
    }
    return bytes;
}

// Output function to write output to both standard output and the file output stream
void output(const string& text) {
    cout << text << endl;
}

int main(int argc, char* argv[]) {
    // Command Line Arguments
    string delay = "fast"; // Default delay value is "fast"
    if (argc >= 3) {
        input = argv[1];
        delay = argv[2];
    } else if (argc == 2) {
        input = argv[1];
    } else {
        cout << "Usage: " << argv[0] << " input_hex_bytes [delay]" << endl;
        return 1;
    }

    // Assume that every input is hexadecimal bytes
    if (input.substr(0, 2) != "0x") {
        input = "0x" + input; // prepend 0x if there isn't one (so the upcoming functions can detect it correctly)
    }

    // Make sure it's a valid size (even number of characters)
    if (input.size() % 2 != 0) {
        cout << "Invalid input to hash256.rb. Expecting even number of hex characters (i.e. bytes)." << endl;
        return 1;
    }

    // Convert hex to bytes
    bytes = hexToBytes(input);
    stringstream message_stream;
    for (unsigned int x : bytes) {
        message_stream << bitset<8>(x).to_string();
    }
    message = message_stream.str();

    // Note about hitting enter to step
    if (delay == "enter") {
        cout << "Hit enter to step through." << endl;
        cin.get();
    }

    // Catch Ctrl-C to prevent unsightly errors when terminating early
    signal(SIGINT, [](int) {
        exit(0);
    });

    // 1. First Hash
    // Assuming you have implemented the necessary logic for SHA256 hashing
    digest = sha256_hash(message);
    cout << "First Hash (SHA-256): " << digest << endl;

    // 2. Use output of first hash as input to second hash
    input = "0x" + digest; // prepend 0x to show that it's hex bytes
    bytes = hexToBytes(input);
    stringstream message_stream_2;
    for (unsigned int x : bytes) {
        message_stream_2 << bitset<8>(x).to_string();
    }
    message = message_stream_2.str();

    // 2. Second Hash
    // Assuming you have implemented the necessary logic for SHA256 hashing
    digest = sha256_hash(message);
    cout << "Second Hash (SHA-256): " << digest << endl;

    return 0;
}
