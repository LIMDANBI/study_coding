#include<iostream>
#define EMPTY 0
#define WALL -1
#define MAX 21
using namespace std;

int ans = 0;
int N, M, K, C;
int map[MAX][MAX];
int tmp_map[MAX][MAX];
int herbicide[MAX][MAX];
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void input() {
	cin >> N >> M >> K >> C;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
}

void copy_and_init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += tmp_map[i][j]; // copy
			tmp_map[i][j] = 0; // init for next year
		}
	}
}

void grow_tree() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == EMPTY || map[i][j] == WALL) continue; // 나무가 아닌 경우
			
			for (int d = 0; d < 8; d+=2) { // 좌 상 우 하
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 경계를 벗어나는 경우
				if (map[ny][nx] == EMPTY || map[ny][nx] == WALL) continue; // 나무가 아닌 경우
				tmp_map[i][j]++;
			}
		}
	}

	copy_and_init();
}

void breeding_tree() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == EMPTY || map[i][j] == WALL) continue; // 나무가 아닌 경우

			int possible_cnt = 0, tree_cnt = map[i][j];
			for (int d = 0; d < 8; d += 2) { // 좌 상 우 하
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 경계를 벗어나는 경우
				if (map[ny][nx] == EMPTY && !herbicide[ny][nx]) possible_cnt++;
			}

			if (possible_cnt == 0) continue;

			int breeding_tree_cnt = tree_cnt / possible_cnt;

			for (int d = 0; d < 8; d += 2) { // 좌 상 우 하
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 경계를 벗어나는 경우
				if (map[ny][nx] == EMPTY && !herbicide[ny][nx]) tmp_map[ny][nx] += breeding_tree_cnt;
			}
		}
	}

	copy_and_init();
}

pair<int, int> select_pos() {
	
	int max_ruin = 0;
	pair<int, int> pos = { 0,0 }; // 제초제를 뿌렸을 때 나무가 가장 많이 박멸되는 칸

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int cnt = 0;
			if (map[i][j] == EMPTY || map[i][j] == WALL) continue;
			else cnt = map[i][j];

			for (int d = 1; d < 8; d+=2) { // 4개의 대각선 방향으로
				for (int k = 1; k <= K; k++) { // k칸만큼 전파
					int ny = i + dy[d] * k;
					int nx = j + dx[d] * k;
					if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 경계를 벗어나는 경우
					if (map[ny][nx] == WALL || map[ny][nx] == EMPTY) break; // 벽이거나 나무가 없는 칸인 경우, 이후의 칸으로는 제초제가 전파되지 않음 (그 칸 까지는 제초제가 뿌려짐)
					cnt += map[ny][nx];
				}
			}

			if (max_ruin < cnt) {
				max_ruin = cnt;
				pos = { i, j };
			}
		}
	}
	ans += max_ruin;
	return pos;
}

void spred_out(int y, int x) {

	herbicide[y][x] = C + 1;
	if (map[y][x] != WALL) map[y][x] = EMPTY;

	for (int d = 1; d < 8; d += 2) { // 4개의 대각선 방향으로
		for (int k = 1; k <= K; k++) { // k칸만큼 전파
			int ny = y + dy[d] * k;
			int nx = x + dx[d] * k;
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 경계를 벗어나는 경우
			if (map[ny][nx] == WALL || map[ny][nx] == EMPTY) {  // 벽이거나 나무가 없는 칸인 경우, 이후의 칸으로는 제초제가 전파되지 않음 (그 칸 까지는 제초제가 뿌려짐)
				herbicide[ny][nx] = C + 1;
				break;
			}
			herbicide[ny][nx] = C + 1;
			map[ny][nx] = EMPTY;
		}
	}
}

void reduce_herbicide() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (herbicide[i][j]) herbicide[i][j]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();

	for (int i = 0; i < M; i++) {
		grow_tree(); 
		breeding_tree(); 
		pair<int, int> pos = select_pos();
		spred_out(pos.first, pos.second); 
		reduce_herbicide();  
	}
	cout << ans;
}