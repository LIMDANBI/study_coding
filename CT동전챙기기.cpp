#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX 21
#define WALL -1
#define EMPTY 0
#define END 10
using namespace std;

struct COIN{
	int num, y, x;
	bool operator < (const COIN& c) const {
		if (num == c.num) return y < c.y;
		return num < c.num;
	}
};
vector<COIN> coin, select_coin;

struct POS{
	int y, x;
} s_pos;

int N, ans = INF;
int coin_cnt = 0;
int map[MAX][MAX];
int dist[MAX][MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void print_map() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << map[i][j] << " ";
		cout << "\n";
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'S') { // 시작점
				s_pos = { i, j };
				map[i][j] = EMPTY;
			}
			else if (s[j] == 'E') map[i][j] = END; // 도착점
			else if (s[j] == '.') map[i][j] = EMPTY; // 빈공간
			else if (s[j] == '#') map[i][j] = WALL; // 벽
			else { // 동전
				coin_cnt++;
				map[i][j] = s[j] - '0';
				coin.push_back({ s[j] - '0', i, j});
			}
		}
	}
	sort(coin.begin(), coin.end()); // 동전에 적혀있는 숫자가 증가하는 순서대로 수집
}

void init_dist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
}

int bfs(int sy, int sx, int destination) {
	
	init_dist();

	queue<pair<int, int>> q;
	q.push({ sy, sx });
	dist[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (map[y][x] == destination) return dist[y][x];

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N ) continue; // 범위를 벗어나는 경우
			if (dist[ny][nx] != INF || map[ny][nx] == WALL) continue; // 이미 방문한 경우, 벽인 경우
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	return INF;
}

void solution(int idx, int cnt) {
	if (cnt == 3) {
		int res = 0, tmp;


		// 1. 시작점 -> 첫번째 코인
		tmp = bfs(s_pos.y, s_pos.x, select_coin[0].num);
		if (tmp == INF) return; res += tmp;

		// 2. 코인 간 이동
		for (int i = 0; i < 2; i++) {
			int sy = select_coin[i].y;
			int sx = select_coin[i].x;
			int destination = select_coin[i+1].num;
			tmp = bfs(sy, sx, destination);
			if (tmp == INF) return; res += tmp;
		}

		// 3. 마지막 코인 -> 도착점
		tmp = bfs(select_coin[2].y, select_coin[2].x, END);
		if (tmp == INF) return; res += tmp;

		ans = min(ans, res);
		return;
	}
	for (int i = idx; i < coin_cnt; i++) {
		select_coin.push_back(coin[i]);
		solution(i + 1, cnt + 1);
		select_coin.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	solution(0, 0);
	if (ans == INF) cout << -1;
	else cout << ans;
}