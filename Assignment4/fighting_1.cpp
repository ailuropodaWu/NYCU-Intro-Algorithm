#include <iostream>
#include <vector>
#define BIG 100000

using namespace std;

int main() {
    int n; cin >> n;
    int temp;
    vector<int> nums, ans;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums.push_back(temp);
        ans.push_back(BIG);
    }
    int l = 1, r = nums[0], max = 0, max_i = -1, step = 0;
    bool stop = false;
    ans[0] = step;
    while(1){
        if(r >= n - 1){
            stop = true;
            r = n - 1;
        }
        for(int i = l; i <= r; ++i){
            if((i + nums[i]) > max){
                max_i = i;
                max = i + nums[i];
            }
        }
        l = r + 1;
        r = max_i + nums[max_i]; 
        step++;
        if(stop)
            break;
    }
    cout << step;
    return 0;
}