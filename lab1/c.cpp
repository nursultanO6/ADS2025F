    #include <iostream>
    #include <deque>
    using namespace std;

    int main()
    {
        string a; cin >> a;
        string b; cin >> b;
        deque<char> ab;
        deque<char> ba;
        for(int i = 0; i<a.size(); i++){
            if(a[i] == '#'){
                ab.pop_back();
            }else{
                ab.push_back(a[i]);
            }
        }
        for(int i = 0; i<b.size(); i++){
            if(b[i] == '#'){
                ba.pop_back();
            }else{
                ba.push_back(b[i]);
            }
        }
        if(ab == ba){
            cout << "Yes";
        }else{
            cout << "No";
        }
    }
        