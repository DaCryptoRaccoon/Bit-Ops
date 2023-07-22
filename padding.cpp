#include <iostream>
#include <string>
#include <bitset>

// SHA-256 Padding function
std::string padMessage(const std::string& message) {
    uint64_t l = message.size();
    uint64_t k = (448 - l - 1) % 512;
    std::string padded = message + '\x80' + std::string(k / 8, '\0');
    
    // Append length of message in bits as 64-bit big-endian integer
    uint64_t messageBits = l * 8;
    for (int i = 7; i >= 0; --i) {
        padded.push_back(static_cast<char>((messageBits >> (i * 8)) & 0xFF));
    }
    
    return padded;
}

int main(int argc, char* argv[]) {
    std::string message;
    if (argc > 1) {
        message = argv[1];
    } else {
        // default message
        message = "abc";
    }
    
    // Convert message to binary representation
    std::string binaryMessage;
    for (char c : message) {
        binaryMessage += std::bitset<8>(c).to_string();
    }
    
    // Padding the message
    std::string paddedMessage = padMessage(binaryMessage);
    
    // Output the padded message
    std::cout << "Padded Message: " << paddedMessage << std::endl;
    
    return 0;
}
