#include <bits/stdc++.h>
using namespace std;

vector<int> s(200005);
set<int> visited;

int f(vector<vector<int>>&graph, int x) {
    if(visited.find(x) != visited.end()) 
        return 0;
    visited.insert(x);
    if(graph[x].empty())
        return 0;
    for(int node: graph[x]) {
        s[x] += 1 + f(graph, node);
    }
    return s[x];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for(int i = 2; i <= n; i++) {
        int temp;
        cin >> temp;
        graph[temp].push_back(i);
    }
    s[1] = f(graph, 1);
    
    for(int i = 1; i <= n; i++)
        cout << s[i] << " ";
    cout << "\n";
}