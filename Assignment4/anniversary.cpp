#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> nums;
    int n, k, temp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums.insert(temp);
    }
    cin >> k;
    long long price = 1, total = 0;
    while(k){
        if(nums.find(price) == nums.end()){
            total += price;
            k--;
        }
        price++;
    }
    cout << total;
    return 0;
}