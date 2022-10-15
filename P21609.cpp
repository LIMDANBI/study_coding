#include<iostream>
#include<cstring>
#include<queue>
#define MAX 21
#define EMPTY -2
#define BLACK -1
#define RAINBOW 0
using namespace std;

struct BLOCK
{
	int size, rainbow, row, col;
	bool operator < (const BLOCK &b) const {
		if (size == b.size) {
			if (rainbow == b.rainbow) {
				if (row == b.row) return col < b.col; // 기준 블록의 열이 가장 큰 것 (4)
				return row < b.row; // 기준 블록의 행이 가장 큰 것 (3)
			} return rainbow < b.rainbow; // 무지개 블록의 수가 가장 많은 블록 그룹 (2)
		} return size < b.size; // 가장 큰 블록 그룹 (1)
	}
};

int N, M;
int ans = 0;
bool isEnd = false;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
}

//void print_map() {
//	cout << "\n";
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (map[i][j] == EMPTY) cout << "  ";
//			else cout << map[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}

void turn_on_rainbow() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == RAINBOW) visited[i][j] = false;
		}
	}
}

pair<int, int> bfs(int i, int j, int num) {

	queue<pair<int, int>> q;
	visited[i][j] = true;
	q.push({ i,j });
	int size = 1;
	int rbow = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] || map[ny][nx] == EMPTY || map[ny][nx] == BLACK) continue;
			if (map[ny][nx] != RAINBOW && map[ny][nx] != num) continue;
			if (map[ny][nx] == RAINBOW) rbow++;
			visited[ny][nx] = true;
			q.push({ ny,nx });
			size++;
		}
	}
	return { size, rbow };
}

pair<int, int> find_block_group() {

	memset(visited, false, sizeof(visited));
	priority_queue<BLOCK> pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] || map[i][j] == RAINBOW || map[i][j] == BLACK || map[i][j] == EMPTY) continue;
			pair<int, int> res = bfs(i, j, map[i][j]);
			turn_on_rainbow(); // 무지개는 중복으로 가질 수 있음!
			if (res.first >= 2) pq.push({ res.first, res.second, i, j });
		}
	}

	if (pq.empty()) {  // 더 이상 블록 그룹이 없는 경우
		isEnd = true;
		return { -1, -1 };
	}

	// 점수 획득 
	int B = pq.top().size;
	ans += B * B;

	return { pq.top().row, pq.top().col };  // 우선순위가 높은 블록 그룹의 기준점
}

void remove_block_group(int y, int x, int num) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	visited[y][x] = true;
	map[y][x] = EMPTY;
	q.push({ y,x });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
			if (map[ny][nx] == num || map[ny][nx] == RAINBOW) {
				visited[ny][nx] = true;
				map[ny][nx] = EMPTY;
				q.push({ ny,nx });
			}
		}
	}	
}

void gravity_map() {

	// 1. tmp_map => EMPTY로 초기화 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) tmp_map[i][j] = EMPTY;
	}

	// 2. 중력 작용
	for (int col = 0; col < N; col++) {
		int idx = N - 1;
		for (int row = N - 1; row >= 0; row--) {
			if (map[row][col] == EMPTY) continue;
			else if (map[row][col] == BLACK) idx = row;
			tmp_map[idx--][col] = map[row][col];
		}
	}

	// 3. tmp_map to map
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) map[i][j] = tmp_map[i][j];
	}
}

void rotate_map() { // 격자가 90도 반시계 방향으로 회전
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) tmp_map[N - 1 - col][row] = map[row][col];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) map[i][j] = tmp_map[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	while (1) { // auto play

		// 1. 크기가 가장 큰 블록 그룹을 찾음
		pair<int, int> pos = find_block_group();
		if (isEnd) break; // 더 이상 블록 그룹이 없는 경우

		// 2. 찾은 블록그룹의 모든 블록을 제거
		remove_block_group(pos.first, pos.second, map[pos.first][pos.second]);

		// 3. 격자에 중력 작용
		gravity_map();

		// 4. 격자가 90' 반시계 방향으로 회전
		rotate_map();

		// 5. 다시 한번 격자에 중력 작용 
		gravity_map();
	}
	cout << ans; // 획득한 점수의 합
}