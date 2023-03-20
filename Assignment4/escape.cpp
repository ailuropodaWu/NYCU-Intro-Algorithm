#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b){
    string s1 = a + b, s2 = b + a;
    if(s1 == s2)
        return false;
    else if (s1 > s2)
        return true;
    else
        return false;
}
int main() {
    int n; cin >> n;
    vector<string> nums;
    string temp, total = "";
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end(), cmp);
    for(string& s : nums)
        total += s;
    if(total[0] == '0')
        total = "0";
    cout << total;
    return 0;
}