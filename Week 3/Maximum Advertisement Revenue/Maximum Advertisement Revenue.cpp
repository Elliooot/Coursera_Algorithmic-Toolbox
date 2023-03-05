#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll n;
    ll maxProfit = 0;
    cin >> n;
    vector<ll> price(n), clicks(n);
    for(ll i = 0; i < n; i++){
        cin >> price[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> clicks[i];
    }
    sort(price.begin(), price.end());
    sort(clicks.begin(), clicks.end());

    for(ll i = n-1; i >= 0; i--){
        maxProfit += price[i] * clicks[i];
    }
    cout << maxProfit << endl;
    return 0;
}
