#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int n, m;
long long dist[501];
vector<pair<int, int>> adj[501];

int main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) dist[i] = INF;
  dist[1] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  bool timeMachine = false;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) continue;
      for (int j = 0; j < adj[i].size(); j++) {
        int goal = adj[i][j].first, pay = adj[i][j].second;
        if (dist[goal] > dist[i] + pay) {
          //   cout<<i<<' '<<goal<<' '<<dist[i]+pay<<endl;
          dist[goal] = dist[i] + pay;
          if (k == n) timeMachine = true;
        }
      }
    }

  if (timeMachine)
    cout << -1;
  else {
    for (int i = 2; i <= n; i++) {
      long long result = dist[i] == INF ? -1 : dist[i];
      cout << result << '\n';
    }
  }
}