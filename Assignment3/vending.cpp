#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define BIG 1000000000000000000

using namespace std;




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> coins;
    int n, q, idx = 0;
    cin >> n;
    long long temp, amount, max = 0, min = BIG;
    vector<long long> ans, buffer(100001);
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        coins.push_back(temp);
    }
    cin >> q;
    for(int _ = 0; _ < q; ++_){
        cin >> amount;
        for(int i = 0; i < n; ++i){
            cin >> temp;
            amount -= coins[i] * temp;
        }
        amount *= -1;
        max = amount > max ? amount : max;
        ans.push_back(amount);
    }
    sort(coins.begin(), coins.end());
    buffer[0] = 0;
    for(int i = 1; i <= max; ++i){
        if(i == coins[idx]){
            buffer[i] = 1;
            idx++;
        }
        else if(i >= coins[idx]){
            min = INT_MAX;
            for(int j = 0; j < n; ++j){
                if(coins[j] > i)
                    break;
                temp = 1 + buffer[i - coins[j]];
                min = temp < min ? temp : min;
            }
            buffer[i] = min;
        }
    }
    
    for(long long i : ans){
        cout << buffer[i] << endl;
    }
    return 0;
}