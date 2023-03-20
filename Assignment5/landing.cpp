#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> grid;
const char grass = '_', tree = '^';

int bfs(int i, int j){
    if(grid[i][j] == tree)
        return 0;
    int num = 0, a, b;
    queue<pair<int, int>> check;
    pair<int, int> temp;
    check.push(pair<int, int>(i, j));
    while(!check.empty()){
        temp = check.front();
        check.pop();
        a = temp.first;
        b = temp.second;
        if(a < 0 || a > grid.size() - 1 ||
            b < 0 || b > grid.size() - 1 ||
            grid[a][b] == tree)
            continue;
        num++;
        grid[a][b] = tree;
        check.push(pair<int, int>(a + 1, b));
        check.push(pair<int, int>(a - 1, b));
        check.push(pair<int, int>(a, b + 1));
        check.push(pair<int, int>(a, b - 1));
    }
    return num;
}
int main() {
    int n; cin >> n;
    int l, r, mid, ans;
    string temp;
    for(int __ = 0; __ < n; ++__){
        grid.clear();
        cin >> l >> r;
        ans = 0;
        mid = l / 2;
        for(int _ = 0; _ < l; ++_){
            cin >> temp;
            grid.push_back(temp);
        }
        for(int i = mid - r; i <= mid + r; ++i){
            for(int j = mid - r; j <= mid + r; ++j){
                ans = max(ans, bfs(i, j));
            }
        }
        cout << ans << endl;
    }
    return 0;
}