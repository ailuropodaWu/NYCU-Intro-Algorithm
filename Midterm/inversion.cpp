#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
long long count(int l, int r){
    if(l == r)
        return 0;
    if(l == r - 1){
        if(v[l] > v[r]){
            swap(v[l], v[r]);
            return 1;
        }
        return 0;
    }
    int mid = (l + r) / 2;
    long long cnt_l = count(l, mid);
    long long cnt_r = count(mid + 1, r);
    long long cnt = 0;
    int idx = mid + 1;
    for(int i = l; i <= mid; ++i){
        while(idx <= r && v[idx] < v[i])
            ++idx;
        cnt += idx - mid - 1;
    }
	vector<int> first, second;
	for (int k = l; k <= mid; k++)first.push_back(v[k]);
	for (int k = mid + 1; k <= r; k++)second.push_back(v[k]);
	merge(first.begin(), first.end(), second.begin(), second.end(), v.begin() + l);
    return cnt_l + cnt_r + cnt;
}
int main() {
    int n;
	while (cin >> n) {
		v.clear();
		for (int _ = 0; _ < n; ++_) {
			int t;
			cin >> t;
			v.push_back(t);
		}
		cout << count(0, n - 1) << endl;
	}
    return 0;
}