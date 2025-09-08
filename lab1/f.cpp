    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int n; cin >> n;
        int d = 2;
        while(n>0){
            bool c = 0;
            for (int i = 2; i * i <= d; i++){
                if (d % i == 0) {   
                    c = 1;
                    break;
                }
            }if(c == 0){
                n--;
            }
            d++;
        }
        cout << d - 1;
    }

