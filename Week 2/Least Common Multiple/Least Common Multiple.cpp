#include <iostream>

using namespace std;
typedef long long int ll;

int main()
{
    ll a, b;
    cin >> a >> b;
    ll c = a * b;
    while(b){
        int A = a;
        a = b;
        b = A % b;
    }
    ll ans = c / a;
    cout << ans << endl;
    return 0;
}
