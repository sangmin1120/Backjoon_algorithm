/**
 * 택배 배송
 * Dikjstra (G5)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> graph[50001];
int dist[50001];

void solution() {

    priority_queue<pair<int,int>> pq;
    pq.push({0,1}); // weight, vertex
    dist[1] = 0;

    while (!pq.empty()) {
        auto c = pq.top(); pq.pop();
        int cur = c.second;
        int val = -c.first;

        if (dist[cur] < val)    continue;

        for (auto g : graph[cur]) {
            int next = g.first;
            int w = g.second + dist[cur];

            if (dist[next] > w) {
                dist[next] = w;
                pq.push({-w,next});
            }
        }
    }

    cout << dist[n] << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //input
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    fill(dist,dist+n+1,INT_MAX);

    solution();

    return 0;
}
