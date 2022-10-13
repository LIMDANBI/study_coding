#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 30
using namespace std;

struct GROUP {
	int y, x, num, cnt; // 그룹을 이루는 숫자, 그룹 크기
};
vector<GROUP> group;
vector<int> selected_group;

int n, ans = 0;
int MAP[MAX][MAX];
int TMP_MAP[MAX][MAX];
int GNUM[MAX][MAX];
bool VISITED[MAX][MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> MAP[i][j];
	}
}

int bfs(int i, int j, int num, int group_num) {
	GNUM[i][j] = group_num;
	queue<pair<int, int>> q;
	q.push({ i, j });

	int group_size = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (GNUM[ny][nx] || MAP[ny][nx] != num) continue;
			GNUM[ny][nx] = group_num;
			q.push({ ny, nx });
			group_size++;
		}
	}
	return group_size;
}

int get_side_of_two_group(int i, int j, int g1_num, int g2_num) {
	memset(VISITED, false, sizeof(VISITED));
	queue<pair<int, int>> q;
	VISITED[i][j] = true;
	q.push({ i, j });
	
	int res = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || VISITED[ny][nx]) continue;
			if (GNUM[ny][nx] == g2_num) res++;
			if (GNUM[ny][nx] != g1_num) continue;
			VISITED[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	return res;
}

void art_score_of_two_group(int idx, int cnt) {
	if (cnt == 2) {
		int g1 = selected_group[0]; // 선택한 그룹 1 
		int g2 = selected_group[1]; // 선택한 그룹 2
		int g1_num = MAP[group[g1].y][group[g1].x];
		int g2_num = MAP[group[g2].y][group[g2].x];
		int score = (group[g1].cnt + group[g2].cnt) * g1_num * g2_num;
		int side = get_side_of_two_group(group[g1].y, group[g1].x, group[g1].num, group[g2].num); // 맞닿은 변의 개수를 구함
		//cout << group[g1].cnt << " " << group[g2].cnt << " " << g1_num << " " << g2_num << " " << side << "\n";
		ans += score * side;
		return; 
	}
	for (int i = idx; i < (int)group.size(); i++) {
		selected_group.push_back(i);
		art_score_of_two_group(i + 1, cnt + 1);
		selected_group.pop_back();
	}
}

void get_art_score() {
	
	group.clear(); // 이전 group 정보를 비워줌
	memset(GNUM, 0, sizeof(GNUM));
	
	// 1. group을 구함
	int group_num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (GNUM[i][j]) continue;
			int group_size = bfs(i, j, MAP[i][j], group_num);
			group.push_back({ i, j, group_num, group_size });
			group_num++;
		}
	}

	// 2. 두 그룹의 예술 점수를 구함
	art_score_of_two_group(0, 0);
}

void print_map() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << TMP_MAP[i][j] << " ";
		cout << "\n";
	} 
}

void rotate_square(int y1, int x1) {
	int mid = n / 2;
	for (int i = 0; i < mid; i++) {
		for (int j = 0; j < mid; j++) TMP_MAP[y1 + j][x1 - i + mid - 1] = MAP[y1 + i][x1 + j];
	}
}

void rotate() {

	int mid = n / 2;

	// 1. 십자가 반시계 방향 90' 회전
	for (int row = 0; row < mid; row++) TMP_MAP[mid][row] = MAP[row][mid]; // 상 -> 좌
	for (int col = 0; col < mid; col++) TMP_MAP[n - 1 - col][mid] = MAP[mid][col]; // 좌 -> 하
	for (int row = mid + 1; row < n; row++) TMP_MAP[mid][row] = MAP[row][mid]; // 하 -> 우
	for (int col = mid + 1; col < n; col++) TMP_MAP[n - 1 - col][mid] = MAP[mid][col]; // 우 -> 상
	TMP_MAP[mid][mid] = MAP[mid][mid]; // 중앙

	// 2. 정사각형 시계 방향 90' 회전
	rotate_square(0, 0); // 좌상
	rotate_square(0, mid + 1); // 우상
	rotate_square(mid + 1, 0); // 좌하
	rotate_square(mid + 1, mid + 1); // 우하
	//print_map();
	
	// 3. copy TMP_MAP to MAP
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) MAP[i][j] = TMP_MAP[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	get_art_score(); // 초기 예술 점수
	for (int i = 0; i < 3; i++) { // 1, 2, 3 회전 후 예술 점수
		rotate(); // 회전
		get_art_score(); // 회전 후 예술 점수를 구함
	}
	cout << ans;
}