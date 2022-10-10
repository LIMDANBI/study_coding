#include<iostream>
#define MAX 101
using namespace std;

int N, L;
int map[MAX][MAX];

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
}

void solution() {
	int ans = 0;

	// 1. row 확인 
	for (int row = 0; row < N; row++) {
		int cnt = 1;  
		bool ismake = true;
		for (int col = 0; col + 1 < N; col++) {
			if (map[row][col] == map[row][col + 1]) cnt++; // 높이가 동일한 경우
			else if (map[row][col] - map[row][col + 1] == -1) { // 높이가 높아지는 경우
				if (cnt >= L) cnt = 1;
				else ismake = false;
			}
			else if (map[row][col] - map[row][col + 1] == 1) { // 높이가 낮아지는 경우
				if (cnt < 0) ismake = false;
				else cnt = 1 - L;
			}
			else ismake = false;
		}
		if (cnt >= 0 && ismake) ans += 1;
	}
	
	// 2. col 확인
	for (int col = 0; col < N; col++) {
		int cnt = 1;
		bool ismake = true;
		for (int row = 0; row + 1 < N; row++) {
			if (map[row][col] == map[row + 1][col]) cnt++; // 높이가 동일한 경우
			else if (map[row][col] - map[row + 1][col] == -1) { // 높이가 높아지는 경우
				if (cnt >= L) cnt = 1;
				else ismake = false;
			}
			else if (map[row][col] - map[row + 1][col] == 1) { // 높이가 낮아지는 경우
				if (cnt < 0) ismake = false;
				else cnt = 1 - L;
			}
			else ismake = false;
		}
		if (cnt >= 0 && ismake) ans += 1;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	solution();
}