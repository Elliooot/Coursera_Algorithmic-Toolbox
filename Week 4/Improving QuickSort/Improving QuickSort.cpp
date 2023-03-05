#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int partition(vector<int> &c, int front, int end){
    int pivot = c[end], i = front - 1;
    for(int j = front; j <= end - 1; j++){
        if(c[j] < pivot){
            i++;
            swap(c[i], c[j]);
        }
    }
    swap(c[i+1], c[end]);
    return i+1;
}

void QuickSort(vector<int> &c, int front, int end){
    if(front < end){
        int pi = partition(c, front, end);
        QuickSort(c, front, pi-1);
        QuickSort(c, pi+1, end);
    }

}
void print(vector<int> c, int n){
    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    QuickSort(c, 0, n-1);
    print(c, n);
    return 0;
}
