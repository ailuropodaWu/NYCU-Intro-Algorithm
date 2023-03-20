#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n, cmd[2];
    vector<int> q;
    cin >> n;
    while(n--){
        cin >> cmd[0];
        if(cmd[0] == 3){
            if(!q.empty()){
                cout << q.front();
                q.erase(q.begin());
            }
            else
                cout << "Oh Oh";
            cout << endl;
        }
        else if(cmd[0] == 2){
            stable_sort(q.begin(), q.end(), greater<int>());
        }
        else if(cmd[0] == 1){
            cin >> cmd[1];
            q.push_back(cmd[1]);
        }
    }
    return 0;
}