#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string pattern) {
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

int main() {
    string give;
    int n;
    cin >> give >> n;

    vector<string> city(n);
    vector<int> buf(n);
    vector<string> res;

    int best = 0;

    for(int i = 0; i < n; i++){
        cin >> city[i];
        city[i][0] = tolower(city[i][0]);

        vector<int> lps = LPS(city[i] + give);
        int overlap = lps.back();

        if(best < overlap) best = overlap;
        buf[i] = overlap;
    }

    for(int i = 0; i < n; i++){
        city[i][0] = toupper(city[i][0]);
        if(buf[i] == best && best != 0){
            res.push_back(city[i]);
        }
    }

    cout << res.size() << endl;
    for(string s : res) cout << s << endl;

    return 0;
}
