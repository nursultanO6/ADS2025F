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

void search(string &txt, string &pat, vector<int> &res, int &sum) {
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
                res.push_back(i+1 - pat.size());
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
    cin >> a >> b;
    vector<int> res;
    int sum = 0;
    search(a, b, res, sum);
    cout << sum << endl;
    for(int i : res)cout << i << " ";
}