#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    Node(pair<int, int> n){
        data = n;
    }
    pair<int, int> data;
    Node* l = NULL;
    Node* r = NULL;
};
vector<pair<int, int>> Inorder, Postorder;
vector<int> Population;

vector<pair<int, int>> Input(int n);
Node* Construct();
long long Count(Node* root);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        Population.push_back(temp);
    }
    Inorder = Input(n);
    Postorder = Input(n);
    Node* root = Construct();
    cout << Count(root);
    return 0;
}

vector<pair<int, int>> Input(int n){
    vector<pair<int, int>> v;
    pair<int, int> temp;
    for(int i = 0; i < n; ++i){
        cin >> temp.first;
        temp.second = Population[temp.first - 1];
        v.push_back(temp);
    }
    return v;
}

Node* Construct(){
    if(Postorder.size() != Inorder.size())
        return NULL;
    int n = Postorder.size();
    int idx, in, post;
    idx = in = post = n - 1;
    Node* root = NULL;
    stack<Node*> s;
    bool have_l = false;
    while(post >= 0){
        Node* node = NULL;
        do{
            node = new Node(Postorder[post]);
            if(!root)
                root = node;
            if(s.size() > 0){
                if(have_l){
                    have_l = false;
                    s.top()->l = node;
                    s.pop();
                }
                else{
                    s.top()->r = node;
                }
            }
            s.push(node);
        }
        while(Postorder[post--].first != Inorder[in].first);
        node = NULL;
        while(!s.empty() && s.top()->data.first == Inorder[in].first){
            node = s.top();
            s.pop();
            in--;
        }
        if(node){
            s.push(node);
            have_l = true;
        }
    }
    return root;
}

long long Count(Node* root){
    if(!root)
        return 0;
    long long l = 0, r = 0;
    if(root->r){
        if(root->r->data.second > root->data.second)
            r = 1;
        r += Count(root->r);
    }
    if(root->l){
        if(root->l->data.second > root->data.second)
            l = 1;
        l += Count(root->l);
    }
    return l + r;
}