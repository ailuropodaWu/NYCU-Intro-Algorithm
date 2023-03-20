#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a = 0, b = 0;
    cin >> n;
    long long total = 0;
    pair<int, int> temp;
    vector<pair<int, int>> cost, diff;
    for(int i = 0; i < n; ++i){
        cin >> temp.first;
        cin >> temp.second;
        int t = abs(temp.first - temp.second);
        cost.push_back(temp);
        diff.push_back(pair<int, int>(t, i));
    }
    sort(diff.begin(), diff.end());
    for(int i = n - 1; i >= 0; --i){
        int idx = diff[i].second;
        if(a > n / 2 - 1){
            total += cost[idx].second;
        }
        else if(b > n / 2 - 1){
            total += cost[idx].first;
        }
        else if(cost[idx].first < cost[idx].second){
            ++a;
            total += cost[idx].first;
        }
        else{
            ++b;
            total += cost[idx].second;
        }
    }
    cout << total;
    return 0;
}