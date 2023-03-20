#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> nums;
long long min_to_same(int l, int r){
    long long ret = 0;
    int key = nums[(l + r) / 2];
    for(int i = l; i <= r; ++i)
        ret += abs(key - nums[i]);
    return ret;
}
long long min_good_sequence(int l, int r){
    if(r - l < 2){
        if(nums[l] > nums[r])
            swap(nums[l], nums[r]);
        return 0;
    }
    int middle = (l + r) / 2;
    vector<int> tmp;
    int left = middle - l + 1, right = r - middle;
    int idxl = l, idxr = middle + 1;
    long long  L = min_good_sequence(l, middle), R = min_good_sequence(middle + 1, r);
    L += min_to_same(middle + 1, r);
    R += min_to_same(l, middle);
    while(left || right){
        if(left == 0){
            tmp.push_back(nums[idxr++]);
            --right;
        }
        else if(right == 0){
            tmp.push_back(nums[idxl++]);
            --left;
        }
        else if(nums[idxr] < nums[idxl]){
            tmp.push_back(nums[idxr++]);
            --right;
        }
        else{
            tmp.push_back(nums[idxl++]);
            --left;
        }
    }
    for(int i = 0; i < tmp.size(); ++i){
        nums[l + i] = tmp[i];
    }
    return min(L, R);
}
int main(){
  	ios::sync_with_stdio(0);
  	cin.tie(0);
    int n, temp;
    cin >> n;
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        nums.push_back(temp);
    }
    cout << min_good_sequence(0, n - 1);   
    return 0;
}