#include <bits/stdc++.h>
using namespace std;


bool comp(pair<pair<string, string>, double> a, pair<pair<string, string>, double> b){
    if(a.second != b.second)return a.second < b.second;
    if(a.first.first != b.first.first)return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

void merge(vector<pair<pair<string, string>, double>>& v, int left, int mid, int right){
    int n1 = mid + 1 - left;
    int n2 = right - mid;

    vector<pair<pair<string, string>, double>> L(n1), R(n2);
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
void mergeSort(vector<pair<pair<string, string>, double>>& res, int low, int high){
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
    int org = n;
    map<string, double> grades{
        {"A+", 4.0},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.0},
        {"C+", 2.50},
        {"C", 2.0},
        {"D+", 1.50},
        {"D", 1.0},
        {"F", 0.0}
    };
    vector<pair<pair<string,string> ,double>> res;
    while(n > 0){
        string fn, ln;
        int sub;
        cin >> fn >> ln;
        cin >> sub;
        double g = 0.0, c = 0.0;
        for(int i = 0; i < sub; i++){
            string m; cin >> m;
            int cre; cin >> cre;

            g += cre * grades[m];
            c += cre;
        }
        res.push_back({{fn, ln}, g/c});
        n--;
    }
    mergeSort(res, 0, org-1);

    for(pair<pair<string, string>, double> i : res){
        cout << i.first.first + " " + i.first.second + " " << fixed << setprecision(3) << i.second * 1.0 << endl; 
    }
    return 0;
    
}