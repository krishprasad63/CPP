#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("numbers.txt"); // Name of the input text file
    if (!inputFile) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::vector<int> numbers; // Dynamic array to store the integers
    int number;

    // Read integers from the file
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    // Print the numbers to confirm
    std::cout << "Numbers read from the file:" << std::endl;
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
