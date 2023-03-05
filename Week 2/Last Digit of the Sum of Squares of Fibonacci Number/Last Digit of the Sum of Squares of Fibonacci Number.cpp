#include<iostream>

using namespace std;

long squarefib(long n){
    long long sum = 0;
    n %= 60;
    long long cur = 0, next = 1;
    for(int i = 0; i <= n; i++){
        sum += ((cur % 60) * (cur % 60));
        long long newcur = next;
        next += cur;
        cur = newcur;
    }
    return (sum % 10);
}

int main(){
    long n;
    cin >> n;
    cout << squarefib(n) << endl;
    return 0;
}
