#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, total_weight = 0, idx = 0; 
    queue<int> bridge;
    
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    while (!bridge.empty()) {
        answer++;
        
        total_weight -= bridge.front();
        bridge.pop();
        
        if (idx < truck_weights.size()) {
            if (total_weight + truck_weights[idx] <= weight) {
                bridge.push(truck_weights[idx]);
                total_weight += truck_weights[idx];
                idx ++;
            } else {
                bridge.push(0);
            }
        }
    }
    
    return answer;
}