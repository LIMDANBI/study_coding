#include<iostream>
#define MAX 4
#define EMPTY 0
#define SHARK -1
#define FISHNUM 17
using namespace std;

struct FISH {
	int y, x, d;
	bool isdead;
} fish[FISHNUM];

int ans = 0, map[MAX][MAX];
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void input() {
	int num, dir;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> num >> dir;
			fish[num] = { i, j, dir-1, false };
			map[i][j] = num;
		}
	}
}

void move_fish() {
	for (int i = 1; i < FISHNUM; i++) {
		if (fish[i].isdead) continue;
		int y = fish[i].y;
		int x = fish[i].x;
		int d = fish[i].d;
		for (int dir = 0; dir < 8; dir++) {
			int nd = (d + dir) % 8;
			int ny = y + dy[nd];
			int nx = x + dx[nd];
			if (ny < 0 || ny >= MAX || nx < 0 || nx >= MAX || map[ny][nx]==SHARK) continue;
			
			// 물고기 위치 교환
			int num = map[ny][nx];
			map[ny][nx] = map[y][x];
			map[y][x] = num;

			// fish 정보 수정 
			fish[i] = { ny,nx,nd, false };
			fish[num].y = y;
			fish[num].x = x;
			break;
		}
	}
}

void move_shark(int y, int x, int d, int eat) {
	ans = max(ans, eat);

	// 1. backtracking을 위한 정보 저장
	int tmp_map[MAX][MAX];
	FISH tmp_fish[FISHNUM];
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) tmp_map[i][j] = map[i][j];
	}
	for (int i = 1; i < FISHNUM; i++) tmp_fish[i] = fish[i];

	// 2. 물고기 이동 
	move_fish();

	// 3. 상어 이동
	for (int cnt = 1; cnt < MAX; cnt++) {
		int ny = y + dy[d] * cnt;
		int nx = x + dx[d] * cnt;
		if (ny < 0 || ny >= MAX || nx < 0 || nx >= MAX || map[ny][nx]==EMPTY) continue;

		int num = map[ny][nx];
		fish[num].isdead = true;
		map[ny][nx] = SHARK;
		map[y][x] = EMPTY;
		move_shark(ny, nx, fish[num].d, eat + num);
		map[y][x] = SHARK;
		map[ny][nx] = num;
		fish[num].isdead = false;
	}

	// 4. 이전에 저장해둔 정보 복구
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) map[i][j] = tmp_map[i][j];
	}
	for (int i = 1; i < FISHNUM; i++) fish[i] = tmp_fish[i];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	int num = map[0][0]; 
	map[0][0] = SHARK;
	fish[num].isdead = true;
	move_shark(0, 0, fish[num].d, num);
	cout << ans;
}