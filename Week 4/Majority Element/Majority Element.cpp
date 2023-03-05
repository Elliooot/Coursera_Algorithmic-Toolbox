#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mid = n / 2, cnt = 1;
    bool f = false;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]) cnt = 1;
        else{
            cnt++;
            if(cnt > mid){
                cout << "1" << endl;
                f = true;
                break;
            }
        }
    }
    if(!f) cout << "0" << endl;
    return 0;
}
