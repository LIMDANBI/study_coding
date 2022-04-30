#include<iostream>
#include<vector>
#include<queue>
#define MAX 21
using namespace std;

struct STUDENT { int me, like1, like2, like3, like4; };
struct SEAT { int like, empty, row, col; };
struct compare {
	bool operator()(const SEAT& s1, const SEAT& s2) {
		if (s1.like == s2.like) {
			if (s1.empty == s2.empty) {
				if (s1.row == s2.row) return s1.col > s2.col; // 열의 번호가 가장 작은 칸
				return s1.row > s2.row; // 행의 번호가 가장 작은 칸
			}
			return s1.empty < s2.empty; // 인접한 칸 중에서 비어있는 칸이 가장 많은 칸
		}
		return s1.like < s2.like; // 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸
	}
};
vector<STUDENT> student;
pair<int, int> pos[401];

int N;
int map[MAX][MAX]; // 좌석 배치
int dr[] = { -1, 1, 0, 0 }; // 인접한 칸
int dc[] = { 0, 0, -1, 1 };

void input() {
	cin >> N;
	int me, like1, like2, like3, like4;
	for (int i = 0; i < N * N; i++) {
		cin >> me >> like1 >> like2 >> like3 >> like4;
		student.push_back({ me, like1, like2, like3, like4 });
	}
}

void selectSeat() {
	for (int i = 0; i < student.size(); i++) {
		int me = student[i].me;
		int like1 = student[i].like1;
		int like2 = student[i].like2;
		int like3 = student[i].like3;
		int like4 = student[i].like4;

		priority_queue<SEAT, vector<SEAT>, compare> pq;
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (map[r][c] != 0) continue; //빈칸이 아닌 경우
				int like = 0, empty = 0;
				for (int d = 0; d < 4; d++) {
					int nr = r + dr[d];
					int nc = c + dc[d];
					if (nr<1 || nr>N || nc<1 || nc>N) continue; // 범위를 벗어나는 경우
					if (map[nr][nc] == like1 || map[nr][nc] == like2 || map[nr][nc] == like3 || map[nr][nc] == like4) like++; // 인접한 좋아하는 학생 수 
					if (map[nr][nc] == 0) empty++; // 인접한 빈 칸
				}
				pq.push({ like, empty, r, c });
			}
		}
		int r = pq.top().row;
		int c = pq.top().col;
		map[r][c] = me;
		pos[me] = { r,c };
	}
}

int output() { // 학생의 만족도의 총 합 (인접한 칸에 앉은 좋아하는 학생의 수가 0이면 만족도는 0, 1이면 1, 2이면 10, 3이면 100, 4이면 1000)
	int ans = 0;
	for (int i = 0; i < student.size(); i++) {
		int me = student[i].me;
		int like1 = student[i].like1;
		int like2 = student[i].like2;
		int like3 = student[i].like3;
		int like4 = student[i].like4;
		int r = pos[me].first;
		int c = pos[me].second;
		int like = 0;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr<1 || nr>N || nc<1 || nc>N) continue; // 범위를 벗어나는 경우 
			if (map[nr][nc] == like1 || map[nr][nc] == like2 || map[nr][nc] == like3 || map[nr][nc] == like4) like++; // 인접한 좋아하는 학생 수 
		}
		if (like < 2) ans += like;
		else if (like == 2) ans += 10;
		else if (like == 3) ans += 100;
		else ans += 1000;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	selectSeat();
	cout << output();
}