#include<iostream>
#include<vector>

using namespace std;

int DPMoneyChange(int n, vector<int> &coins){
    vector<int> temp(n+1);
    temp[0] = 0;
    for(int i = 1; i <= n; i++){
        temp[i] = INT32_MAX;
        for(int j = 0; j < coins.size(); j++){
            if(i >= coins[j]){
                temp[i] = temp[i] < (temp[i-coins[j]] + 1) ? temp[i] : (temp[i-coins[j]] + 1);
            }
        } 
    }
    return temp[n];
}

int main(){
    int n;
    vector<int> coins = {1,3,4};
    cin >> n;
    cout << DPMoneyChange(n, coins) << endl;
    return 0;
}
