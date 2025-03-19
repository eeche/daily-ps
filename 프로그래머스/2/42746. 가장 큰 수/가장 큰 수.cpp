#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (int i : numbers) {
        v.push_back(to_string(i));
    }
    sort(v.begin(), v.end(), [](string str1, string str2) {
        return str1 + str2 > str2 + str1;
    });
    
    for (string str : v) {
        answer += str;
    }
    
    if(answer == string(answer.length(), '0'))
        return "0";
    
    return answer;
}