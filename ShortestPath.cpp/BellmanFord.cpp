// idea: run relax operation for all vetices nV-1 times
#include<bits/stdc++.h>
using namespace std;
struct Edge {
  int v1, v2, w;
  Edge(int _v1, int _v2, int _w) {
    v1 = _v1;
    v2 = _v2;
    w = _w;
  }
};
void addEdge(vector<Edge> adj[], int v1, int v2, int w) {
  adj[v1].push_back(Edge(v1, v2, w));
}
vector<int> BellmanFord(int sV, vector<Edge> adj[], int nV) {
  vector<int> res(nV + 1, 1e9);
  res[sV] = 0;
  for (int i = 1;i < nV;i++) {
    for (int j = 1;j <= nV;j++) {
      for (Edge e : adj[j]) res[e.v2] = min(res[e.v2], res[j] + e.w);
    }
  }
  return res;
}
int main() {
  int n, v, v1, v2, w;
  cin >> n >> v;
  vector<Edge> adj[n + 1];
  for (int i = 0;i < v;i++) {
    cin >> v1 >> v2 >> w;
    addEdge(adj, v1, v2, w);
  }
  cin >> v1 >> v2;
  long long res = BellmanFord(v1, adj, n)[v2];
  if (res == 1e9) cout << -1;
  else cout << res;
  return 0;
}
