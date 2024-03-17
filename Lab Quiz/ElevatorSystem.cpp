#include <iostream>
#include <string>

using namespace std;

class Elevator {
public:
    void parseInput(const string& input) {
        index = 0;
        this->input = input;
        try {
            G();
            if (index == input.length()) {
                cout << "Input parsed successfully." << endl;
            } else {
                cout << "Error: Parsing failed. Remaining input: " << input.substr(index) << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

private:
    string input;
    size_t index;

    void G() {
        if (input[index] == 'u' || input[index] == 'd') {
            cout << "Applying production: G -> UG" << endl;
            U();
            G();
        } else if (input[index] == '\0') {
            cout << "Applying production: G -> ε" << endl; // epsilon (e)
        } else {
            throw runtime_error("Unexpected character '" + to_string(input[index]) + "'");
        }
    }

    void U() {
        if (input[index] == 'u') {
            cout << "Applying production: U -> uD" << endl;
            index++;
            D();
        } else {
            cout << "Applying production: U -> u" << endl;
            throw runtime_error("Expected 'u'");
        }
    }

    void D() {
        if (input[index] == 'd') {
            cout << "Applying production: D -> dD" << endl;
            index++;
            D();
        } else if (input[index] == 'u' || input[index] == '\0') {
            cout << "Applying production: D -> ε" << endl; // epsilon (e)
        } else {
            throw runtime_error("Expected 'd' or end of input");
        }
    }
};

int main() {
    Elevator elevator;
    
    // Input from user
    string input;
    cout << "Enter input (u for up, d for down): ";
    getline(cin, input);

    cout << "Parsing..." << endl;
    elevator.parseInput(input);

    return 0;
}
