#include <iostream>
#include <sstream>
using namespace std;



int main() {
    istringstream ss("18.2");
    // ss.ignore();
    string st; 
    getline(ss, st);
    cout << " " << st << endl;
    return 0;
}
