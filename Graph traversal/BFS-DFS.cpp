#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[], int nV, int sV) {
  vector<bool> visited(nV + 1, false);
  queue<int> q;
  q.push(sV);
  visited[sV] = true;
  while (!q.empty()) {
    int front = q.front();q.pop();
    cout << front << " ";
    for (int v : adj[front]) {
      if (visited[v] == 1) continue;
      visited[v] = true;
      q.push(v);
    }
  }
  cout << endl;
}
void test(vector<bool> t) {
  for (auto x : t) cout << x << " ";
  cout << endl;
}
void DFS(vector<int> adj[], int sV, vector<bool>& visited) {
  cout << sV << " ";
  visited[sV] = true;
  for (int v : adj[sV]) {
    if (visited[v]) {
      continue;
    }
    DFS(adj, v, visited);
  }
}

void addEdge(vector<int> adj[], int v1, int v2) {
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}
int main() {
  int n = 8;
  vector<int> adj[n + 1];
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 7);
  addEdge(adj, 4, 7);
  addEdge(adj, 5, 6);
  addEdge(adj, 3, 6);
  addEdge(adj, 6, 8);
  bfs(adj, n, 1);
  vector<bool> visited(n + 1, false);
  DFS(adj, 1, visited);
  return 0;
}