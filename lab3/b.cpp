#include <bits/stdc++.h>
using namespace std;
int main(){
    long n, k, sum = 0, max = 0;
    cin >> n >> k;
    vector<long>list(n);
    for(int i = 0; i < n; i++){
        cin >> list[i]; 
        sum += list[i];
        if(max < list[i])max = list[i];
    }
    while(max < sum){
        long m = (max + sum)/2;
        long mn = 0, ind = 1;
        for(int i = 0; i < n; i++){
            if(mn + list[i] > m){
                mn = list[i];
                ind++;
            }else{
                mn += list[i];
            }
        }
        if(ind > k)max = m+1;
        else sum = m;


    }
    cout << sum;
}