#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> nums1(n);
    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }
    int m; cin >> m;
    vector<int> nums2(m);
    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }

    int i = 0, j = 0;
    vector<int> res;
    while(i < n && j < m){
        if(nums1[i] >= nums2[j]){
            res.push_back(nums2[j]);
            j++;
        }else{
            res.push_back(nums1[i]);
            i++;
        }
    }
    while(i < n){
        res.push_back(nums1[i]);
        i++;
    }
    while(j < m){
        res.push_back(nums2[j]);
        j++;
    }
    for(int i : res){
        cout << i << " ";
    }
}