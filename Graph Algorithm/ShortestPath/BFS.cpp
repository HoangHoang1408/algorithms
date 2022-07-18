// for directed unweighted graph
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
vector<int> TopoSort(vector<Edge> adj[], int nV) {
  vector<int> inDegrees(nV + 1, 0), res;
  for (int i = 1;i <= nV;i++) {
    for (Edge e : adj[i]) inDegrees[e.v2] += 1;
  }
  queue<int> q;
  for (int i = 1;i <= nV;i++) {
    if (inDegrees[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int fV = q.front();q.pop();
    res.push_back(fV);
    for (Edge e : adj[fV]) {
      inDegrees[e.v2] -= 1;
      if (inDegrees[e.v2] == 0) q.push(e.v2);
    }
  }
  return res;
}
vector<int> shortestPathUsingDFS(vector<Edge> adj[], int nV) {
  vector<int> res(nV + 1, 1e9);
  vector<int> temp = TopoSort(adj, nV);
  res[1] = 0;
  for (int v : temp) {
    for (Edge e : adj[v]) {
      if (e.w + res[v] < res[e.v2]) res[e.v2] = e.w + res[v];
    }
  }
  return res;
}
int main() {
  int n = 6;
  vector<Edge> adj[n + 1];
  addEdge(adj, 1, 2, 1);
  addEdge(adj, 1, 3, 2);
  addEdge(adj, 2, 4, 3);
  addEdge(adj, 2, 3, 3);
  addEdge(adj, 3, 4, 2);
  addEdge(adj, 3, 5, 5);
  addEdge(adj, 4, 5, 3);
  addEdge(adj, 4, 6, 6);
  addEdge(adj, 5, 6, 4);
  for (int d : shortestPathUsingDFS(adj, n)) {
    cout << d << " ";
  }
  return 0;
}