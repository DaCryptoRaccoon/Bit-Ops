#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "sha256lib.hpp" // Assuming you have a sha256lib.hpp header with the necessary functions

using namespace std;

// Global variables
vector<unsigned int> bytes;
string message;
vector<vector<unsigned int>> blocks;
vector<unsigned int> hash_state;

// Output function to write output to both standard output and the file output stream
ofstream output_file;
void output(const string& text) {
    cout << text << endl;
    if (output_file.is_open()) {
        output_file << text << endl;
    }
}

int main() {
    // Open a file for writing the results
    string output_file_path = "output.txt"; // Change this path to the desired output file
    output_file.open(output_file_path);

    // Catch Ctrl-C to prevent unsightly errors when terminating early
    signal(SIGINT, [](int) {
        output_file.close();
        exit(0);
    });

    // 1. Message
    // Assuming you have implemented the necessary logic for processing the message and setting global variables like 'bytes' and 'message'

    // 2. Padding
    // Assuming you have implemented the necessary padding logic for the message and updated the 'message' string

    // 3. Message Blocks
    // Assuming you have implemented the logic to split the 'message' string into blocks and store them in 'blocks' vector

    // Read input data from a text file
    string input_file_path = "MASTERWORDS.txt"; // Change this path to the input file containing data to hash
    ifstream input_file(input_file_path);
    if (!input_file.is_open()) {
        cerr << "Error opening input file." << endl;
        output_file.close();
        return 1;
    }

    string input_line;
    while (getline(input_file, input_line)) {
        // Process each line of input data and hash it
        // Assuming you have implemented the necessary logic for processing the line and updating global variables accordingly

        // 4. Message Schedule
        // Assuming you have implemented the logic to create the message schedule for the current block

        // Initialize the SHA-256 hash state
        hash_state = SHA256::initial_hash_values();

        // For each block
        for (size_t i = 0; i < blocks.size(); ++i) {
            // make variables global so scripts can access them
            vector<unsigned int> block = blocks[i];

            // 5. Compression (Initial Hash Values)
            // Assuming you have implemented the logic to set initial hash values on the first run

            // 5. Compression
            // Assuming you have implemented the logic to perform the compression using hash values from the previous compression

            // Output the hash result for each block
            stringstream result_stream;
            result_stream << "Hash result for block " << i << " of line '" << input_line << "': ";
            for (unsigned int h : hash_state) {
                result_stream << hex << uppercase << setfill('0') << setw(8) << h;
            }
            output(result_stream.str());
        }
    }

    // Close the file input and output streams
    input_file.close();
    output_file.close();

    return 0;
}
