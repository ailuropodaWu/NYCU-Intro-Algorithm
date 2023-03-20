#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n; cin >> n;
    long long temp;
    vector<long long> nums;
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        nums.push_back(temp);
    }
    nums.push_back(0);
    for(int i = 2; i <= n; ++i){
        nums[i] += (nums[i - 1] < nums[i - 2]) ? nums[i - 1] : nums[i - 2];
    }
    cout << nums[n];
    return 0;
}