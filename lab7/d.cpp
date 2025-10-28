#include <bits/stdc++.h>
using namespace std;


bool comp(const pair<vector<int>, int>& a, const pair<vector<int>, int>& b){
    if(a.second != b.second)return a.second > b.second;
    int n = a.first.size();
    for(int i = 0; i < n; i++){
        if(a.first[i] != b.first[i])return a.first[i] < b.first[i];
    }
    return a.first[0] < b.first[0];
}

void merge(vector<pair<vector<int>, int>>& v, int left, int mid, int right){
    int n1 = mid + 1 - left;
    int n2 = right - mid;

    vector<pair<vector<int>,int>> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(comp(L[i], R[j])){
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
void mergeSort(vector<pair<vector<int>,int>>& res, int low, int high){
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
    int m; cin >> m;
    vector<pair<vector<int>, int>> res;
    for(int i = 0; i < n; i++){
        int sum = 0;
        pair<vector<int>,int> row;
        for(int j = 0; j < m; j++){
            int num; cin >> num;
            sum += num;
            row.first.push_back(num);
        }
        row.second=sum;
        res.push_back(row);
    }
    mergeSort(res, 0, n-1);
    for(pair<vector<int> , int> i : res){
        for(int j : i.first){
            cout << j << " ";
        }
        cout << endl;
    }
    
}