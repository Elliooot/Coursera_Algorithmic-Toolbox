#include <iostream>

using namespace std;
typedef long long int ll;

int main()
{
    ll a, b;
    cin >> a >> b;
    while(b){
        int A = a;
        a = b;
        b = A % b;
    }
    cout << a << endl;
    return 0;
}
