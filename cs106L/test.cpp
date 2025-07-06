#include <iostream>
#include <sstream>
using namespace std;

int main(){
    
    ostringstream oss1("Ito-En green Tea", ostringstream::ate);
    cout << oss1.str() << endl;

    oss1 << "killer" << 169;
    cout << oss1.str() << endl;
    // printStateBits(oss1);
    istringstream iss ("36.9 enhance");
    int num1;
    string str1;
    iss >> num1 >> str1;
    // iss >> num1;
    cout << num1 << " " << str1 << endl;



}
