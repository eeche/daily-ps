#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    int answer = 0;
    vector<vector<int>> is_rectangle(101, vector<int>(101, 0));
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    vector<vector<int>> dist(101, vector<int>(101, -1));
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    for (int i =0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0] * 2; j <= rectangle[i][2] * 2; j++) {
            for (int k = rectangle[i][1] * 2; k <= rectangle[i][3] * 2; k++) {
                is_rectangle[j][k] = 1;
            }
        }
    }
    
    for (int i =0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0] * 2 + 1; j < rectangle[i][2] * 2; j++) {
            for (int k = rectangle[i][1] * 2 + 1; k < rectangle[i][3] * 2; k++) {
                is_rectangle[j][k] = 0;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    visited[characterX][characterY] = true;
    dist[characterX][characterY] = 0;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        if (cx == itemX && cy == itemY) {
            return dist[cx][cy] / 2;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
            if (is_rectangle[nx][ny] == 0 || visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    
    return -1;
}