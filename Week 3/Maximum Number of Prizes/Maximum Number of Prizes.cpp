#include<iostream>
#include<vector>

using namespace std;

vector<int> sol(int n){
    vector<int> p;
    for(int i = 1; i + 1 <= n - i; i++){
        p.push_back(i);
        n -= i;
    }
    if(n) p.push_back(n);
    return p;
}

int main(){
    int n;
    cin >> n;
    vector<int> ans = sol(n);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
