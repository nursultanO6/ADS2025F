    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        long long n, k, sum = 0, min = 1;
        cin >> n >> k;
        vector<long long>list(n);
        for(int i = 0; i < n; i++){
            cin >> list[i]; 
            sum += list[i];
        }
        while(min < sum){
            long m = (min + sum)/2;
            long mn = 0, ind = 0;
            for(int i = 0; i < n; i++){
                if(m > list[i]){
                    ind ++;
                }else{
                    ind += (list[i]  + m -1)/m;
                }
            }
            if(ind > k)min = m+1;
            else sum = m;


        }
        cout << sum;
    }