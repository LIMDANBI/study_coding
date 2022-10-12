#include<iostream>
#include<deque>
#define MAX 11
using namespace std;

int N, M, K;
deque<int> tree[MAX][MAX];
int nutrient[MAX][MAX], A[MAX][MAX];
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrient[i][j] = 5;
			cin >> A[i][j];
		}
	}
	int y, x, age;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> age;
		tree[y-1][x-1].push_back(age);
	}
}

void spring_and_summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			// 봄 - 양분을 먹을 수 있는 경우, 양분을 먹고 나이  1 증가
			for (t = 0; t < tree[i][j].size(); t++) {
				if (nutrient[i][j] < tree[i][j][t]) break; //양분을 먹지 못하고 즉시 죽음
				nutrient[i][j] -= tree[i][j][t];
				tree[i][j][t]++;
			}

			// 여름 - 봄에 죽은 나무들이 양분으로 변함 
			for (int k = tree[i][j].size() - 1; k >= t; k--) {
				nutrient[i][j] += tree[i][j][k] / 2;
				tree[i][j].pop_back();
			}
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int t = 0; t < tree[i][j].size(); t++) {
				if (tree[i][j][t] % 5) continue;  // 나무 나이가 5의 배수가 아닌 경우 
				for (int d = 0; d < 8; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
					tree[ny][nx].push_front(1); // 정렬하지 않기 위해!
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) nutrient[i][j] += A[i][j];
	}
}

void output() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) ans += tree[i][j].size();
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	while (K--) {
		spring_and_summer();
		fall();
		winter();
	}
	output();
}