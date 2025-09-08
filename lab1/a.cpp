#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--){
        int a; cin >> a;
        deque<int> men;
        men.push_front(a);   
        for(int i = a-1; i > 0 ; i--){
            men.push_front(i);
            int b = i % men.size();
            for(int j = b; j > 0; j--){
                men.push_front(men.back());
                men.pop_back();
            }
        }
        for(int i : men){
            cout << i << " ";
        }cout << endl;
    }
}
