#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> sol(m);
    for(vector<int>& v : sol)  
        v.resize(n + 1);
    for(int r = 0; r <= m; ++r){
        for(int c = 0; c <= n; ++c){
            if(r == 0 || c == 0)
                sol[r][c] = 0;
            else
                sol[r][c] = (nums1[r - 1] == nums2[c - 1]) ? sol[r - 1][c - 1] + 1 : max(sol[r][c - 1], sol[r - 1][c]);
        }
    }
    return sol[m][n];
}
int main() {
    int n, temp; cin >> n;
    vector<int> nums, sort_nums;
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        nums.push_back(temp);
    }
    sort_nums = nums;
    sort(sort_nums.begin(), sort_nums.end());
    for(int i = sort_nums.size() - 1; i; --i){
        if(sort_nums[i] == sort_nums[i - 1]){
            sort_nums.erase(sort_nums.begin() + i);
        }
    }
    
    cout << LCS(nums, sort_nums);
    return 0;
}