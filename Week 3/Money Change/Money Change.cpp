#include <iostream>
#include <vector>

using namespace std;

vector<int> denominations = {1, 5, 10};

void findMinCoins(int value){
    //sort(denominations.begin(), denominations.end());
    vector<int> answer;
    for(int i = denominations.size()-1; i >= 0 ; i--){
        while(value >= denominations[i]){
            value -= denominations[i];
            answer.push_back(denominations[i]);
        }
    }
    cout << answer.size() << endl;
}

int main()
{
    int value;
    cin >> value;
    findMinCoins(value);
    return 0;
}
