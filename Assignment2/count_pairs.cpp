#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long ans = 0;
    long long temp, L, R;
    long long l, r;
    vector<long long> nums;
    cin >> n >> L >> R;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; ++i){
        l = ((L % nums[i]) == 0) ? L / nums[i] : L / nums[i] + 1;
        r = R / nums[i];
        ans += upper_bound(nums.begin() + i + 1, nums.end(), r) - 
                lower_bound(nums.begin() + i + 1, nums.end(), l);
    }
    cout << ans;
    return 0;
}