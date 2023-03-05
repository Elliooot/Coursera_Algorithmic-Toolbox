#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int d, m, n;
    cin >> d >> m >> n;
    vector<int> stop(n+2);
    stop[0] = 0;
    stop[n+1] = d;
    for(int i = 1; i < n+1; i++){
        cin >> stop[i];
    }

    int num = 0;
    int lastStop = stop[0];
    bool impossible = false;
    for(int i = 0; i < n+1; i++){
        if((stop[i+1]-stop[i]) > m){
            cout << -1 << endl;
            impossible = true;
            break;
        }else if((stop[i+1] - lastStop) > m){
            num++;
            lastStop = stop[i];
        }
    }
    if(!impossible) cout << num << endl;
    return 0;
}
