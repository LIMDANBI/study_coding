#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 21
#define EMPTY 0 //0: 빈 칸
#define RIGHT 1 //1 : 방향이 오른쪽인 온풍기가 있음
#define LEFT 2 //2 : 방향이 왼쪽인 온풍기가 있음
#define UP 3 //3 : 방향이 위인 온풍기가 있음
#define DOWN 4 //4 : 방향이 아래인 온풍기가 있음
#define CHECK 5 //5 : 온도를 조사해야 하는 칸
using namespace std;

struct TEMP { int r, c, d, k; };
struct HEATER { int r, c, d; };
vector<HEATER> heater;
vector<pair<int, int>> checkPos;

int R, C, K, W; // RxC, 온도가 K 이상이 되었는지, 벽의 개수
int map[MAX][MAX];
bool wall[MAX][MAX][5], visit[MAX][MAX];
int temperature[MAX][MAX], tmpTemperature[MAX][MAX];
int dr[] = { 0, 0, 0, -1, 1 }; // 오른쪽, 왼쪽, 위, 아래
int dc[] = { 0, 1, -1, 0, 0 };
int dh[5][2][3] = { // dh[1][1][0] 오른쪽을 바라볼 때 c 좌표 0번째
	{{ 0, 0, 0 }, { 0, 0, 0 }},
	{{ -1, 0, 1 }, { 1, 1, 1 }}, // 오른쪽
	{{ 1, 0, -1 }, { -1, -1, -1 }}, // 왼쪽
	{{ -1, -1, -1 }, { -1, 0, 1}}, // 위
	{{ 1, 1, 1 }, { 1, 0, -1 }}, // 아래
};

//void printMap() { // for check state
//	cout << '\n';
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) cout << temperature[i][j] << ' ';
//		cout << '\n';
//	}
//}

void input() {
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) { //  집 상태 정보
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (0 < map[i][j] && map[i][j] < 5) heater.push_back({ i, j, map[i][j] });
			if (map[i][j] == CHECK) checkPos.push_back({ i,j });
		}
	}
	cin >> W;
	int x, y, t;
	for (int i = 1; i <= W; i++) { // 벽 정보 -  t = 0, (x, y)와 (x-1, y) 사이 벽 / t = 1, (x, y)와 (x, y+1) 사이 벽
		cin >> x >> y >> t;
		if (t == 0) {
			wall[x][y][UP] = true; // (x,y) 입장에서는 위(3)에 벽이 생기는 것
			wall[x - 1][y][DOWN] = true; // (x-1,y) 입장에서는 아래(4)에 벽이 생기는 것
		}
		else {
			wall[x][y][RIGHT] = true; // (x,y) 입장에서는 오른쪽(1)에 벽이 생기는 것
			wall[x][y + 1][LEFT] = true; // (x,y+1) 입장에서는 왼쪽(2)에 벽이 생기는 것
		}
	}
}

void bfs(int h) {
	queue<TEMP> q;
	int r = heater[h].r;
	int c = heater[h].c;
	int d = heater[h].d; // 온풍기 방향
	r += dr[d]; 
	c += dc[d];
	q.push({ r,c,d,5 });
	visit[r][c] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		int k = q.front().k;
		q.pop();
		
		tmpTemperature[r][c] = k;
		for (int i = 0; i < 3; i++) {
			int nr = r + dh[d][0][i];
			int nc = c + dh[d][1][i];
			if (nr<1 || nr>R || nc<1 || nc>C || visit[nr][nc]) continue; // 범위를 벗어나는 경우, 이미 방문한 경우
			if (i == 1 && wall[r][c][d]) continue; // i = 1 인 경우 벽 확인
			else { // i = 0 or 2 인 경우 벽 확인
				if (d < 3) { // 우, 좌
					if (i == 0 && (wall[r][c][UP] || wall[nr][c][d])) continue;
					if (i == 2 && (wall[r][c][DOWN] || wall[nr][c][d])) continue;
				}
				else { // 상, 하
					if (i == 0 && (wall[r][c][RIGHT] || wall[r][nc][d])) continue;
					if (i == 2 && (wall[r][c][LEFT] || wall[r][nc][d])) continue;
				}
			}
			visit[nr][nc] = true;
			if (k - 1 > 0) q.push({ nr, nc, d, k - 1 });
		}
	}
}

void wind() {
	for (int h = 0; h < heater.size(); h++) {
		memset(tmpTemperature, 0, sizeof(tmpTemperature)); // 초기화
		memset(visit, false, sizeof(visit));
		bfs(h);
		for (int i = 1; i <= R; i++) { // 다른 온풍기에서 나온 바람에 의한 온도 상승
			for (int j = 1; j <= C; j++) temperature[i][j] += tmpTemperature[i][j];
		}
	}
}

void control() { // 온도 조절
	memset(tmpTemperature, 0, sizeof(tmpTemperature)); // 초기화
	for (int i = 1; i <= R; i++) { 
		for (int j = 1; j <= C; j++) {
			int temp = temperature[i][j];
			for (int d = 1; d < 5; d++) {
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr<1 || nr>R || nc<1 || nc>C || wall[i][j][d]) continue; //범위를 벗어나는 경우, 벽이 있는 경우
				if (temperature[i][j] > temperature[nr][nc]) {
					int diff = ((temperature[i][j] - temperature[nr][nc]) / 4);
					tmpTemperature[i][j] -= diff;
					tmpTemperature[nr][nc] += diff;
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) temperature[i][j] += tmpTemperature[i][j];
	}
}

void reduce() { // 온도가 1 이상인 가장 바깥쪽 칸(1행, R행, 1열, C열)의 온도가 1씩 감소
	for (int i = 1; i < C; i++) { // 1행
		if (temperature[1][i] > 0) temperature[1][i]--;
	}
	for (int i = 2; i <= C; i++) { // R행
		if (temperature[R][i] > 0) temperature[R][i]--;
	}
	for (int i = 2; i <= R; i++) { // 1열
		if (temperature[i][1] > 0) temperature[i][1]--;
	}
	for (int i = 1; i < R; i++) { // C열
		if (temperature[i][C] > 0) temperature[i][C]--;
	}
}

bool check() { // 조사하는 모든 칸의 온도가 K 이상이 되었는지 검사
	for (int i = 0; i < checkPos.size(); i++) {
		int r = checkPos[i].first;
		int c = checkPos[i].second;
		if (temperature[r][c] < K) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	int chocolate = 0;
	while (chocolate < 101) {
		wind();
		control();
		reduce();
		chocolate++;
		if (check()) break;
	}
	cout << chocolate;
}