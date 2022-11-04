#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(); cin.tie();
    int N; cin >> N; cin.ignore();
    for(int i=1; i<=N; i++){
        string str; getline(cin, str);
        cout << i << ". " << str << "\n";
    }
}