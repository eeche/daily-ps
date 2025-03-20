#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, job_done = 0, idx = 0;
    int job_counts = jobs.size();
    
    sort(jobs.begin(), jobs.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(job_done < job_counts) {
        while (idx < job_counts && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        if (pq.empty()) {
            time = jobs[idx][0];
        } else {
            pair<int, int> current = pq.top();
            pq.pop();
            
            int duration = current.first;
            int request = current.second;
            
            time += duration;
            
            answer += (time - request);
            
            job_done++;
        }
    }
    return answer/job_counts;
}