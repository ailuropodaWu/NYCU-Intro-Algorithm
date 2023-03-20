#include <iostream>
#include <vector>

using namespace std;

int main() {
    int time_n, stu_n, cap, cmb;
    int temp_t, index, t;
    vector<vector<int>> student;
    while(cin >> time_n >> stu_n >> cap >> cmb){
        student.resize(stu_n);
        for(int _ = 0; _ < stu_n; ++_){
            cin >> index >> t;
            for(int __ = 0; __ < t; ++__){
                cin >> temp_t;
            }
        }
        for(int _ = 0; _ < cmb; ++_){
            cin >> t;
            for(int __ = 0; __ < t; ++__){
                cin >> temp_t;
            }
        }
    }
    return 0;
}