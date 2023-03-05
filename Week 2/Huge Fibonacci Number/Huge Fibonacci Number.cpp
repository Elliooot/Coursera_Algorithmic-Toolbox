#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

ll pisano(ll m)
{
    ll prev = 0;
    ll curr = 1;
    ll res = 0;
    for(int i = 0; i < m * m; i++){
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll pisanoPeriod = pisano(m);
    n = n % pisanoPeriod;
    vector<int> f(n+1);
    f[0] = 0;
    f[1] = 1;
    for(ll i = 2; i < n+1; i++){
        f[i] = (f[i-1] + f[i-2]) % m;
    }
    cout << f[n] << endl;
    return 0;
}
