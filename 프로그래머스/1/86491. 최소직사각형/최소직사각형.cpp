#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int x = 0, y = 0;
    
    for (vector<int> size : sizes) {
                
        x = max(x, max(size[0], size[1]));
        y = max(y, min(size[0], size[1]));
    }
    return x*y;
}