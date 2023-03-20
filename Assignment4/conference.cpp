#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    int s, f;
    pair<int, int> temp;
    vector<pair<int, int>> ans;
    map<int, int> nums;
    for(int i = 0; i < n; ++i){
        cin >> s;
        cin >> f;
        if(s > f)
            continue;
        if(nums.find(f) == nums.end() || nums[f] < s)
            nums[f] = s;        
    }
    map<int, int>::iterator it;
    for(it = nums.begin(); it != nums.end(); ++it){
        temp.first = it->second;
        temp.second = it->first;
        if(ans.empty())
            ans.push_back(temp);
        else if(temp.first >= ans.back().second)
            ans.push_back(temp);
    }
    for(auto p : ans)
        cout << p.first << ' ' << p.second << endl;
    return 0;
}