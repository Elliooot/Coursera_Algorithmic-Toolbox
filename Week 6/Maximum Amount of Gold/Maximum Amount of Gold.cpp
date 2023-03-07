#include<iostream>
#include<vector>

using namespace std;

int maxWeight(vector<int> w, int W){
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(w[i-1] <= j){
                if((dp[i-1][j-w[i-1]] + w[i-1]) > dp[i][j])
                    dp[i][j] = dp[i-1][j-w[i-1]] + w[i-1];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int W, n;
    cin >> W >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    cout << maxWeight(w, W) << endl;
    return 0;
}
