#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= max_num; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int solution(string numbers) {
    int answer = 0;
    set<int> num_set;
    
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 0; i < numbers.size(); i++) {
            for (int len = 1; len <= numbers.size() - i; len++) {
                int num = stoi(numbers.substr(i, len));
                num_set.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    int max_num = *num_set.rbegin();
    vector<bool> is_prime = sieve(max_num);
    
    for (int num : num_set) {
        if (is_prime[num]) answer++;
    }
    
    return answer;
}