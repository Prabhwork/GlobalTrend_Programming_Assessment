#include <iostream>
#include <string>
using namespace std;
bool alphabetic(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (alphabetic(input)) {
        cout << "The string contains only alphabetic characters." << endl;
    } else {
        cout << "The string contains non-alphabetic characters." << endl;
    }

    return 0;
}