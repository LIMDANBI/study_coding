#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX 50
#define MAXVIRUS 10
#define EMPTY 0
#define WALL 1
#define VIRUS 2
using namespace std;

struct POS { int y, x; };
vector<POS> virus;

int N, M;
int emptyCnt = 0, ans = INF;
int map[MAX][MAX], timeMap[MAX][MAX];
bool active[MAXVIRUS];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != WALL) emptyCnt++; // 빈 공간 개수 저장
			if (map[i][j] == VIRUS) virus.push_back({ i,j }); // 바이러스 위치 저장
		}
	}
	emptyCnt -= M;
}

void bfs(queue<POS> q) {
	int infectCnt = 0, infectTIme=0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 범위를 벗어나는 경우
			if (map[ny][nx] == WALL || timeMap[ny][nx] != -1) continue; // 빈칸이 아닌 경우, 이미 방문한 경우
			timeMap[ny][nx] = timeMap[y][x] + 1;
			infectTIme = timeMap[ny][nx];
			if (emptyCnt == infectCnt) break;
			q.push({ ny, nx });
			infectCnt++;
		}
		if (emptyCnt == infectCnt) break;
	}
	if (emptyCnt == infectCnt) ans = min(ans, infectTIme);
}

void backtracking(int idx, int cnt) {
	if (cnt == M) { // M 개의 활성 바이러스를 모두 선택
		queue<POS> q;
		memset(timeMap, -1, sizeof(timeMap));
		for (int i = 0; i < virus.size(); i++) {
			if (!active[i]) continue;
			int y = virus[i].y;
			int x = virus[i].x;
			timeMap[y][x] = 0;
			q.push({ y,x }); // 활성화 된 바이러스 위치 push
		}
		bfs(q);
		return ;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (active[i]) continue;
		active[i] = true;
		backtracking(i + 1, cnt + 1);
		active[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	backtracking(0, 0);
	if (ans == INF) cout << -1; // 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우
	else cout << ans;
}