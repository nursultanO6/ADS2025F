    #include <iostream>
    #include <deque>
    using namespace std;

    int main()
    {
        string a; cin >> a;
        deque<char> ab;
        ab.push_back(a[0]);
        for(int i = 1; i < a.size(); i++){
            if(a[i] == ab[ab.size() - 1]){
                ab.pop_back();
                if(ab.empty() && i != a.size()-1){
                    i++;
                    ab.push_back(a[i]);
                }
            }else{
                ab.push_back(a[i]);
            }
        }
        if(ab.empty()){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }
        