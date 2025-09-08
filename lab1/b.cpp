        #include <iostream>
        #include <vector>
        using namespace std;

        int main()
        {
            int n; cin >> n;
            vector<int> list(n);
            for(int i = 0; i < n; i++){
                cin >> list[i];
            }
            cout << "-1" << " ";
            for(int i = 1; i < n; i++){
                bool b = 1;
                for(int j = i-1; j >= 0; j--){
                    if(list[i] >= list[j]){
                        cout << list[j] << " ";
                        b = 0;
                        break;
                    }
                }
                if(b){
                    cout << "-1" << " ";   
                }
            }
        }
