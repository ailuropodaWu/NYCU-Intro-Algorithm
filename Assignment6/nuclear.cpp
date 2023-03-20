#include <iostream>
#include <vector>
#define big 2000000000
using namespace std;

int short_path(int s_v, vector<vector<pair<int, int>>>& graph, vector<bool>& s_flag, vector<int>& v_w){
    int num = graph.size(), v, ret = big, cost;
    vector<int> path(num, big);
    vector<bool> flag(num, false);
    path[s_v] = v_w[s_v];
    for(int _ = 0; _ < num; ++_){
        cost = big;
        v = -1;
        for(int i = 0; i < num; ++i){
            if(!flag[i] && path[i] < cost){
                cost = path[i];
                v = i;
            }
        }
        if(v == -1)
            break;
        if(s_flag[v]){
            ret = path[v];
            return ret;
        }
        flag[v] = true;
        for(auto p : graph[v]){
            if(!flag[p.first])
                path[p.first] = min(path[p.first], path[v] + p.second + v_w[p.first]);
        }
    }
    for(int i = 0; i < num; ++i){
        if(s_flag[i])
            ret = min(ret, path[i]);
    }
    return (ret == big) ? -1 : ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v_n, e_n, s_n, s_v;
    int temp_v1, temp_v2, temp_w, temp_s;
    vector<int> v_w;
    vector<vector<pair<int, int>>> graph;
    vector<bool> s_flag;
    while(cin >> v_n >> e_n >> s_n){
        v_w.clear();
        graph.clear();
        s_flag.clear();
        graph.resize(v_n);
        for(int _ = 0; _ < v_n; ++_){
            cin >> temp_w;
            v_w.push_back(temp_w);
            s_flag.push_back(false);
        }
        for(int _ = 0; _ < e_n; ++_){
            cin >> temp_v1 >> temp_v2 >> temp_w;
            graph[temp_v1].push_back(pair<int, int>(temp_v2, temp_w));
            graph[temp_v2].push_back(pair<int, int>(temp_v1, temp_w));
        }
        for(int _ = 0; _ < s_n; ++_){
            cin >> temp_s;
            s_flag[temp_s] = true;
        }
        cin >> s_v;
        cout << short_path(s_v, graph, s_flag, v_w) << endl;
    }
    return 0;
}
