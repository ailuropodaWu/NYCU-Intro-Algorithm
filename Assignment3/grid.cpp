#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<long long>> grid(m);
    for(vector<long long>& v : grid)
        v.resize(n);
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            if(r == 0 || c == 0)
                grid[r][c] = 1;
            else
                grid[r][c] = grid[r - 1][c] + grid[r][c - 1];
        }
    }
    cout << grid[m - 1][n - 1];
    return 0;
}