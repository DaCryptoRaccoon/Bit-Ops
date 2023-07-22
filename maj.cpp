#include <iostream>
#include <bitset>
#include <thread>
#include <chrono>

using namespace std;

// Function to calculate the majority of x, y, z
bitset<32> Maj(bitset<32> x, bitset<32> y, bitset<32> z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

int main(int argc, char* argv[]) {
    // Defaults
    bitset<32> x(0b00000000111111110000000011111111); // 0x428a2f98
    bitset<32> y(0b00000000000000001111111111111111); // 0x71374491
    bitset<32> z(0b11111111111111110000000000000000); // 0xb5c0fbcf

    // Arguments passed
    if (argc == 4) {
        x = bitset<32>(stoul(argv[1], nullptr, 2));
        y = bitset<32>(stoul(argv[2], nullptr, 2));
        z = bitset<32>(stoul(argv[3], nullptr, 2));
    }

    // Animation
    for (int i = 32; i >= 1; --i) {
        system("clear");
        bitset<32> maj = Maj(x, y, z);
        cout << string(i + 3, ' ') << "▼" << endl;
        cout << "x: " << x << " " << x[i - 1] << endl;
        cout << "y: " << y << " " << y[i - 1] << endl;
        cout << "z: " << z << " " << z[i - 1] << endl;
        cout << string(32, '-') << endl;
        cout << maj.to_string().substr(i - 1).rjust(35, ' ') << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    this_thread::sleep_for(chrono::seconds(1));

    return 0;
}
