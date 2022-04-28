#include<iostream>
#include<cstring>
#include<vector>
#define MAX 5
using namespace std;

int M, S;
int sy, sx, maxeat = 0;
int smell[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> path[3], tmpPath[3];
int fdy[] = { 0, -1, -1, -1, 0, 1, 1, 1 }; // 물고기 이동 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ (1~8 -> 0~7)
int fdx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int sdy[] = { -1, 0, 1, 0 }; // 상어 이동 ↑, ←, ↓, → (0~3) 상 좌 하 우
int sdx[] = { 0, -1, 0, 1 };
vector<int> map[MAX][MAX], copyMap[MAX][MAX];

void input() {
	cin >> M >> S;
	int fy, fx, fd;
	for (int i = 0; i < M; i++) { // 물고기 정보 (위치, 방향)
		cin >> fy >> fx >> fd;
		map[fy][fx].push_back(fd - 1);
	}
	cin >> sy >> sx; // 상어 정보
}

void startCopy() { // 물고기 복제 시전
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) 
			copyMap[i][j] = map[i][j];
	}
}

void moveFish() { // 물고기 이동 (상어가 있는 칸, 물고기의 냄새가 있는 칸, 격자의 범위를 벗어나는 칸으로는 이동할 수 없음)
	vector<int> tmpMap[MAX][MAX];
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (map[i][j].size() == 0) continue;
			for (int k = 0; k < map[i][j].size(); k++) {
				int dir = map[i][j][k];
				int nd = dir;
				bool ismove = false;
				for (int d = 0; d < 8; d++) {
					int ny = i + fdy[nd];
					int nx = j + fdx[nd];
					nd--; if (nd < 0) nd = 7; // 반시계 방향 45도 회전
					if (ny<1 || ny >4 || nx<1 || nx>4) continue; // 범위를 벗어나는 경우
					if (smell[ny][nx]>0 || ny == sy && nx == sx) continue; // 물고기의 냄새 또는 상어가 있는 칸인 경우
					ismove = true; // 이동 성공
					nd++; if (nd > 7) nd = 0; // 이동에 성공 했으므로 회전할 필요 x 
					tmpMap[ny][nx].push_back(nd);
					break;
				}
				if (!ismove) tmpMap[i][j].push_back(dir); // 이동 실패
			}
		}
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++)
			map[i][j] = tmpMap[i][j];
	}
}

void backtracking(int y, int x, int cnt, int eat) { // 물고기를 가장 많이 잡아 먹을 수 있는 상어의 이동 경로을 찾음
	if (cnt == 0) {
		memset(visit, false, sizeof(visit));
		maxeat = -1; // 초기화
	}
	if (cnt == 3) {
		if (maxeat < eat) {
			maxeat = eat;
			for (int i = 0; i < 3; i++) path[i] = tmpPath[i];
		}
		return;
	}
	for (int d = 0; d < 4; d++) {
		int ny = y + sdy[d];
		int nx = x + sdx[d];
		if (ny < 1 || ny >4 || nx < 1 || nx>4) continue; // 범위를 벗어나는 경우
		tmpPath[cnt] = { ny, nx };
		if (visit[ny][nx]) backtracking(ny, nx, cnt + 1, eat);
		else {
			visit[ny][nx] = true;
			backtracking(ny, nx, cnt + 1, eat + map[ny][nx].size());
			visit[ny][nx] = false;
		}
	}
}

void moveShark() { // 상어가 물고기가 있는 칸으로 이동하면, 그 칸에 있는 모든 물고기는 격자에서 제외되고 냄새를 남김
	backtracking(sy, sx, 0, 0); // 물고기를 가장 많이 잡아 먹을 수 있는 상어의 이동 경로을 찾음
	for (int i = 0; i < 3; i++) {
		sy = path[i].first;
		sx = path[i].second;
		if (map[sy][sx].size() == 0) continue; // 물고기가 없는 경우
		map[sy][sx].clear(); // 물고기가 있는 경우
		smell[sy][sx] = 3; // 냄새를 남김
	}
}

void removeSmell() { // 물고기 냄새 제거
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (smell[i][j] > 0) smell[i][j]--;
		}
	}
}

void finishCopy() { // 물고기 복제 완료
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			for (int k = 0; k < copyMap[i][j].size(); k++)
				map[i][j].push_back(copyMap[i][j][k]);
		}
	}
}

int ouput() { // S번의 연습을 마친 후 격자에 있는 물고기의 수
	int ans = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) ans += map[i][j].size();
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	while (S--){
		startCopy();
		moveFish();
		moveShark();
		removeSmell();
		finishCopy();
	}
	cout << ouput();
}