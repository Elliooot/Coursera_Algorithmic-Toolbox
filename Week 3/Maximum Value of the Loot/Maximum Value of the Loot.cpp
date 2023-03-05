#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item{
    int value, weight;
};

bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

long double fks(struct Item arr[], int W, int n){
    sort(arr, arr + n, cmp);
    double maxValue = 0;
    int curW = 0;
    for(int i = 0; i < n; i++){
        if((curW + arr[i].weight) <= W){
            maxValue += arr[i].value;
            curW += arr[i].weight;
        }else if((curW + arr[i].weight) > W){
            maxValue += (double)arr[i].value / arr[i].weight * (W - curW);
            curW = W;
        }
    }
    return maxValue;
}


int main()
{
    int n, W;
    cin >> n >> W;
    Item arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].value >> arr[i].weight;
    }
    cout << fixed << setprecision(3) << fks(arr, W, n) << endl;
    return 0;
}
