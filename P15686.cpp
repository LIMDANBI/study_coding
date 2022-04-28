#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
#define MAX 51
#define EMPTY 0
#define HOUSE 1
#define CHICKEN 2
using namespace std;

struct POS { int y, x; };
vector<POS> chicken, house;

int N, M, ans = INF;
int map[MAX][MAX];
int selected[13]; // 치킨집 선택 여부

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == CHICKEN) chicken.push_back({ i,j }); // 치킨집 위치 저장
			if (map[i][j] == HOUSE) house.push_back({ i,j }); // 집 위치 저장
		}
	}
}

void backtracking(int idx, int cnt) {
	if (cnt == M) { // M개의 치킨 집 선택 완료
		int res = 0;
		for (int i = 0; i < house.size(); i++) {
			int dis = INF;
			int hy = house[i].y;
			int hx = house[i].x;
			for (int j = 0; j < chicken.size(); j++) {
				if (!selected[j]) continue;
				int cx = chicken[j].x;
				int cy = chicken[j].y;
				dis = min(dis, abs(cy - hy) + abs(cx - hx));
			}
			res += dis;
		}
		ans = min(ans, res);
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (selected[i]) continue;
		selected[i] = true; // i번 째 치킨 집 선택
		backtracking(i + 1, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	backtracking(0, 0);
	cout << ans;
}