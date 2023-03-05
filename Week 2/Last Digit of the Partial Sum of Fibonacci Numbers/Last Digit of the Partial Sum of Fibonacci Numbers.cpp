#include<iostream>

using namespace std;
typedef long long ll;

ll partialsum(ll from, ll to){
    ll sum = 0;
    int m = from % 60;
    int n = to % 60;
    if(n < m) n += 60;

    ll cur = 0, next = 1;
    for(int i = 0; i <= n; i++){
        if(i >= m){
            sum += cur;
        }
        ll newcur = next;
        next += cur;
        cur = newcur;
    }
    return (sum % 10);
}

int main(){
    ll from, to;
    cin >> from >> to;
    cout << partialsum(from, to) << endl;
    return 0;
}
