#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, arr[1001]={0,}; cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr+0, arr+n);
    for(int i=0; i<n; i++) cout << arr[i] << endl;
}