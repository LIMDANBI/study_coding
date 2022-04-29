#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 21
using namespace std;

struct SERVICE { // 운행 정보
	int sy, sx, dy, dx; // 출발지 도착지
	bool iscompleted; // 도착 여부
};
vector<SERVICE> service;

struct PASSENGER { int dist, y, x; }; // 승객 정보
struct compare {
	bool operator()(const PASSENGER& p1, const PASSENGER& p2) { // 우선순위 : 짧은 거리 > 작은 행 번호 > 작은 열 번호
		if (p1.dist == p2.dist) {
			if (p1.y == p2.y) return p1.x > p2.x;
			return p1.y > p2.y;
		}
		return p1.dist > p2.dist;
	}
};

int N, M, Fuel, Remain; // N*N, M명의 승객, 연료, 남은 승객
int bj_y, bj_x; // 백준이 운전을 시작하는 칸의 행 번호와 열 번호
int num, dest_y, dest_x; // 현재 승객의 번호, 목적지 
int map[MAX][MAX], fuel[MAX][MAX];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M >> Fuel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> map[i][j];
	}
	cin >> bj_y >> bj_x; //  백준이 운전을 시작하는 칸의 행 번호와 열 번호
	Remain = M; // 남은 승객 수 
	int sy, sx, dy, dx;
	for (int i = 0; i < M; i++) {
		cin >> sy >> sx >> dy >> dx; // 각 승객의 출발지의 행과 열 번호, 그리고 목적지의 행과 열 번호
		service.push_back({ sy, sx, dy, dx, false });
	}
}

void findClose() {
	memset(fuel, -1, sizeof(fuel)); // 초기화
	queue<pair<int, int>> q; // BFS 탐색
	q.push({ bj_y, bj_x });
	fuel[bj_y][bj_x] = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr<1 || nr>N || nc<1 || nc>N) continue; // 범위를 벗어나는 경우
			if (map[nr][nc] || fuel[nr][nc] != -1) continue; // 벽이 있는 경우, 이미 방문한 경우
			fuel[nr][nc] = fuel[r][c] + 1;
			q.push({ nr,nc });
		}
	}

	priority_queue<PASSENGER, vector<PASSENGER>, compare> pq;
	for (int i = 0; i < service.size(); i++) {
		if (service[i].iscompleted) continue;
		int sy = service[i].sy;
		int sx = service[i].sx;
		int dist = fuel[sy][sx];
		if (dist != -1) {
			pq.push({ dist, sy, sx });
			if (pq.top().x == sx && pq.top().y == sy) num = i;
		}
	}
	if (pq.size() == 0) {
		Fuel = -1;
		return;
	}
	dest_y = service[num].dy;
	dest_x = service[num].dx;
	bj_y = pq.top().y;
	bj_x = pq.top().x;
	int dist = pq.top().dist;
	if (dist >= Fuel) {
		Fuel = -1;
		return;
	}
	Fuel -= dist;
}

void goDestination() {
	if (Fuel < 0) return;
	memset(fuel, -1, sizeof(fuel)); // 초기화
	queue<pair<int, int>> q; // BFS 탐색
	q.push({ bj_y, bj_x });
	fuel[bj_y][bj_x] = 0;
	while (!q.empty() && fuel[dest_y][dest_x] == -1) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr<1 || nr>N || nc<1 || nc>N) continue; // 범위를 벗어나는 경우
			if (map[nr][nc] || fuel[nr][nc] != -1) continue; // 벽이 있는 경우, 이미 방문한 경우
			fuel[nr][nc] = fuel[r][c] + 1;
			q.push({ nr,nc });
		}
	}
	int dist = fuel[dest_y][dest_x];
	if (dist > Fuel || dist == -1) {
		Fuel = -1;
		return;
	}
	Fuel += dist;
	service[num].iscompleted = true;
	Remain--;
	bj_y = dest_y;
	bj_x = dest_x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	while (Remain > 0 && Fuel > 0) {
		findClose(); // 가장 가까운 손님을 찾음
		goDestination(); // 목적지로 모셔다 드림
	}
	cout << Fuel; // 모든 손님을 이동시키고 연료를 충전했을 때 남은 연료의 양
}