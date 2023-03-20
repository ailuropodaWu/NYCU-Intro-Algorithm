#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
#define big 1000
using namespace std;

int shortest(int s_v, vector<vector<int>>& graph){
    int num = graph.size();
    int v, ret = -1;
    vector<int> path(num, big);
    vector<bool> flag(num, false);
    queue<int> q;
    path[s_v] = 0;
    flag[s_v] = true;
    q.push(s_v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        flag[v] = true;
        for(auto i : graph[v]){
            path[i] = min(path[i], path[v] + 1);
            if(!flag[i])
                q.push(i);
        }
    }
    for(int i : path){
        ret = max(ret, i);
    }
    return ret;
}

int index(string s, unordered_map<string, int>& m, int& i){
    if(m.find(s) == m.end()){
        m.insert(pair<string, int>(s, i++));
    }
    return m[s];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string temp_v1, temp_v2;
    vector<vector<int>> friends(500);
    unordered_map<string, int> users_i;
    while(cin >> n){
        int ans = big, num = 0;
        friends.clear(); users_i.clear();
        friends.resize(500);
        for(int _ = 0; _ < n; ++_){
            cin >> temp_v1 >> temp_v2;
            friends[index(temp_v1, users_i, num)].push_back(index(temp_v2, users_i, num));
            friends[index(temp_v2, users_i, num)].push_back(index(temp_v1, users_i, num));
        }
        friends.resize(num);
        ans = shortest(0, friends);
        for(int i = 1; i < num; ++i){
            ans = max(ans, shortest(i, friends));
        }
        //ans = short_path(friends);
        if(ans == big)
            ans = -1;
        
        cout << ans << endl;
    }
    return 0;
}