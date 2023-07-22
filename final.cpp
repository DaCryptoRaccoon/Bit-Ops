#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include "sha256lib.hpp" // Assuming you have a sha256lib.hpp header with the necessary functions

using namespace std;

// Global variables
string input;
string message;
vector<vector<unsigned int>> blocks;
vector<unsigned int> hash_values;

// Output function to write output to both standard output and the file output stream
void output(const string& text) {
    cout << text << endl;
}

int main(int argc, char* argv[]) {
    // Command Line Arguments
    if (argc >= 2) {
        input = argv[1];
    } else {
        // Default input
        input = "abc";
    }

    // Convert the input string to binary
    message = "";
    for (char c : input) {
        message += bitset<8>(c).to_string();
    }

    // Padding
    message += "1"; // Append 1 bit
    int message_length = message.size();
    int k = 448 - (message_length % 512); // Number of zero bits to append
    k = (k + 512) % 512; // To ensure k is positive (avoid -0)
    message += string(k, '0'); // Append k zero bits
    bitset<64> length_bits(message_length - 1); // Represent message_length in 64 bits
    message += length_bits.to_string(); // Append message length as 64 bits

    // Split the padded message into blocks of 512 bits (64 bytes)
    for (size_t i = 0; i < message.size(); i += 512) {
        vector<unsigned int> block(16, 0);
        for (size_t j = 0; j < 16; ++j) {
            for (size_t k = 0; k < 32; ++k) {
                block[j] |= (message[i + j * 32 + k] - '0') << (31 - k);
            }
        }
        blocks.push_back(block);
    }

    // Set initial hash state using initial hash values
    hash_values = SHA256::initial_hash_values();

    // Apply SHA-256 compression function to update hash values for each block
    for (const auto& block : blocks) {
        // Prepare 64 word message schedule
        vector<unsigned int> schedule = SHA256::calculate_schedule(block);

        // Remember starting hash values
        vector<unsigned int> initial = hash_values;

        // Apply compression function to update hash values
        hash_values = SHA256::compression(initial, schedule, SHA256::constants());
    }

    // Start animation
    system("clear");
    cout << "----------------" << endl;
    cout << "final hash value: (H" << blocks.size() << ")" << endl;
    cout << "----------------" << endl;

    vector<string> registers = {"a", "b", "c", "d", "e", "f", "g", "h"};

    // Display hash values in binary, hexadecimal, and concatenated hexadecimal format
    for (size_t frame = 1; frame <= 3; ++frame) {
        for (size_t i = 0; i < hash_values.size(); ++i) {
            string binary_value = bitset<32>(hash_values[i]).to_string();
            string hex_value = SHA256::to_hex(hash_values[i]);

            system("clear");
            cout << "----------------" << endl;
            cout << "final hash value: (H" << blocks.size() << ")" << endl;
            cout << "----------------" << endl;
            for (size_t j = 0; j < hash_values.size(); ++j) {
                cout << registers[j] << " = " << binary_value << " = " << hex_value << endl;
            }

            if (frame == 3) {
                string digest = "";
                for (size_t j = 0; j < hash_values.size(); ++j) {
                    digest += SHA256::to_hex(hash_values[j]);
                }
                cout << endl << digest << endl;
            }

            if (frame < 3) {
                this_thread::sleep_for(chrono::milliseconds(frame == 1 ? 1000 : 50));
            }
        }
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
    return 0;
}
