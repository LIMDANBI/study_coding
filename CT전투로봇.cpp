#include<iostream>
#include<vector>
#include<queue>
#define MAX 21
#define EMPTY 0
#define INF 987654321
using namespace std;

struct ROBOT {
	int y, x, level, cnt;
} robot;

int N;
int map[MAX][MAX];
int dist[MAX][MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) { // 상어의 초기 크기는 2
				robot = { i, j, 2, 0 };
				map[i][j] = EMPTY; // 빈칸으로 바꿔주기!!!!!!!!!!!!!!!!!!!!!!!!!!
			}
		}
	}
}

void init_dist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
}

void get_dist() {
	init_dist();
	queue<pair<int, int>> q;
	q.push({ robot.y, robot.x });
	dist[robot.y][robot.x] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 경계를 벗어나는 경우
			if (robot.level < map[ny][nx]) continue; // 지나갈 수 없는 경우
			if (dist[ny][nx] != INF) continue; // 이미 방문한 경우
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int move_robot() {
	get_dist(); // 현 로봇의 위치에서 갈 수 있는 거리를 구함

	int ny, nx, fish_size, min_dist = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF || map[i][j] == EMPTY) continue; // 갈 수 없는 곳이거나, 비어 있는 곳인 경우
			if (map[i][j] == robot.level) continue; // 레벨이 같은 경우
			if (dist[i][j] < min_dist) {
				min_dist = dist[i][j];
				fish_size = map[i][j];
				ny = i; nx = j;
			}
		}
	}
	if (min_dist == INF) return 0;

	robot.y = ny; robot.x = nx; robot.cnt++;
	if (robot.cnt == robot.level) { // 자신의 레벨과 같은 수의 몬스터를 없앨 때 마다 레벨 1 증가
		robot.cnt = 0;
		robot.level++;
	}
	map[ny][nx] = EMPTY;
	return dist[ny][nx];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	
	int ans = 0;
	while (1) {
		int res = move_robot();
		if (res == 0) break;
		else ans += res;
	}
	cout << ans;
}