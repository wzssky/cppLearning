#include <iostream>
#include <sstream>
using namespace std;

string GetLine() {
        string result;
        getline(cin, result);
        return result;
    }

bool Getboolean(){
    stringstream ss;
    bool bolv;
    string input;
    while(true){
        input = GetLine();
        stringstream ss(input);
        if(ss >> boolalpha >> bolv){
             char remaining;
            if(ss >> remaining) // Something's left, input is invalid
                cout << "Unexpected character: " << remaining << endl;
            else 
                return bolv;
        }
        else{
            cout << "Invalid input. Please type 'true' or 'false'" << endl;
        }
    }
    
}
int main() {
    bool userInput = Getboolean();
    cout << "You entered: " << boolalpha << userInput << endl;
    return 0;
}
