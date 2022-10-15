#include<iostream>
#include<queue>
#define MAX 101
#define INF 987654321
#define EMPTY 0
using namespace std;

int N, K;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> map[N - 1][i];
}

bool isContinue() {
	int min_fish = INF, max_fish = 0;
	for (int i = 0; i < N; i++) {
		min_fish = min(min_fish, map[N - 1][i]);
		max_fish = max(max_fish, map[N - 1][i]);
	}
	if (max_fish - min_fish <= K) return false;
	return true;
}

void put_fish() {
	int min_fish = INF;
	for (int i = 0; i < N; i++) min_fish = min(min_fish, map[N - 1][i]);
	for (int i = 0; i < N; i++) {
		if (map[N - 1][i] == min_fish) map[N - 1][i]++;
	}
}

void fold_fish() {
	int start = 0, w = 1, h = 1;
	for (int idx = 0; ; idx++) {

		if (start + w + h - 1 >= N) break; // 더 이상 어항을 쌓을 수 없는 경우
		
		for (int x = start; x < start + w; x++) {
			for (int y = N - 1; y > N - 1 - h; y--) {
				int ny = N - 1 - w + x - start;
				int nx = start + w + N - 1 - y;
				map[ny][nx] = map[y][x];
				map[y][x] = EMPTY;
			}
		}
		start += (idx / 2 + 1);  // 시작점 위치
		idx % 2 ? w++ : h++; // 번갈아가며 증가
	}
}

void control_fish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == EMPTY) continue;

			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (map[ny][nx] == EMPTY) continue;
				int fish_num = map[i][j];
				if (map[ny][nx] < fish_num) {
					fish_num -= map[ny][nx];
					fish_num /= 5;
					tmp_map[ny][nx] += fish_num;
					tmp_map[i][j] -= fish_num;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += tmp_map[i][j];
			tmp_map[i][j] = EMPTY;
		}
	}
}

void spread_fihs() {

	queue<int> q;
	for (int col = 0; col < N; col++) {
		for (int row = N - 1; row >= 0; row--) {
			if (map[row][col]) {
				q.push(map[row][col]);
				map[row][col] = EMPTY;
			}
			else break;
		}
	}

	int col = 0;
	while (!q.empty() && col<N) {
		map[N - 1][col++] = q.front();
		q.pop();
	}
}

void two_fold_fish() {
	for (int col = 0; col < N / 2; col++) {
		map[N - 2][N - col - 1] = map[N - 1][col];
		map[N - 1][col] = EMPTY;
	}
	for (int col = N / 2; col < N / 2 + N / 4; col++) {
		map[N - 4][N - col + N / 2 - 1] = map[N - 1][col];
		map[N - 1][col] = EMPTY;
		map[N - 3][N - col + N / 2 - 1] = map[N - 2][col];
		map[N - 2][col] = EMPTY;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();

	int ans = 0;
	while (isContinue()) {

		// 1. 물고기의 수가 가장 적은 어항에 물고기를 한 마리 넣음
		put_fish();

		// 2. 어항을 쌓음
		fold_fish();

		// 3. 어항에 있는 물고기의 수 조절
		control_fish();

		// 4. 어항을 바닥에 일렬로 놓음
		spread_fihs();

		// 5. 가운데를 중심으로 왼쪽 N/2개를 공중 부양
		two_fold_fish();

		// 6. 다시 물고기 수 조절 
		control_fish();

		// 7. 다시 바닥에 일렬로 놓음
		spread_fihs();

		ans++;
	}
	cout << ans;
}