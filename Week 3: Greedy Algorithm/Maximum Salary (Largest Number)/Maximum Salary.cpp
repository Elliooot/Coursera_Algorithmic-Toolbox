#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

bool isBetter(int c, int max){
    if(max == INT8_MIN) return true;
    int c_bits = 0, max_bits = 0, a, b, C = c, Max = max;
    while(c){
        c_bits++;
        c /= 10;
    }
    while(max){
        max_bits++;
        max /= 10;
    }
    a = C * pow(10, max_bits) + Max;
    b = Max * pow(10, c_bits) + C;
    if(a > b) return true;
    else return false;
}

vector<int> max_salary(vector<int> &v){
    vector<int> u;
    while(!v.empty()){
        int max = INT8_MIN;
        int k;
        for(int i = 0; i < v.size(); i++){
            if(isBetter(v[i], max)){
                max = v[i];
                k = i;
            }
        }
        swap(v[k], v[v.size() - 1]);
        u.push_back(max);
        v.pop_back();
    }
    return u;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> ans = max_salary(v);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    return 0;
}
