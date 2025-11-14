#include <bits/stdc++.h>
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

void search(string &txt, string &pat, int& sum) {
    int n =txt.size();
    int m = pat.size();

    vector<int> lps = LPS(pat);

    int i = 0;
    int j = 0;

    while (i < n) {

        if (pat[j] == txt[i]) {
            i++;
            j++;

            if (j == m) {
                sum++;
                j = lps[j-1];
            }
        }

        else {
            if( j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}

int main() {
    string a, b;
    int n;
    
    cin >> a >> n;     // read pattern and number
    cin.ignore();        // ignore newline
    getline(cin, b); 
    

    int sum = 0;
    search(b, a, sum);
    if(sum >= n)cout << "YES";
    else cout << "NO";

}