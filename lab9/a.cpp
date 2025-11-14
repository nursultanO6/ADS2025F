#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> LPS(string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
        
    int len = 0;  
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) { 
                len = lps[len - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
bool search(string &pat, string &txt, int x) {
    string p = "";
    while(x--){
        p += pat;
    }
    int n = p.length();
    int m = txt.length();

    vector<int> lps = LPS(txt);

    int i = 0;
    int j = 0;

    while (i < n) {

        if (p[i] == txt[j]) {
            i++;
             j++;

            if (j == m) {
                return true;
            }
        }

        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

int main() {
    string a; cin >> a;
    string b; cin >> b;
    
    string pat = "";
    int r = (b.size() * 2 + a.size() - 1) / a.size();
    int l = 1;

    vector<int> lps = LPS(b);

    while(l < r){
        int m = (l + r) / 2;
        
        if(search(a, b, m))r = m;
        else l = m + 1;
    }

    
    if(search(a, b, l))cout <<  l;
    else cout << -1;

}