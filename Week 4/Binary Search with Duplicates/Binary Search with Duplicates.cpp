#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> k, int q){
    int min_idx = 0, max_idx = k.size()-1;
    while(max_idx >= min_idx){
        int mid = (min_idx + max_idx) / 2;
        if(q == k[mid] && k[mid-1] != k[mid])return mid;
        else if(q < k[mid] || (q == k[mid] && k[mid-1] == k[mid])) max_idx = mid - 1;
        else if(q > k[mid]) min_idx = mid + 1;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    cin >> m;
    vector<int> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i];
    }
    for(int i = 0; i < m; i++){
        cout << BinarySearch(k, q[i]) << " ";
    }
    return 0;
}
