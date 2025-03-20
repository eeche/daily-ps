#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int n, vector<vector<int>>& graph, vector<bool>& visited, int exclude) {
    int count = 1;
    visited[n] = true;
    for (int next : graph[n]) {
        if (next != exclude && !visited[next]) {
            count += dfs(next, graph, visited, exclude);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> graph(n + 1);
    
    for (auto& wire : wires) {
        int v1 = wire[0], v2 = wire[1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    for (auto& wire : wires) {
        int v1 = wire[0], v2 = wire[1];
        vector<bool> visited(n + 1, false);
        
        int count = dfs(v1, graph, visited, v2);
        
        int diff = abs(n - 2 * count);
        answer = min(answer, diff);
    }
    
    return answer;
}