#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long A, B;
vector<int> Buildings;

long long renewal(int l, int r){
    int nums = upper_bound(Buildings.begin(), Buildings.end(), r) - lower_bound(Buildings.begin(), Buildings.end(), l);
    int mid = (r + l) / 2;
    if(!nums)
        return A;
  	if(l == r)
      	return B * nums;
    return min((renewal(l, mid) + renewal(mid + 1, r)), B * nums * (r - l + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    int k;
    cin >> n >> k >> A >> B;
    for(int _ = 0; _ < k; ++_){
        cin >> temp;
        Buildings.push_back(temp);
    }
    sort(Buildings.begin(), Buildings.end());
    cout << renewal(1, n);
    return 0;
}