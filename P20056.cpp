#include<iostream>
#include<vector>
#define MAX 50 
using namespace std;

struct MSD { int m, s, d; };
vector<MSD> map[MAX][MAX], tmpMap[MAX][MAX];

int N, M, K;
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void input() {
	cin >> N >> M >> K; // 격자 크기, 파이어볼 개수, 이동명령 횟수
	int  r, c, m, s, d; // 위치, 질량, 속력, 방향
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		map[r - 1][c - 1].push_back({ m,s,d });
	}
}

void moveorder() { // 마법사 상어의 이동 명령
	for (int i = 0; i < N; i++) { // 파이어볼 이동
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				int m = map[i][j][k].m;
				int s = map[i][j][k].s;
				int d = map[i][j][k].d;
				int nr = i + dr[d] * s;
				int nc = j + dc[d] * s;
				nr %= N; if (nr < 0) nr += N; // 1번 행은 N번과 연결
				nc %= N; if (nc < 0) nc += N; // 1번 열은 N번 열과 연결
				tmpMap[nr][nc].push_back({ m,s,d });
			}
			map[i][j].clear();
		}
	}
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			if (tmpMap[i][j].size() > 1) { // 2개 이상의 파이어볼이 있는 칸
				int nm = 0, ns = 0, nd; // 새로운 질량, 속력, 방향
				int before = tmpMap[i][j][0].d;
				int flag = true;
				for (int k = 0; k < tmpMap[i][j].size(); k++) {
					nm += tmpMap[i][j][k].m;
					ns += tmpMap[i][j][k].s;
					nd = tmpMap[i][j][k].d;
					if (before % 2 != nd % 2) flag = false;
				}
				nm /= 5;
				ns /= (int)tmpMap[i][j].size();
				int start_dir;
				flag ? start_dir = 0 : start_dir = 1; // 방향이 모두 홀수이거나 모두 짝수이면 0, 2, 4, 6 / 그렇지 않으면 1, 3, 5, 7
				if (nm != 0) { // 질량이 0인 파이어볼은 소멸되어 없어짐
					for (int d = start_dir; d < 8; d += 2)
						map[i][j].push_back({ nm,ns,d });
				}
			}
			else map[i][j] = tmpMap[i][j]; // 파이어볼이 1개 있는 칸
			tmpMap[i][j].clear();
		}
	}
}

int output() {  // 남아있는 파이어볼 질량의 합
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) ans += map[i][j][k].m;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	while (K--) moveorder(); // 마법사 상어가 이동을 K번 명령
	cout << output(); // 남아있는 파이어볼 질량의 합
}