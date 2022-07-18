// apply for all kinds of graph except negative-weighted graph
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
struct Compare {
  bool operator()(Edge a, Edge b) {
    return a.w > b.w;
  }
};

vector<long long> Dijstra(int sV, vector<Edge> adj[], int nV) {
  vector<long long> res(nV + 1, 1e15);
  priority_queue<Edge, vector<Edge>, Compare> pq;
  res[sV] = 0;
  pq.push(Edge(sV, sV, 0));
  while (!pq.empty()) {
    Edge tE = pq.top();
    pq.pop();
    for (Edge e : adj[tE.v2]) {
      if (res[e.v2] <= res[tE.v2] + e.w) continue;
      res[e.v2] = res[tE.v2] + e.w;
      pq.push(e);
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
  long long res = Dijstra(v1, adj, n)[v2];
  if (res == 1e15) cout << -1;
  else cout << res;
  return 0;
}