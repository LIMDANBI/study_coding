#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

int N;
bool map[MAX][MAX];
int dy[] = { 0, -1, 0, 1 }; // 우 상 좌 하
int dx[] = { 1, 0, -1, 0 };

void solution(int x, int y, int d, int g) {

	vector<int> dir;

	// 시작점 
	map[y][x] = true;
	y += dy[d];
	x += dx[d];
	map[y][x] = true;
	dir.push_back(d);

	// g 세대 드래곤 커브 
	while (g--) {
		int curve_size = dir.size();
		for (int i = curve_size - 1; i >= 0; i--) { // 거꾸로 
			int nd = (dir[i] + 1) % 4;
			y += dy[nd];
			x += dx[nd];
			map[y][x] = true;
			dir.push_back(nd);
		}
	}
}

void output() {  // 크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수
	int ans = 0;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) ans++;
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		solution(x, y, d, g);
	}
	output();
}