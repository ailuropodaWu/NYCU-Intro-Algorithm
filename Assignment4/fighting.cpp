#include <iostream>
#include <vector>
#define BIG 100000
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int temp;
    vector<int> nums, ans;
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        nums.push_back(temp);
        ans.push_back(BIG);
    }
    ans[0] = 0;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(j + nums[j] >= i){
                temp = ans[j] + 1;
                ans[i] = min(temp, ans[i]);
            }
        }
    }
    cout << ans.back();
    return 0;
}