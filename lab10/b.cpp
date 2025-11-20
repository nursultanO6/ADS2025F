#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    int start, finish;
    cin >> start >> finish;

    vector<int> dist(n + 1, -1);

    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int i = q.front();
        q.pop();

        for(int j = 1; j <= n; j++){
            if(adj[i][j] == 1 && dist[j] == -1){
                dist[j] = dist[i] + 1;
                q.push(j);
            }
        }
    }
    cout << dist[finish];
}
