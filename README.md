# Bit-Ops

BitOps: Understanding the SHA-256 Algorithm through Code Visualization

Introduction:
In the realm of cryptography, the SHA-256 algorithm stands tall as a fundamental component of securing digital communications and data integrity. However, the inner workings of SHA-256 can be quite intricate and challenging to grasp at first glance. In this article, we embark on an exciting journey to comprehend the core concepts of SHA-256 through interactive code visualization and animations. Welcome to BitOps, where we dive into the bits and bytes that make SHA-256 tick!

Acknowledging the Original Author

The creators of BitOps are immensely grateful to in3rsha for the brilliant work on the original SHA-256 animation project. By forking the project and converting it to C++, they aimed to contribute to the developer community, enabling a broader audience to explore the fascinating world of SHA-256 with the help of code visualization and animations.

Please check out his Github projects here : https://github.com/in3rsha/sha256-animation
                                          : https://github.com/in3rsha/ 🥇

Open Source Spirit: Collaboration and Sharing

BitOps carries the spirit of open source development, where projects can evolve, grow, and find new life in the hands of dedicated developers. The C++ version of the SHA-256 animation is a testament to the power of collaboration, sharing knowledge, and building upon the work of others to create something valuable for the community.

Contributing to the Community

With BitOps, the torch of knowledge continues to shine brightly. Developers and cryptography enthusiasts can now explore SHA-256 in C++, gaining insights into this essential cryptographic algorithm through a new lens. BitOps aims to serve as an educational tool, enabling users to understand the inner workings of SHA-256 and promoting awareness of secure coding practices.

SHA-256 Basics:
Before delving into the code, let's understand the basics of SHA-256. The algorithm takes a message as input and produces a fixed-size 256-bit (32-byte) hash value. This cryptographic hash function is designed to be collision-resistant, meaning it is highly improbable to find two different messages with the same hash. The secure nature of SHA-256 makes it widely used in various applications like digital signatures, blockchain, and password hashing.

The BitOps Code:
Our journey starts with BitOps, a collection of C++ source files that demonstrate different steps of the SHA-256 algorithm. These source files, ranging from rotr.cpp to final.cpp, implement functions that perform essential operations such as right rotations, padding, message schedule calculation, and compression.

Visualizing Right Rotation (rotr.cpp):
The right rotation operation is a fundamental component of SHA-256. To help you understand it better, BitOps includes a rotr.cpp file that animates the right rotation operation on a 32-bit binary number. The visual representation helps you grasp the movement of bits during the rotation process.

Padding for SHA-256 (padding.cpp):
The padding of the input message is crucial in SHA-256. The padding.cpp file in BitOps showcases the implementation of the padding function for SHA-256. You can visualize how the message is extended to meet the required size for the algorithm.

Understanding Majority Calculation (maj.cpp):
SHA-256 involves calculating the majority of three 32-bit binary numbers. The maj.cpp file in BitOps lets you visualize the majority calculation and its significance in the SHA-256 algorithm.

Initiating with Initial Hash Values (initial.cpp):
To set the stage for SHA-256, the algorithm starts with initial hash values (H0). The initial.cpp file provides an animation that demonstrates the calculation of these critical hash values.

SHA-256 Compression Visualization (hashing.cpp):
The most vital part of SHA-256 is the compression function, which takes a message block and updates the hash values. The hashing.cpp file showcases the visualization of the SHA-256 compression process, offering a deeper insight into the algorithm's inner workings.

BitOps in Action (hash256.cpp):
BitOps is brought to life in the hash256.cpp file, where a two-round SHA-256 hashing process is executed for a given input. The file enables you to witness the transformations undergone by the input during the hashing process.

The Final Compression Step (final.cpp):
Finally, we arrive at the concluding step of SHA-256. The final.cpp file visualizes the last compression step, highlighting the calculation of the message schedule and the resulting hash value.

Unveiling the Expansion Step (expansion.cpp):
The expansion step is a crucial component of the SHA-256 compression function. The expansion.cpp file lets you visualize the calculation of the message schedule, step-by-step, making the process easily comprehensible.

expansion.cpp

The expansion.cpp code implements the expansion of the message schedule for the SHA-256 compression function. It takes an input string (default is "abc") and the block number (default is 0) and word number (default is 63) to calculate the message schedule.

Function Prototypes: The code declares function prototypes for various helper functions used in the main code.

Function Definitions: The code includes the definitions for the helper functions, such as padding, split, sigma1, sigma0, shr, rotr, and add. However, the actual implementations of these functions are missing and should be completed for the code to work correctly.

Main Function:

The main function processes command-line arguments to set the input, block_number, and t (word number) variables. If no arguments are provided, the default values are used.

The input string is converted to its binary representation and padded following the SHA-256 padding scheme.

The padded message is split into blocks of 512 bits (64 bytes) using the split function.

The main animation frames are printed to show the calculation of the message schedule. The code displays the values of different Wt (word) variables, which are intermediate values in the calculation of the message schedule.

The animation shows the calculation of Wt_16 to Wt. However, the animation is not complete, and the code displays only the calculation of Wt_16 to Wt_12. The remaining lines for Wt_11 to Wt_1 and Wt are commented out.

The sigma0, rotr, and shr functions are used in the calculation of Wt_15 to Wt_12.

Note: The code is incomplete, as the actual implementation of the helper functions is missing. The animation for the complete calculation of the message schedule should be added, and the logic for Wt_11 to Wt_1 and Wt should be implemented.

To complete the code, you need to define the helper functions (padding, split, sigma1, sigma0, shr, rotr, and add) and finish the animation part by uncommenting the lines for Wt_11 to Wt_1 and Wt and adding their respective calculations. Additionally, ensure that the output of the animation matches the expected results based on the SHA-256 algorithm's message schedule calculation.

final.cpp

The final.cpp code implements the final part of the SHA-256 hashing algorithm. It takes an input string, performs the SHA-256 hashing process, and displays the final hash value in binary, hexadecimal, and concatenated hexadecimal format using a simple animation.

Header Files: The code includes the necessary header files for basic input/output, vector manipulation, bit manipulation, and the custom sha256lib.hpp header that contains the SHA-256 functions.

Global Variables: The code declares global variables input, message, blocks, and hash_values.

Output Function: The output function is defined to write output text to the standard output.

Main Function:

The main function receives the command-line argument input_hex_bytes. If no argument is provided, the default input is set to "abc".

The input string is converted to its binary representation and then padded following the SHA-256 padding scheme.

The padded message is split into blocks of 512 bits (64 bytes), and the SHA-256 initial hash state is set using the initial hash values.

The SHA-256 compression function is applied to each block to update the hash values.

An animation is displayed to show the final hash value for each register (a, b, c, d, e, f, g, h) at each step of the compression function.

The final hash value is displayed in binary, hexadecimal, and concatenated hexadecimal format.

Note: The code assumes that the sha256lib.hpp header is properly implemented with the necessary SHA-256 functions. The animation part of the code creates a dynamic display of the intermediate hash values for each block processed. The SHA256::calculate_schedule and SHA256::compression functions are assumed to be implemented in sha256lib.hpp.

Please ensure that the sha256lib.hpp header contains the required SHA-256 functions for the code to work as intended. Additionally, you may want to add the SHA-256 logic implementation and verify that the output matches the expected results for the input you provide.

sha256.cpp

The hash256.cpp code performs SHA-256 hashing on a given hexadecimal input and displays the hash results for both the first and second hashes. 

Header Files: The code includes the necessary header files for basic input/output, string manipulation, and the custom sha256lib.hpp header that contains the SHA-256 functions.

Global Variables: The code declares global variables input, bytes, message, and digest.

Function hexToBytes: The hexToBytes function is defined to convert a hexadecimal input string to a vector of unsigned integers representing the bytes.

Output Function: The output function is defined to write output text to the standard output.

Main Function:

The main function receives command-line arguments: input_hex_bytes and an optional delay parameter.

The code converts the input_hex_bytes to bytes using the hexToBytes function and prepares the message string by converting each byte to its binary representation.

If the delay argument is set to "enter", the program prompts the user to hit enter to step through the process.

The code computes the first hash (SHA-256) by calling the sha256_hash function (which is assumed to be implemented in sha256lib.hpp) with the message string as input. The result is stored in the digest variable, and it is displayed.

The output of the first hash is used as the input for the second hash. The process is repeated, and the second hash (SHA-256) result is displayed.

Note: The code assumes that the sha256lib.hpp header is properly implemented with the necessary SHA-256 functions. Additionally, some parts of the code have placeholders (commented with // Assuming you have implemented...) that indicate the need for actual implementation of specific logic. These parts are essential for the complete functionality of the SHA-256 hashing process.

Please make sure to implement the missing parts of the code and verify that the sha256lib.hpp header contains the required SHA-256 functions for the code to work as intended.

hashing.cpp

The hashing.cpp code performs the hashing process using SHA-256 on data read from an input file and writes the results to both the standard output and an output file. 

Header Files: The code includes the necessary header files for basic input/output, file handling, string manipulation, and the custom sha256lib.hpp header that contains the SHA-256 functions.

Global Variables: The code declares global variables to store the data and intermediate results of the hashing process. These include the bytes vector, message string, blocks vector, and hash_state vector.

Output Function: The output function is defined to write output text to both the standard output and the output file stream.

Main Function:

The main function opens an output file for writing the results. It also catches the Ctrl-C signal to ensure the file is closed properly in case of early termination.

The code reads input data from a text file specified by the input_file_path variable. It assumes that each line of the input file represents data to be hashed.

For each line of input data, the code processes it, creates message blocks, and performs the SHA-256 hashing process. It then outputs the hash result for each block.

The code initializes the SHA-256 hash state using SHA256::initial_hash_values() from the sha256lib.hpp header.

Inside the loop for each line, there is a nested loop to process each block using SHA-256 compression and update the hash state.

The computed hash result for each block is formatted and output using the output function.

After processing all lines from the input file, the file streams are closed.

Note: Some parts of the code have placeholders (commented with // Assuming you have implemented...) that indicate the need for actual implementation of specific logic. These parts are essential for the complete functionality of the SHA-256 hashing process. You'll need to implement the missing parts of the code to ensure it works correctly. Additionally, the code assumes that the custom sha256lib.hpp header is properly implemented with the necessary SHA-256 functions.

Please make sure to implement the missing parts and verify that the sha256lib.hpp header contains the required SHA-256 functions for the code to work as intended.

initial.cpp

The initial.cpp code demonstrates the process of calculating the initial hash values (H0) used in the SHA-256 algorithm. The initial hash values are obtained by taking the first thirty-two bits of the fractional parts of the square roots of the first eight prime numbers (2, 3, 5, 7, 11, 13, 17, 19).

Header Files: The code includes the necessary header files for basic input/output, bit manipulation, and timing functions.

Function to Convert to Binary Representation: The function bits(uint32_t num) takes a 32-bit unsigned integer as input and returns its binary representation as a string.

Main Function:

The main function initializes a vector primes containing the first eight prime numbers (2, 3, 5, 7, 11, 13, 17, 19).
It also creates a vector registers to store the initial hash values (H0).
The code uses an animation loop to visualize the process of calculating the initial hash values.
In each frame of the animation, the code calculates and displays the intermediate steps of the process.
The animation shows how the initial hash values (H0) are obtained by performing square roots and extracting the first thirty-two bits of the fractional parts. The process involves converting the floating-point fractional part to a fixed-point representation (32-bit binary) by multiplying it with 2^32 (1ULL << 32).

The animation makes it easier to follow the step-by-step calculation of each initial hash value. It helps to visualize the process and understand how the fractional parts of square roots are used to create the initial values of the SHA-256 hash function.

maj.cpp

The maj.cpp code demonstrates how the majority function (Maj) works. In the SHA-256 algorithm, the majority function is used to calculate the majority of its three input bits, producing a single output bit. The majority function returns 1 if the majority of the input bits are 1s, and 0 otherwise.

Header Files: The code includes the necessary header files for basic input/output and bit manipulation.

Majority Function: The function Maj(bitset<32> x, bitset<32> y, bitset<32> z) takes three bitsets of size 32 (x, y, z) as input and returns a bitset of size 32 as the output. The function implements the majority logic using bitwise AND and XOR operations.

Main Function:

The main function allows passing three bit patterns (x, y, z) as command-line arguments in binary representation. If no arguments are provided, it uses default bit patterns.
It calls the Maj function in an animation loop.
In each iteration of the loop, it calculates the majority of x, y, z and displays the intermediate results using clear screen and delay to create the animation effect.
The main purpose of this code is to illustrate the behavior of the majority function and how it operates on its three input bits. This function is an essential part of the SHA-256 compression function, where it plays a crucial role in the bitwise operations used to generate the final hash value.

padding.cpp

Header Files: The code includes the necessary header files for basic input/output and bit manipulation.

Padding Function: The function padMessage(const std::string& message) takes the input message as a string and returns the padded message in binary representation. It calculates the number of bits needed to achieve a multiple of 512 bits and appends the padding bits as specified by the SHA-256 algorithm. The padding begins with a single bit '1', followed by zeros, and finally appends the original message length in bits (64-bit big-endian integer).

Main Function:

The main function allows passing the message as a command-line argument. If no argument is provided, it uses a default message "abc".
It converts the message characters to their binary representation and stores them in binaryMessage.
It then calls the padMessage function to pad the binary message according to the SHA-256 algorithm.
The final padded message is printed to the console.
The main purpose of this code is to demonstrate how to pad a message according to the SHA-256 specification. Padding is a crucial step in the SHA-256 algorithm to ensure the message is a multiple of 512 bits and to maintain data integrity during the hashing process.

rotr.cpp

Header Files: The code includes the necessary header files for basic input/output, bit manipulation, and animation.

Right Rotation Function: The function rotr(int n, uint32_t x) performs a right rotation on the 32-bit binary number x by n bits. The right rotation is done by shifting the bits to the right by n positions and then combining the shifted bits with the bits shifted to the left by 32 - n positions.

Animation Function: The function animateRotation(uint32_t x, int n) displays an animation to visualize the right rotation process for the binary number x by n bits. It iterates from 1 to n, showing the intermediate results of the right rotation.

Main Function:

The main function allows passing the binary number x and the number of bits n to rotate as command-line arguments. If no arguments are provided, it uses default values.
It checks if the provided binary number x is valid (not exceeding 32 bits) and prints an error message if it is not.
It then calls the animateRotation function to display the animation for the right rotation operation.
The main purpose of this code is to demonstrate and visualize how right rotation works on a 32-bit binary number. It can be used to better understand bitwise operations and their applications in algorithms like SHA-256, where right rotation is a common operation.

schedule.cpp

Header Files: The code includes the necessary header files for string manipulation, vector operations, bit manipulation, and animation.

Helper Functions:

rotr(int n, uint32_t x): Performs right rotation on a 32-bit binary number x by n bits.
add(uint32_t a, uint32_t b, uint32_t c, uint32_t d): Adds four 32-bit binary numbers and returns the result.
sigma0(uint32_t x): Performs the σ0 operation on a 32-bit binary number x.
sigma1(uint32_t x): Performs the σ1 operation on a 32-bit binary number x.
split(const std::string& str, int blockSize): Splits the input string into blocks of the specified size.
Message Schedule Calculation Function: The function calculateMessageSchedule(const std::string& block) calculates the message schedule from a 512-bit binary message block for the SHA-256 algorithm. It does the following:

It first extracts the initial 16 words of the message schedule from the 512-bit block.
It then iteratively calculates the remaining 48 words using the σ0 and σ1 operations and stores the results in the schedule vector.
During the calculation, an animation is displayed to show the progress of the message schedule calculation.
Main Function:

The main function allows passing a message block as a command-line argument. If no argument is provided, it uses the default input "abc".
It pads the input message and splits it into 512-bit blocks.
It then calls the calculateMessageSchedule function to calculate the message schedule for the provided block or the default block.
The main purpose of this code is to demonstrate how the message schedule is calculated from a 512-bit message block as part of the SHA-256 algorithm. The code provides an animation to visualize the calculation process, which is helpful for educational purposes and understanding the SHA-256 algorithm's internals.

sha256.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<string>: Provides string-related operations.
<sstream>: Provides string stream functionality.
<iomanip>: Provides functions to manipulate the output format.
Constants: The code defines an array K containing 64 constants used in the SHA-256 algorithm.

SHA-256 Helper Functions: The code defines several inline functions used as helper functions for the SHA-256 algorithm:

Ch(uint32_t x, uint32_t y, uint32_t z): Computes the Ch operation.
Maj(uint32_t x, uint32_t y, uint32_t z): Computes the Maj operation.
Ror(uint32_t x, int n): Performs right rotation on a 32-bit binary number.
Sigma0(uint32_t x): Computes the Sigma0 operation.
Sigma1(uint32_t x): Computes the Sigma1 operation.
Gamma0(uint32_t x): Computes the Gamma0 operation.
Gamma1(uint32_t x): Computes the Gamma1 operation.
SHA-256 Function: The main SHA-256 computation is performed in the function sha256(const std::string& message):

The function takes a message as input and returns the SHA-256 hash as a hexadecimal string.
It initializes the hash values h0, h1, h2, h3, h4, h5, h6, and h7.
The message is padded and processed in 512-bit (64-byte) blocks.
For each block, it calculates the 64 32-bit words w[0] to w[63].
It then performs the main SHA-256 compression function using the calculated w array and updates the hash values in each iteration.
The final hash value is obtained by concatenating the updated h0 to h7 in hexadecimal format.
Main Function:

The main function demonstrates the usage of the sha256 function by computing the SHA-256 hash of the string "Hello, SHA-256!".
It prints the original message and the resulting SHA-256 hash to the console.
Overall, this code provides a complete implementation of the SHA-256 algorithm, including helper functions and the main SHA-256 computation function, allowing you to compute the SHA-256 hash of any input message.

t1.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<vector>: Provides the std::vector container class to work with dynamic arrays of elements.
<bitset>: Enables manipulation of individual bits in a fixed-size sequence of bits.
"sha256lib.hpp": Presumably includes necessary functions for SHA-256 operations (not provided in the initial code).
Variable Initialization:

The variable input is initialized with the string "abc".
The variable message is set to the binary representation of the first character of the input string using bitset<8>(input.c_str()[0]).to_string().
The message is then padded to meet the SHA-256 block size requirement, and the resulting blocks are stored in the blocks vector.
The variable block_number is set to 0, indicating that the first block of the message will be processed.
The block string is assigned the first block for further processing.
The schedule vector is calculated by passing the block to the calculate_schedule function.
Constants and Initial Hash Values:

The w, k, initial, and hash vectors are initialized with values corresponding to the SHA-256 schedule (Wt), constants (Kt), initial hash values (IV), and current hash values, respectively.
Settings:

The variable indent is assigned the value of " ", which is used for indentation in the output.
Display State Function:

The function displayState() clears the screen and displays the current state of the hash values in the SHA-256 computation.
It shows the values of a, b, c, d, e, f, g, and h.
Delay Function:

The code includes a placeholder for the delay function, which is intended to introduce a delay in the animation for each step.
Main Animation Loop:

The animation starts by displaying the initial state and then waiting for 1 second before proceeding.
The animation displays the values of w[0] (message schedule) and the current values of a, b, c, d, e, f, g, and h.
The code ends after this initial animation step.
Incomplete Animation Loop:

The code has a comment indicating that the animation loop continues beyond the initial step, but the rest of the animation loop is missing from the provided code.
The code is intended to display intermediate states and perform SHA-256 computations using the w, k, and hash vectors, likely showing how these values are updated in each step of the SHA-256 computation.
Since the animation loop is not provided, it is unclear how the SHA-256 compression function is animated in the rest of the code. The missing parts would need to be implemented in order to complete the animation and demonstrate the SHA-256 compression process.

t2.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<bitset>: Enables manipulation of individual bits in a fixed-size sequence of bits.
Custom Function: The code uses a custom function toBinaryString(uint32_t num) to convert a 32-bit integer to its binary string representation.

Include Statements: The code includes placeholders for necessary functions from a "sha256lib.h" header file. The actual implementations of these functions are not provided in the initial code.

Input Message Preparation:

The variable input is initialized with the string "abc".
The variable message is set to the value of input, indicating that it will be used as the message to be processed.
Message Padding and Splitting:

The message is then padded to meet the SHA-256 block size requirement.
The padded message is split into blocks of 512 bits, and the first block (block_number = 0) is taken for further processing.
Schedule Calculation:

The variable schedule is assigned the result of the function calculate_schedule(block), which calculates the message schedule (W) for the given block.
Constants (Kt):

The variable k is assigned the value of the constants K, which are used in the SHA-256 compression function.
Initial Hash Values:

The variable initial is assigned the initial hash values (IV) for SHA-256.
The variable hash is initialized with the same values as initial.
T1 Calculation:

The variable t1 is calculated using the functions add, usigma1, and ch, and the constants K and W[0].
The function add takes five arguments and performs addition with overflow handling.
The function usigma1 calculates the sigma1 function for a 32-bit integer.
The function ch computes the choice function for SHA-256 compression.
Print Initial State:

The code prints the initial state before the compression (T2) begins.
It displays the values of W[0], K[0], and the intermediate result T1.
The current values of variables a, b, c, d, e, f, g, and h (the current state of the hash function) are also shown.
Animation Part: The animation part has been omitted for brevity, but it is assumed that this code will animate the SHA-256 compression process, updating the hash values at each step.
Overall, the code sets up the initial state for the SHA-256 compression function (T2), including the message schedule, constants, and initial hash values. It then calculates the value of T1 and displays the initial state before proceeding with the animation part to demonstrate the SHA-256 compression process. Note that the animation part is not provided in the code and may be implemented in the missing "sha256lib.h" header file.

usigma0.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<bitset>: Enables manipulation of individual bits in a fixed-size sequence of bits.
<thread>: Enables multi-threading and concurrent execution.
<chrono>: Provides time-related utilities for managing delays.
Utility Functions: rotr and bits

The code includes two utility functions:

uint32_t rotr(int n, uint32_t x);
std::string bits(uint32_t x);
rotr: Performs a right rotation on the 32-bit binary number x by n positions and returns the result.
bits: Converts a 32-bit binary number x to its binary string representation.
Animation for Computing Σ0(x)

The code provides animation to demonstrate the computation of Σ0(x) step-by-step using right rotations and XOR operations.
The default value of x is 0b00000000000000000011111111111111 (binary representation).
Command-line Arguments:
If at least one command-line argument (in addition to the program name) is provided, it is considered as a binary string, which will be converted to a 32-bit unsigned integer x.
Input Validation:
The code checks if the provided binary string is longer than 32 bits. If so, it displays an error message and exits the program.
Animation Steps:

The code performs three iterations to demonstrate the computation of Σ0(x).
For each iteration, it calculates ROTR(2, x), ROTR(13, x), and ROTR(22, x) and displays the binary representation of each result.
It then computes Σ0(x) by XORing the three rotated values and updates x to be the result of Σ0(x).
The animation provides a visualization of the bitwise operations involved in computing Σ0(x) in SHA-256.
Overall, the code allows the user to provide a binary string, which is then used to animate the step-by-step computation of Σ0(x) in SHA-256 using right rotations and XOR operations. If no command-line arguments are provided, the program uses a default value for x and runs the animation accordingly.

sigma1.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<bitset>: Enables manipulation of individual bits in a fixed-size sequence of bits.
<thread>: Enables multi-threading and concurrent execution.
<chrono>: Provides time-related utilities for managing delays.
Utility Functions: shr and rotr

The code includes two utility functions:

uint32_t shr(uint32_t x, int n);
uint32_t rotr(uint32_t x, int n);
Purpose: These functions perform shift right (logical right shift) and rotate right (circular right shift) operations on the 32-bit unsigned integer x by n positions and return the result.
Main Function

The main function serves as the entry point of the program.
Command-line Arguments:
If at least one command-line argument (in addition to the program name) is provided, it is considered as a binary string, which will be converted to a 32-bit unsigned integer x.
Input Validation:
The code checks if the provided binary string is longer than 32 bits. If so, it displays an error message and exits the program.
Animation

The code provides animation to demonstrate the sigma1 calculation step-by-step using rotations and shifts.
It initially displays the binary representation of x and fixed-width separators.
Animation Steps:
It animates the ROTR(17, x) operation by displaying the result of the right rotation for each possible rotation amount from 0 to 17.
It then animates the ROTR(19, x) operation by displaying the result of the right rotation for each possible rotation amount from 0 to 19.
Next, it animates the SHR(10, x) operation by displaying the result of the right shift for each possible shift amount from 0 to 10.
Finally, it animates the XOR operation of ROTR(17, x), ROTR(19, x), and SHR(10, x) for each bit position from 31 to 0, displaying the intermediate results of the XOR operation at each step.
The animation provides a visualization of the bitwise operations involved in calculating σ1(x) in SHA-256.
Overall, the code allows the user to provide a binary string, which is then processed to perform the sigma1 calculation step-by-step using rotations and shifts, with animated visualizations for each operation. If no command-line arguments are provided, the program uses a default value for x and runs the animation accordingly.

shr.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<bitset>: Enables manipulation of individual bits in a fixed-size sequence of bits.
<thread>: Enables multi-threading and concurrent execution.
<chrono>: Provides time-related utilities for managing delays.
Utility Function: shr

The shr function is defined with the following signature:

uint32_t shr(uint32_t x, int n);
Purpose: This function performs a right shift operation on the 32-bit unsigned integer x by n positions and returns the result.
Main Function

The main function serves as the entry point of the program.
Command-line Arguments:
If there are at least two command-line arguments (in addition to the program name), the program processes them as follows:
The first argument is expected to be a binary string, which will be converted to a 32-bit unsigned integer x.
The second argument is expected to be an integer value n, which will be used for shifting.
If only one argument (in addition to the program name) is provided, it is considered as the binary string, and the default value of n is set to 32.
If no arguments are provided, the program uses the default values for x and n.
Input Validation:
The code checks if the provided binary string is longer than 32 bits, and if so, it displays an error message and exits the program.
Animation:
The code uses animation to demonstrate the right shift operation.
The variable s holds the string representation of the shift amount n.
The loop iterates n times, and in each iteration, it clears the console, displays the current value of x, and the result of the shift operation using shr.
After each iteration, there is a delay of 100 milliseconds between steps to create the animation effect.
Overall, the code allows the user to provide a binary string and a shift amount to perform a right shift operation on a 32-bit word (x). It provides visual animation to show the shifting process step-by-step. If no command-line arguments are provided, the program uses default values for x and n and runs the animation.

xor.cpp

Header Files: The code includes the following necessary header files:

<iostream>: Provides input and output stream functionality.
<vector>: Defines the vector container and its related functions.
<thread>: Enables multi-threading and concurrent execution.
<chrono>: Provides time-related utilities for managing delays.
Utility Function: rotr

The rotr function is defined with the following signature:

uint32_t rotr(uint32_t x, int n);
Purpose: This function performs a circular right shift of the bits in a 32-bit unsigned integer x by n positions and returns the result.
Utility Function: displayBinary

The displayBinary function is defined with the following signature:

void displayBinary(uint32_t value, int width);
Purpose: This function converts a 32-bit unsigned integer value to its binary representation and displays it, keeping only the rightmost width number of bits.
Main Function

The main function serves as the entry point of the program.
Command-line Arguments:
If there are at least three command-line arguments (in addition to the program name), the program processes them as binary strings.
The binary strings are converted to 32-bit unsigned integers and stored in a vector values.
The width variable keeps track of the maximum width (number of bits) among the input binary strings.
Binary Strings Processing:
The program displays each binary value from the values vector using the displayBinary function.
The bitwise XOR (exclusive OR) operation is performed on all the values in the values vector, and the result is stored in the variable result.
The final result is displayed using the displayBinary function.
Animation (Fallback):
If the program is executed with fewer than three command-line arguments, an animation is displayed to demonstrate bitwise XOR operations with binary numbers.
Constants off, on, split, and delay control the animation parameters.
The animation simulates bitwise XOR operations using binary numbers and shows the intermediate results with a delay between steps.
Overall, the code provides functionality to process binary strings, perform bitwise XOR operations, and display the intermediate results. If there are insufficient command-line arguments, it runs an animation to demonstrate bitwise XOR operations.

Disclaimer: The code and visualizations in BitOps are for educational purposes only and may not be optimized for production use. For secure cryptographic implementations, use vetted libraries and consult security This section acknowledges the original creator, in3rsha, and emphasizes the collaborative spirit of open source development. BitOps respects the original project's contributions and intends to provide an educational platform for understanding SHA-256.
