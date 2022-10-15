#include<iostream>
#define MAX 1000
using namespace std;

int N, NUM;
int map[MAX][MAX];
int dy[] = { -1, 0, 1, 0 }; // 상 우 하 좌 
int dx[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> NUM;

	int idx = 2, cnt = 0;
	int y = N / 2, x = N / 2;
	pair<int, int> pos = { y + 1, x + 1 };
	map[y][x] = 1;
	for (int d = 0; y!=-1; d++) {
		d %= 4;
		if (d % 2 == 0) cnt++;
		for (int i = 0; i < cnt; i++) {
			y += dy[d];
			x += dx[d];
			if (y < 0) break;
			map[y][x] = idx++;
			if (map[y][x] == NUM) pos = { y+1, x+1 };
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << pos.first << " " << pos.second;
}