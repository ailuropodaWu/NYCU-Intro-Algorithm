#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, k, temp;
    int idx1 = 0, idx2 = 0, temp_1, temp_2;
    cin >> m >> n >> k;
    vector<int> num1, num2, ans;
    for(int _ = 0; _ < m; ++_){
        cin >> temp;
        num1.push_back(temp);
    }
    for(int _ = 0; _ < n; ++_){
        cin >> temp;
        num2.push_back(temp);
    }
    int s = m + n - k;
    for(int i = 1; i <= k; ++i){
        temp_1 = idx1;
        temp_2 = idx2;
        int max = -1;
        for(int a = idx1; a < min(m, s + i - idx2); ++a){
            if(num1[a] > max){
                max = num1[a];
                temp_1 = a + 1;
            }
        }
        for(int a = idx2; a < min(n, s + i - idx1); ++a){
            if(num2[a] > max){
                max = num2[a];
                temp_2 = a + 1;
                temp_1 = idx1;
            }
        }
        idx1 = temp_1;
        idx2 = temp_2;
        ans.push_back(max);
    }
    for(int i : ans)
        cout << i << ' ';
    return 0;
}