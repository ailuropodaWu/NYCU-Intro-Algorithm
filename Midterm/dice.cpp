#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, target;
    cin >> n >> k >> target;
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            for(int idx = j; idx <= target; ++idx){
                dp[i][idx] = (dp[i][idx] + dp[i - 1][idx - j]) % 1000000007;
            }
        }
    }
    cout << dp[n][target];
    return 0;
}