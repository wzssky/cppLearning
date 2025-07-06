#include <vector>
#include <iostream>

using namespace std;
void out_terminal(vector<int>& v){
    for(size_t i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec(5, 10);
    out_terminal(vec);
    vec.push_back(2);
    out_terminal(vec);
    vec.insert(vec.begin() + 2, 200);
    out_terminal(vec);
    
}