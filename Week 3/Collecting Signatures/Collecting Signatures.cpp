#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

struct segment{
    ll l,r;
    bool is_contained = false;
};

bool cmp(struct segment a, struct segment b){
    return a.r < b.r;
}

int main()
{
    int n, num = 1;
    cin >> n;
    segment a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].l >> a[i].r;
    }
    vector<ll> ans;
    sort(a, a+n, cmp);

    int point = a[0].r;
    ans.push_back(point);
    for(int i = 1; i < n; i++){
        if(point < a[i].l || point > a[i].r){
            num++;
            point = a[i].r;
            ans.push_back(point);
        }
    }
    cout << num << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
