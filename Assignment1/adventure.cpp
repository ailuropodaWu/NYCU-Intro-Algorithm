#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            if(a[2] == b[2]){
                if(a[3] == b[3])
                    return false;
                else
                    return a[3] > b[3];
            }
            else
                return a[2] > b[2];
        }
        else
            return a[1] > b[1];
    }
    else
        return a[0] > b[0];
}
int main() {
    int n, target, tmp, arr[300];
    int left, right;
    vector<vector<int>> ans;
    vector<int> temp(4);
    cin >> n >> target;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n - 3; ++i){
        for(int j = i + 1; j < n - 2; ++j){
            left = j + 1;
            right = n - 1;
        	tmp = target - arr[i] - arr[j];
            while(left < right){
                if(arr[right] + arr[left] > tmp){
                    --right;
                  	continue;
                }
                else if(arr[right] + arr[left] < tmp){
                    ++left;
                  	continue;
                }
                else{
                    temp[0] = arr[i];
                    temp[1] = arr[j];
                    temp[2] = arr[left];
                    temp[3] = arr[right];
                    ans.push_back(temp);
                    ++left;
                    --right;
                  	continue;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size()){
      	cout << unique(ans.begin(), ans.end()) - ans.begin();
    }
  	else cout << "FeiDooDoo_Zuo_Wei_Men";
    return 0;
}