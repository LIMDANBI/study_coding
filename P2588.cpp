#include <iostream>
using namespace std;
int main() {
    int arr[7]={};
    cin >> arr[1] >> arr[2];
    arr[3]=arr[1]*((arr[2]%100)%10); arr[4]=arr[1]*((arr[2]%100)/10); arr[5]=arr[1]*(arr[2]/100); arr[6]=arr[1]*arr[2];
    for(int i=3; i<7; i++) cout << arr[i] << "\n";
}