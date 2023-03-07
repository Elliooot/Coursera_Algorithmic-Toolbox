#include<iostream>
#include<vector>

using namespace std;

vector<int> process;

int PrimitiveCal(int n){
    if(n == 1) return 0;
    vector<int> min(n+1);
    min[1] = 0;
    
    for(int i = 2; i <= n; i++){
        min[i] = min[i-1] + 1;
        if(i % 3 == 0){
            min[i] = min[i] < (min[i / 3] + 1) ? min[i] : (min[i / 3] + 1);
        }else if(i % 2 == 0){
            min[i] = min[i] < (min[i / 2] + 1) ? min[i] : (min[i / 2] + 1);
        }
    }
    int m = n;
    process.push_back(n);
    while(n>1){
        if(n % 3 == 0 && min[n/3]<min[n-1]){
            n/=3;
            process.push_back(n);
        }else if(n % 2 == 0 && min[n/2]<min[n-1]){
            n/=2;
            process.push_back(n);
        }else{
            n -= 1;
            process.push_back(n);
        }
    }
    return min[m];
}

int main(){
    int n;
    cin >> n;
    cout << PrimitiveCal(n) << endl;
    for(int i = process.size()-1; i >= 0; i--){
        cout << process[i] << " ";
    }
    return 0;
}
