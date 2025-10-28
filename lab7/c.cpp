#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& v, int left, int mid, int right){
    int n1 = mid + 1 - left;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i]<= R[j]){
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
void mergeSort(vector<int>& res, int low, int high){
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
    vector<int> nums1(n);
    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }
    vector<int> nums2(m);
    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }
    mergeSort(nums1, 0, n-1);
    mergeSort(nums2, 0, m-1);
    int i = 0;
    int j = 0;
    vector<int> res;
    while(i < n && j < m){
        if(nums1[i] == nums2[j]){
            res.push_back(nums2[j]);
            j++;
            i++;
        }else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for(int i : res){
        cout << i << " ";
    }
}