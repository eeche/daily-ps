#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    unordered_map<string, int> name_count;
    
    // participant 배열에서 각 이름의 등장 횟수 세기
    for (const string& name : participant) {
        name_count[name]++;
    }
    
    // completion 배열에서 등장한 선수의 이름을 하나씩 차감
    for (const string& name : completion) {
        name_count[name]--;
    }
    
    // 남은 횟수가 1인 이름을 찾아서 반환
    for (const string& name : participant) {
        if (name_count[name] > 0) {
            answer = name;
        }
    }
    return answer;
}