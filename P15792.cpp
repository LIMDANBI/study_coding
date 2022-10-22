#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int A, B;
	cin >> A >> B;
	cout << int(A/B) << ".";
	A%=B;
	for (int i = 0; i <= 1000; i++){
		A *= 10;
		cout << A/B;
		A = A - (A/B)*B;
	}
}