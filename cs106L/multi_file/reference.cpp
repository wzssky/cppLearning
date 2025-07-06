#include <iostream>
#include <string>
#include <cctype> // For tolower
using namespace std;
/* Prototype a function called ConvertToLowerCase, which returns a lower-case
    * version of the input string.
    */
string ConvertToLowerCase(string& input);
int main() {
    string myString = "THIS IS A STRING!";
    cout << ConvertToLowerCase(myString) << endl;
    cout << myString << endl;
}
/* Implementation of ConvertToLowerCase. */
string ConvertToLowerCase(string& input) { // Now corrected.
    for (int k = 0; k < input.size(); ++k)
        input[k] = tolower(input[k]); // tolower converts a char to lower-case
    return input;
}