#include <bits/stdc++.h>
using namespace std;

set<int> visited;
int mx = 0;

int f(vector<vector<int>>& graph, int x) {
    if(visited.find(x) != visited.end()) return 0;
    visited.insert(x);
    if(graph[x].empty()) return 0;
    vector<int> diameter;
    for(int node: graph[x]) {
        if(visited.find(node) != visited.end()) continue;
        int temp = 1 + f(graph, node);
        diameter.push_back(temp);
    }
    sort(diameter.begin(), diameter.end());
    int l = diameter.size();
    if(l > 1) 
        mx = max(mx, diameter[l-1] + diameter[l-2]);
    else if(l == 1)
        mx = max(mx, diameter[l-1]);
    // mx = max(mx, longest_diameter);
    if(l>0) return diameter[l-1];
    else return 0;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1);
    for(int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        indegree[y]++;
    }
    int root = -1;
    // find root
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            root = i;
            break;
        }
    }
    int return_val = f(graph, root);
    cout << mx << "\n";
}