#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> music_map;
    unordered_map<string, vector<pair<int, int>>> songs_by_genre;
    
    for (int i=0; i<genres.size(); i++) {
        music_map[genres[i]] += plays[i];
        songs_by_genre[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sorted_genres(music_map.begin(), music_map.end());
    sort(sorted_genres.begin(), sorted_genres.end(), [](const pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second;
    });
    
    for (auto& genre : sorted_genres) {
        string genre_name = genre.first;
        
        sort(songs_by_genre[genre_name].begin(), songs_by_genre[genre_name].end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second) return a.first < b.first; // 재생 횟수가 같다면 고유 번호 기준 정렬
                return a.second > b.second; // 재생 횟수 기준 내림차순 정렬
            });
        int cnt = 0;
        for (auto& song : songs_by_genre[genre_name]) {
            answer.push_back(song.first);
            if (++cnt == 2) break;
        }
    }
    // 각 장르별 재생 횟수 전부 구하고 많은 장르의 오름차순으로 정렬해서 고유 번호 입력, 
    return answer;
}