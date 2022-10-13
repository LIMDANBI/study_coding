#include<iostream>
#include<queue>
#define MAX_N 21
#define MAX_M 401
#define EMPTY 0
using namespace std;

struct CONTRACT {
	int num, cnt;
} contract[MAX_N][MAX_N];

struct PLAYER {
	int y, x, dir;
	bool isdead;
} player[MAX_M];

int N, M, K;
int player_num[MAX_N][MAX_N];
int tmp_player_num[MAX_N][MAX_N];
int priority[MAX_M][4][4];

int dy[] = { -1, 1, 0, 0 }; //  위, 아래, 왼쪽, 오른쪽
int dx[] = { 0, 0, -1, 1 };

void print_map() {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << contract[i][j].num << "=" << contract[i][j].cnt << " ";
		} cout << "\n";
	}
}

void input() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> player_num[i][j];
			player[player_num[i][j]] = { i, j, -1, false };
		}
	}
	for (int i = 1; i <= M; i++) {
		int dir; cin >> dir;
		player[i].dir = dir - 1;  // 1~4 -> 0~3
	}
	for (int i = 1; i <= M; i++) { // i번째 상어가
		for (int j = 0; j < 4; j++) { // j번째 방향을 보고 있을 때
			for (int k = 0; k < 4; k++) { // 우선 순위 방향 4가지 순서대로
				cin >> priority[i][j][k];
				priority[i][j][k]--; // 1~4 -> 0~3
			}
		}
	}
}

void valid_period() {
	for (int i = 1; i <= M; i++) {
		if (player[i].isdead) continue; // 남아 있지 않은 플레이어는 계약을 하지 않음
		int y = player[i].y;
		int x = player[i].x;
		contract[y][x] = { i, K };
	}
}

void decrease_period() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (contract[i][j].cnt) contract[i][j].cnt--;
		}
	}
}

void move_player() {
	
	// 1. 플레이어가 이동
	for (int i = 1; i <= M; i++) {
		if (player[i].isdead) continue;
		int y = player[i].y;
		int x = player[i].x;
		int dir = player[i].dir;
		
		// 인접한 칸 중  아무도 독점 계약을 맺지 않은 칸(1), 본인이 독점 계약을 맺은 칸(0)을 찾음
		priority_queue<pair<int, int>> pq; 
		for (int d = 0; d < 4; d++) {
			int nd = priority[i][dir][d]; // i 번째 플레이어가 dir을 바라보고 있을 때 d 번째 우선수위
			int ny = y + dy[nd];
			int nx = x + dx[nd];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 범위를 벗어나는 경우
			if (contract[ny][nx].cnt == 0) pq.push({ 1, -d }); // 아무도 독점계약을 맺지 않은 칸
			if (contract[ny][nx].num == i) pq.push({ 0, -d }); // 본인이 독점 계약을 맺은 칸
		}

		int nd = priority[i][dir][-pq.top().second];
		int ny = y + dy[nd];
		int nx = x + dx[nd];

		// 플레이어 정보 수정!!!!!!!!!!!!!!!!!!!!
		player[i] = { ny, nx, nd, false};

		if (tmp_player_num[ny][nx] == EMPTY) tmp_player_num[ny][nx] = i;
		else { // 가장 작은 번호를 가진 플레이어만 살아 남음
			int before = tmp_player_num[ny][nx];
			if (i < before) {
				player[before].isdead = true;
				tmp_player_num[ny][nx] = i;
			}
			else player[i].isdead = true;
		}

	}

	// 2. 이동한 정보를 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			player_num[i][j] = tmp_player_num[i][j];
			tmp_player_num[i][j] = EMPTY; // 초기화!!!!!!!!!!!
		}
	}
}

bool isContinue() {
	for (int i = 2; i <= M; i++) {
		if (!player[i].isdead) return true;  // 다른 플레이어가 남아 있는 경우
	}
	return false; // 1번 플레이어만 남아 있는 경우 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();

	int ans = 0;
	valid_period();
	while (isContinue() && ans<=1000) {
		move_player();
		decrease_period();
		valid_period();
		ans++;
	}
	if(ans > 1000) cout << -1;
	else cout << ans;
}