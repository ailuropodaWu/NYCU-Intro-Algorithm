#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n, k, temp;
    cin >> n >> k;
    map<int, int> list, ans;
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        list[temp]++;
    }
    for(pair<int, int> temp : list)
        ans[temp.second] = temp.first;
    map<int, int>::iterator it = ans.end();
    for(int _ = 0; _ < k; ++_)
        it--;
    cout << it->second;
    return 0;
}