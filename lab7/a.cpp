#include <bits/stdc++.h>
using namespace std;
void merge(vector<string>& v, int left, int mid, int right){
    int n1 = mid + 1 - left;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i].size() <= R[j].size()){
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<string>& res, int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(res, low, mid);
        mergeSort(res, mid+1, high);

        merge(res, low, mid, high);
    }
    return;
}
int main(){
    int n; cin >> n;
    while(n--){
        vector<string> res;
        string s;
        while(cin >> s){
            res.push_back(s);
            if(cin.peek() == '\n')break;
        }
        mergeSort(res, 0, res.size()-1);
        for(string i : res){
            cout << i << " ";
        }cout << endl;
    }
}