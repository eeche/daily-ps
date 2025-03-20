#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count) {
    answer = max(answer, count);
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, visited, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, visited, 0);
    return answer;
}