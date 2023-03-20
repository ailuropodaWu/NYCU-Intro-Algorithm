#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long sum = n, power = 1, temp_power = 1, temp;
    bool flag = false;
    vector<long long> ans;
    while(sum > 1){
        if (k < 0 || k > sum)
            break;
        if(sum % 2 == 1){
            ans.push_back(power);
            k--;
        }
        sum /= 2;
        power *= 2;
        if(sum <= k){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "YES" << endl;
        for(int i = 0; i < 2 * (k - sum); ++i)
            ans.push_back(power / 2);
        for(int i = 0; i < 2 * sum - k; ++i)
            ans.push_back(power);
        sort(ans.begin(), ans.end());
        for(long long& i : ans)
            cout << i << ' ';
    }
    else
        cout << "NO";
    return 0;
}