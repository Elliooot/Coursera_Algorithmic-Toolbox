#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> F(n+1);
    F[0] = 0;
    F[1] = 1;
    for(long long int i = 2; i < n+1; i++){
        F[i] = (F[i-1] + F[i-2]) % 10;
    }
    cout << F[n] << endl;
    return 0;
}
