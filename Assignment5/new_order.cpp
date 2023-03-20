#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int v1, v2, w;
    edge(int a, int b, int c){
        v1 = a; v2 = b; w = c;
    }
};

int find_parent(vector<int>& p, int i){
    if(p[i] == -1)
        return i;
    return find_parent(p, p[i]);
}

int kruscal(vector<edge*>edges, vector<int>& parent, int remain_e){
    int sum = 0;
    int p1, p2;
    for(edge* e : edges){
        if(remain_e == 0)
            break;
        p1 = find_parent(parent, e->v1);
        p2 = find_parent(parent, e->v2);
        if(p1 == p2)
            continue;
        parent[p1] = p2;
        sum += e->w;
        remain_e--;
    }
    return (remain_e > 0) ? -1 : sum;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v_num, e_num, o_num;
    int temp_v1, temp_v2, temp_w, temp_o;
    int temp_sum, sum;

    vector<edge*> edges, o_edges, v_edges;
    vector<int> parent;
    vector<bool> is_o;
    while(cin >> v_num >> e_num >> o_num){
        sum = temp_sum = 0;
        edges.clear(); o_edges.clear(), v_edges.clear();
        parent.resize(v_num); is_o.resize(v_num);
        for(int i = 0; i < v_num; ++i){
            parent[i] = -1;
            is_o[i] = false;
        }

        for(int _ = 0; _ < e_num; ++_){
            cin >> temp_v1 >> temp_v2 >> temp_w;
            edge* temp_edge = new edge(temp_v1, temp_v2, temp_w);
            edges.push_back(temp_edge);
        }

        for(int _ = 0; _ < o_num; ++_){
            cin >> temp_o;
            is_o[temp_o] = true;
        }

        for(edge* e : edges){
            if(is_o[e->v1] || is_o[e->v2])
                o_edges.push_back(e);
            else
                v_edges.push_back(e);
        }
        
        sort(o_edges.begin(), o_edges.end(), [](edge* a, edge* b){return a->w < b->w;});
        sort(v_edges.begin(), v_edges.end(), [](edge* a, edge* b){return a->w < b->w;});

        temp_sum = kruscal(v_edges, parent, v_num - o_num - 1);
        if(temp_sum == -1){
            cout << -1 << endl;
            continue;
        }
        else
            sum = temp_sum;
        temp_sum = kruscal(o_edges, parent, (v_num == o_num) ? o_num - 1 : o_num);
        if(temp_sum == -1){
            cout << -1 << endl;
            continue;
        }
        else
            sum += temp_sum;
        cout << sum << endl;
    }
    return 0;
}