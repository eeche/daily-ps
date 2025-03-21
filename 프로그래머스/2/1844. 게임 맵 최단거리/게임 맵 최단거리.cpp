#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int ns = maps.size();
    int ms = maps[0].size();
    
    vector<vector<bool>> visited(ns, vector<bool>(ms, false));
    vector<vector<int>> dist (ns, vector<int>(ms, -1));
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;
    
    while (!q.empty()) {
        
        auto [cy, cx] = q.front();
        q.pop();
        
        if (cy == ns - 1 && cx == ms - 1) {
            return dist[cy][cx];
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= ns || nx < 0 || nx >= ms) continue;
            if (maps[ny][nx] == 0 || visited[ny][nx]) continue;
            
            visited[ny][nx] = true;
            dist[ny][nx] = dist[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
    
    return -1;
}