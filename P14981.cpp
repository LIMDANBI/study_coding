#include<iostream>
#include<cstring>
#include<string>
using namespace std;

string gear[4]; // N극은 0, S극은 1
int rotatenum[4];

void solution(int num, int dir) {
	
	memset(rotatenum, 0, sizeof(rotatenum));
	
	// 1. 톱니 바퀴들의 회전 방향 정하기 
	rotatenum[num] = dir;
	for (int i = num + 1; i < 4; i++) {
		if (rotatenum[i - 1] != 0 && gear[i - 1][2] != gear[i][6]) {
			if (rotatenum[i - 1] == -1) rotatenum[i] = 1;
			else if (rotatenum[i - 1] == 1) rotatenum[i] = -1;
		}
	}
	for (int i = num - 1; i >= 0; i--) {
		if (rotatenum[i + 1] != 0 && gear[i + 1][6] != gear[i][2]) {
			if (rotatenum[i + 1] == -1) rotatenum[i] = 1;
			else if (rotatenum[i + 1] == 1) rotatenum[i] = -1;
		}
	}

	// 2. 톱니 바퀴 회전
	for (int i = 0; i < 4; i++) {
		if (rotatenum[i] == -1) { // 반시계방향 회전
			string s = gear[i].substr(1);
			s += gear[i][0];
			gear[i] = s;
		}
		else if (rotatenum[i] == 1) { // 시계방향 회전
			string s = gear[i].substr(0, gear[i].size() - 1);
			s = gear[i][gear[i].size() - 1] + s;
			gear[i] = s;
		}
	}
}

void output() { // 총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력
	int pow2[] = { 1, 2, 4, 8 };
	int ans = 0;
	for (int i = 0; i < 4; i++) ans += (gear[i][0] - '0') * pow2[i]; // char to int
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> gear[i];
	int k, num, dir;  cin >> k;
	while (k--) {
		cin >> num >> dir;
		solution(num-1, dir);
	}
	output();
}