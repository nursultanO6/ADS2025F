#include <bits/stdc++.h>
using namespace std;

void heapify(string& arr, int n, int i){

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(string& arr){
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}



int main(){
    int n; cin >> n;
    string arr; cin >> arr;

    string v;
    string c;
    for(char i : arr){
        if(i == 'a' || i == 'o' || i == 'u' || i == 'e' || i == 'i'){
            v += i;
        }else{
            c+= i;
        }
    }
    heapSort(v);
    heapSort(c);
    string res = v+c;
    cout << res;
}