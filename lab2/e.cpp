#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    set<string> std;
    for(int i = 0; i < n;i++){
        string s; cin >> s;
        std.insert(s);
    }
    cout << "All in all: " << std.size() << endl << "Students:" << endl;
    for (string i : std) {
        cout << i << endl;
    }
}