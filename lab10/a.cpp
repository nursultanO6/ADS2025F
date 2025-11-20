#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> adj(m + 2, vector<int>(n + 2, 0));
    int mush = 0;
    queue<pair<int, int>> q;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == 1)mush++;
            else if(adj[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    int time = 0;
    while(!q.empty()){
        if(!mush){
            break;
        }
        int ss = q.size();
        while(ss--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(adj[i][j+1] == 1){
                adj[i][j+1] = 2;
                q.push({i, j+1});
                mush--;
            }
            if(adj[i-1][j] == 1){
                adj[i-1][j] = 2;
                q.push({i-1, j});
                mush--;
            }
            if(adj[i][j-1] == 1){
                adj[i][j-1] = 2;
                q.push({i, j-1});
                mush--;
            }
            if(adj[i+1][j] == 1){
                adj[i+1][j] = 2;
                q.push({i+1, j});
                mush--;
            }
        }
        time++;
    }
    if(mush){
        cout << -1;
    }else{
        cout << time;
    }

    
}
