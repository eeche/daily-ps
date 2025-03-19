#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothes_map;
    
    for (const auto& v : clothes) {
        string key = v[1];
        clothes_map[key]++;
    }
    
    for (const auto& pair : clothes_map) {
        answer = answer * (pair.second+1);
    }
    /*
    그리고 두번째 인자의 종류마다 갯수를 구함 그리고 갯수 + 1을 곱하고 - 1을 함
    */
    return answer - 1;
}