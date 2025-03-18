#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    set<int> unique_nums(nums.begin(), nums.end()); // 고유한 폰켓몬 종류 세기
    
    // 최대 선택할 수 있는 폰켓몬 종류 수는 nums.size() / 2이므로 그 중 작은 값을 리턴
    return min(unique_nums.size(), nums.size() / 2);
}