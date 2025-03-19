#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    int n = citations.size();
    
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n-i) {
            answer = n-i;
            break;
        }
    }
    return answer;
}