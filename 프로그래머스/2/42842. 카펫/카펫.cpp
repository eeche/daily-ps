#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i * i <= yellow; i++) {
        if (yellow % i == 0) {
            int width = yellow / i + 2, height = i + 2;
            
            if (brown == (width * height) - yellow) {
                return {width, height};
            }
        }
    }
    
    return answer;
}