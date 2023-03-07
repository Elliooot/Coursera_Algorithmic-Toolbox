#include<iostream>
#include<vector>

using namespace std;

int LCS(vector<int> &s1, vector<int> &s2, vector<int> &s3){
    int k = 0;
    int dp[s1.size() + 1][s2.size() + 1][s3.size() + 1];
    
    for(int i = 0; i <= s1.size(); i++){
        for(int j = 0; j <= s2.size(); j++){
            for(int k = 0; k <= s3.size(); k++){
                if(i == 0 || j == 0 || k == 0){
                    dp[i][j][k] = 0;
                }else if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }else{
                    dp[i][j][k] = max(max(max(dp[i][j][k-1], dp[i][j-1][k]), dp[i-1][j][k]), dp[i-1][j-1][k]);
                }
            }
        }
    }
    return dp[s1.size()][s2.size()][s3.size()];
}

int main(){
    int m, n, l;
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
    cin >> l;
    vector<int> s3(l);
    for(int i = 0; i < l; i++){
        cin >> s3[i];
    }
    cout << LCS(s1, s2, s3) << endl;
    return 0;
}
