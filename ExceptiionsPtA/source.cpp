// Will Hancock
// CIS 1202 501
// December 8, 2024
// Program to calculate character offsets and handle exceptions

#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exceptions
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: The starting character is not a valid letter.";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: The resulting character is out of range.";
    }
};

// Function to calculate the character offset
char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    char result = start + offset;

    if ((islower(start) && !islower(result)) || (isupper(start) && !isupper(result)) || !isalpha(result)) {
        throw invalidRangeException();
    }

    return result;
}

int main() {
    cout << "Character Offset Testing\n" << endl;

    // Test cases
    char testChars[] = { 'z', 'a', 'Z', 'a', 'A' };
    int offsets[] = { 1, -1, -1, 5, 32 };

    for (int i = 0; i < 5; i++) {
        try {
            cout << "Test case: character('" << testChars[i] << "', " << offsets[i] << ")" << endl;
            char result = character(testChars[i], offsets[i]);
            cout << "Result: '" << result << "'\n" << endl;
        }
        catch (const exception& e) {
            cout << "Exception: " << e.what() << "\n" << endl;
        }
    }

    return 0;
}
