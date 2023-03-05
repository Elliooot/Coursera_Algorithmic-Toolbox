#include<iostream>
#include<vector>

using namespace std;
typedef long long int ll;

ll fib(ll n){
    n = (n + 2) % 60;
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    int res = 1;
    for(int i = 2; i <= n; i++){
        f[i] = (f[i-1] % 10 + f[i-2] % 10) % 10;
    }
    if(f[n] == 0){
        return 9;
    }
    return (f[n] % 10 - 1);
}

int main()
{
    ll n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
