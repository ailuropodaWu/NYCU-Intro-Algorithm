#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp, temp_sum = 0;
    map<int, int> ans;
    cin >> n;
    for(int _ = 0; _ < n; ++_){
        temp_sum = 0;
        for(int i = 0; i < 5; ++i){
            cin >> temp;
            temp_sum += temp;
        }
        ++ans[temp_sum];
    }
    map<int, int>::reverse_iterator rit;
    for(rit = ans.rbegin(); rit < ans.rend(); ++rit){
        for(int _ = 0; _ < rit->second; ++_)
            cout << rit->second << endl;
    }
    return 0; 
}