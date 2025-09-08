#include <bits/stdc++.h>
using namespace std;
int main(){
    char a; cin >> a;
    deque<int> ads;
    while(a!= '!'){
        if(a == '*'){
            if(ads.empty()){
                cout << "error" << endl;
            }else{
                cout << ads.front() + ads.back() << endl;
                ads.pop_front();
                if(!ads.empty())ads.pop_back();
            }
        }else {
            int k;
            cin >> k;
            if(a == '+')ads.push_front(k);
            else if(a == '-')ads.push_back(k);
        }
        cin >> a;
    }

}