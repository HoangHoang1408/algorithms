// find all strongly connected components in a graph
// S1: find all finish time in DFS of a vertex in the graph and order the graph by decreasing finish time 
// S2: reverse all the directed edges
// S3: DFS by the order in step 1
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int v1, int v2) {
  adj[v1].push_back(v2);
}
void takeFinishTimeRecur(int sV, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
  visited[sV] = true;
  for (int v : adj[sV]) {
    if (visited[v]) continue;
    takeFinishTimeRecur(v, adj, visited, st);
  }
  st.push(sV);
}
stack<int> takeFinishTime(vector<int> adj[], int nV) {
  int count = 0;
  vector<bool> visited(nV + 1, false);
  stack<int> st;
  for (int i = 1;i <= nV;i++) {
    if (visited[i]) continue;
    takeFinishTimeRecur(i, adj, visited, st);
  }
  return st;
}
void DFS(int sV, vector<vector<int>> adj, vector<bool>& visited) {
  visited[sV] = true;
  cout << sV << " ";
  for (int v : adj[sV]) {
    if (visited[v]) continue;
    DFS(v, adj, visited);
  }
}
vector<vector<int>> reverseEdge(vector<int> adj[], int nV) {
  vector<vector<int>> res(nV + 1);
  for (int i = 1;i <= nV;i++) {
    for (int v : adj[i]) res[v].push_back(i);
  }
  return res;
}

void Kosaraju(vector<int> adj[], int nV) {
  stack<int> st = takeFinishTime(adj, nV);
  vector<vector<int>> newAdj = reverseEdge(adj, nV);
  vector<bool> visited(nV + 1, false);
  while (!st.empty()) {
    int v = st.top();st.pop();
    if (visited[v]) continue;
    DFS(v, newAdj, visited);
    cout << endl;
  }
}

int main() {
  int nV = 7;
  vector<int> adj[nV + 1], finish(nV + 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 1);
  addEdge(adj, 4, 1);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 6);
  addEdge(adj, 6, 7);
  addEdge(adj, 7, 4);
  Kosaraju(adj, nV);
  return 0;
}