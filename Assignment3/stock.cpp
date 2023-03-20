#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    long long ans = 0, temp, min, max;
    vector<long long> nums;
    nums.push_back(0);
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums.push_back(nums[i] + temp);
    }
    for(int j = n; j >= 0; --j){
        min = nums[0];
        max = nums[0];
        for(int i = 1; i < j; ++i){
            min = (nums[i] < min) ? nums[i] : min;
            max = (nums[i] > max) ? nums[i] : max;
        }
        if(abs(nums[j] - max) > abs(nums[j] - min))
            ans = (abs(nums[j] - max) > ans) ? abs(nums[j] - max) : ans;
        else
            ans = (abs(nums[j] - min) > ans) ? abs(nums[j] - min) : ans;
    }
    cout << ans;
    return 0;
}