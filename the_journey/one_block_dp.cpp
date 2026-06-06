#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long OneBlock(int N, vector<int> Arr) {
    unordered_map<long long, long long> mp;

    long long prefixSum = 0;

    // dp[0] = 1
    // Before starting, prefix sum is 0 and there is 1 way
    mp[0] = 1;

    long long ways = 0;

    for (int i = 0; i < N; i++) {
        prefixSum += Arr[i];

        // We need previous prefix sum = current prefix sum - 1
        ways = mp[prefixSum - 1];

        // Store ways to partition till this index
        mp[prefixSum] += ways;
    }

    if (ways == 0) return -1;
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> Arr(N);
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }

    cout << OneBlock(N, Arr);

    return 0;
}