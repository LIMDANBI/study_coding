#include <iostream>
#include <string.h>
using namespace std;
int main() {
	string id; cin >> id;
	cout << id.insert(id.size(), "??!");
}