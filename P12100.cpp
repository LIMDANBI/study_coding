#include<iostream>
#include<vector>
#define MAX 21
using namespace std;

int N, ans = 0;
int map[MAX][MAX];
int tmp_map[MAX][MAX];

vector<int> move_dir;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
}

void copy_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) tmp_map[i][j] = map[i][j];
	}
}

void move_up() {
	for (int col = 0; col < N; col++) {
		vector<int> v;
		for (int row = 0; row < N; row++) {
			if (tmp_map[row][col]) {
				v.push_back(tmp_map[row][col]);
				tmp_map[row][col] = 0;
			}
		}
		int row = 0, idx = 0;
		while (idx < v.size()) {
			if (idx + 1 < v.size() && v[idx] == v[idx + 1]) {
				tmp_map[row++][col] = v[idx] * 2;
				idx += 2;
			}
			else tmp_map[row++][col] = v[idx++];
		}
	}
}

void move_down() {
	for (int col = 0; col < N; col++) {
		vector<int> v;
		for (int row = N-1; row >= 0; row--) {
			if (tmp_map[row][col]) {
				v.push_back(tmp_map[row][col]);
				tmp_map[row][col] = 0;
			}
		}
		int row = N-1, idx = 0;
		while (idx < v.size()) {
			if (idx + 1 < v.size() && v[idx] == v[idx + 1]) {
				tmp_map[row--][col] = v[idx] * 2;
				idx += 2;
			}
			else tmp_map[row--][col] = v[idx++];
		}
	}
}

void move_left() {
	for (int row = 0; row < N; row++) {
		vector<int> v;
		for (int col = 0; col < N; col++) {
			if (tmp_map[row][col]) {
				v.push_back(tmp_map[row][col]);
				tmp_map[row][col] = 0;
			}
		}
		int col = 0, idx = 0;
		while (idx < v.size()) {
			if (idx + 1 < v.size() && v[idx] == v[idx + 1]) {
				tmp_map[row][col++] = v[idx] * 2;
				idx += 2;
			}
			else tmp_map[row][col++] = v[idx++];
		}
	}
}

void move_right() {
	for (int row = 0; row < N; row++) {
		vector<int> v;
		for (int col = N-1; col >= 0; col--) {
			if (tmp_map[row][col]) {
				v.push_back(tmp_map[row][col]);
				tmp_map[row][col] = 0;
			}
		}
		int col = N-1, idx = 0;
		while (idx < v.size()) {
			if (idx + 1 < v.size() && v[idx] == v[idx + 1]) {
				tmp_map[row][col--] = v[idx] * 2;
				idx += 2;
			}
			else tmp_map[row][col--] = v[idx++];
		}
	}
}

int max_block() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) res = max(res, tmp_map[i][j]);
	}
	return res;
}

void solution(int cnt) {
	if (cnt == 5) {
		copy_map();
		for (int d = 0; d < move_dir.size(); d++) {
			if (move_dir[d] == 0) move_up();
			else if (move_dir[d] == 1) move_down();
			else if (move_dir[d] == 2) move_left();
			else if (move_dir[d] == 3) move_right();
		}
		ans = max(ans, max_block());
		return;
	}
	for (int d = 0; d < 4; d++) { // 상 하 좌 우 
		move_dir.push_back(d);
		solution(cnt + 1);
		move_dir.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	solution(0);
	cout << ans;
}