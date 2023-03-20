#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, temp, key; cin >> n;
    bool flag = false;
    vector<int> nums, vec;
    vector<vector<int>> ans;
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        nums.push_back(temp);
    }
    vec.push_back(nums[0]);
    ans.push_back(vec);
    vec.clear();
    for(int i = 1; i < n; ++i){
        key = nums[i];
        if(key > ans.back().back()){
            vec = ans.back();
            vec.push_back(key);
            ans.push_back(vec);
        }
        for(int idx = 1; idx < ans.size(); ++idx){
            if(key > ans[idx - 1].back() && key < ans[idx].back() ||
                (key > ans[idx][ans[idx].size() - 2] && key < ans[idx].back())){
                ans[idx][ans[idx].size() - 1] = key;
            }
        }
        if(key < ans[0][0])
            ans[0][0] = key;
    }
    cout << ans.back().size();
    return 0;
}