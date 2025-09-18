#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
    deque<int> b;
    deque<int> n;
    int nu = 0;
    bool t = 0;
    for(int i = 0; i < 5; i++){
        int g; cin >> g;
        b.push_back(g);
    }
    for(int i = 0; i < 5; i++){
        int g; cin >> g;
        n.push_back(g);
    }
    while(!b.empty() && !n.empty() && nu < 1000000)
    {   
        int bb = b.front();
        int nn = n.front();
        b.pop_front();
        n.pop_front();
        if(bb == 0 && nn == 9) {
            b.push_back(bb);
            b.push_back(nn);
        }else if(bb == 9 && nn == 0) {
            n.push_back(bb);
            n.push_back(nn);
        }else if(bb - nn > 0) {
            b.push_back(bb);
            b.push_back(nn);
        } else {
            n.push_back(bb);
            n.push_back(nn);
        }

        nu++;
   
    }
    if(nu >= 1000000)cout << "blin nichya";
    else if(n.empty()){
        cout << "Boris " << nu;
    }else if(b.empty()){
        cout << "Nursik " << nu;
    }
}
