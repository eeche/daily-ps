#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int n, vector<vector<int>>& wires, vector<bool>& visited) {
    int count = 1;
    visited[n] = true;
    for (int i : wires[n]) {
        if (!visited[i]) {
            count += dfs(i, wires, visited);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> graph(n + 1);
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            
            int v1 = wires[j][0];
            int v2 = wires[j][1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        vector<bool> visited(n + 1, false);
        int size1 = dfs(1, graph, visited);
        
        int size2 = n - size1;
        
        int diff = abs(size1 - size2);
        answer = min(answer, diff);
    }
    
    return answer;
}