#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct member{
    string name;
    int score[4] = {0};
};
bool cmp(member* a, member* b){
    if(a->score[0] != b->score[0]) return a->score[0] > b->score[0];
    else if(a->score[1] != b->score[1])	return a->score[1] > b->score[1];
    else if(a->score[2] != b->score[2])	return a->score[2] > b->score[2];
    else if(a->score[3] != b->score[3])	return a->score[3] > b->score[3];
    else if (a->name != b-> name) return a->name < b->name;
    else return false;
}

class Group{
    
private:
    vector<member*> members;
    int order[4];
    char group_name;
public:
    Group(char c, string order){
        group_name = c;
        members.clear();
        for(int i = 0; i < 4; ++i){
            switch (order[i]){
            case 'H':
                this->order[i] = 0;
                break;
            case 'W':
                this->order[i] = 1;
                break;
            case 'I':
                this->order[i] = 2;
                break;
            case 'E':
                this->order[i] = 3;
                break;
            }
        }
    }

    void Add_member(member* t){
        int temp[4];
        for(int i = 0; i < 4; ++i)
            temp[i] = t->score[order[i]];
        for(int j = 0; j < 4; ++j)
            t->score[j] = temp[j];
        members.push_back(t);
    }

    void Sort(){
        sort(members.begin(), members.end(), cmp);
        return;
    }

    void Print(){
        cout << "Group " << group_name << ":";
        if(members.empty())
            cout << " No Audience";
        cout << endl;
        for(member*& t : members)
            cout << t->name << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string order;
    vector<Group> ans;
    cin >> n;
    for(int i = 0; i < 4; ++i){
        cin >> order;
        Group temp('A' + i, order);
        ans.push_back(temp);
    }
    for(int _ = 0; _ < n; ++_){
        member* temp;
        temp = new member;
        cin >> temp->name;
        for(int i = 0; i < 4; ++i)
            cin >> temp->score[i];
        int max_score = temp->score[0], max_index = 0;
        for(int i = 1; i < 4; ++i){
            if(temp->score[i] > max_score){
                max_score = temp->score[i];
                max_index = i;
            }
        }
        ans[max_index].Add_member(temp);
    }
    for(int i = 0; i < 4; ++i){
        ans[i].Sort();
        ans[i].Print();
    }
    return 0;
}