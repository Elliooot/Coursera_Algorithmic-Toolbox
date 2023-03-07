#include<iostream>
#include<vector>
using namespace std;
int LCS(vector<int> &s1, vector<int> &s2){
    int k = 0;
    int dp[s1.size() + 1][s2.size() + 1];
    
    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(max(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}
int main(){
    int m, n;
    cin >> m;
    vector<int> s1(m);
    for(int i = 0; i < m; i++){
        cin >> s1[i];
    }
    cin >> n;
    vector<int> s2(n);
    for(int i = 0; i < n; i++){
        cin >> s2[i];
    }
    cout << LCS(s1, s2) << endl;
    return 0;
}
