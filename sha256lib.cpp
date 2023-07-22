#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// Constants for SHA-256
const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA-256 helper functions
inline uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

inline uint32_t Maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t Ror(uint32_t x, int n) {
    return (x >> n) | (x << (32 - n));
}

inline uint32_t Sigma0(uint32_t x) {
    return Ror(x, 2) ^ Ror(x, 13) ^ Ror(x, 22);
}

inline uint32_t Sigma1(uint32_t x) {
    return Ror(x, 6) ^ Ror(x, 11) ^ Ror(x, 25);
}

inline uint32_t Gamma0(uint32_t x) {
    return Ror(x, 7) ^ Ror(x, 18) ^ (x >> 3);
}

inline uint32_t Gamma1(uint32_t x) {
    return Ror(x, 17) ^ Ror(x, 19) ^ (x >> 10);
}

std::string sha256(const std::string& message) {
    // Initialize hash values
    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    // Pre-processing
    std::string padded = message;
    padded += '\x80'; // Padding with a single bit '1'
    while (padded.size() % 64 != 56) {
        padded += '\x00'; // Padding with zeros
    }

    // Append original message length in bits
    uint64_t bitLength = message.size() * 8;
    for (int i = 7; i >= 0; i--) {
        padded += static_cast<char>((bitLength >> (i * 8)) & 0xFF);
    }

    // Message blocks processing
    for (size_t i = 0; i < padded.size(); i += 64) {
        uint32_t w[64] = {0};
        for (int t = 0; t < 16; t++) {
            w[t] = (static_cast<uint8_t>(padded[i + 4 * t]) << 24) |
                   (static_cast<uint8_t>(padded[i + 4 * t + 1]) << 16) |
                   (static_cast<uint8_t>(padded[i + 4 * t + 2]) << 8) |
                   (static_cast<uint8_t>(padded[i + 4 * t + 3]));
        }

        for (int t = 16; t < 64; t++) {
            w[t] = Gamma1(w[t - 2]) + w[t - 7] + Gamma0(w[t - 15]) + w[t - 16];
        }

        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;
        uint32_t f = h5;
        uint32_t g = h6;
        uint32_t h = h7;

        for (int t = 0; t < 64; t++) {
            uint32_t T1 = h + Sigma1(e) + Ch(e, f, g) + K[t] + w[t];
            uint32_t T2 = Sigma0(a) + Maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    // Final hash value
    std::stringstream ss;
    ss << std::hex << std::setfill('0')
       << std::setw(8) << h0
       << std::setw(8) << h1
       << std::setw(8) << h2
       << std::setw(8) << h3
       << std::setw(8) << h4
       << std::setw(8) << h5
       << std::setw(8) << h6
       << std::setw(8) << h7;

    return ss.str();
}

int main() {
    std::string message = "Hello, SHA-256!";
    std::string hash = sha256(message);
    std::cout << "Message: " << message << std::endl;
    std::cout << "SHA-256: " << hash << std::endl;
    return 0;
}
