#include<iostream>
#include<cstring>
#include<vector>
#define MAX 20
#define MAXSHARK 401
#define EMPTY 0
using namespace std;
struct SMELL { int remain_smell, shark_num; }; // 남은 냄새, 냄새를 남긴 상어 번호
struct SHARK {
	int y, x, d;  // 상어의 위치, 방향
	bool isin; // 격자안에 있는지
};
SHARK shark[MAXSHARK];
SMELL smell[MAX][MAX], tmpSmell[MAX][MAX];

int N, M, K; // N×N 격자, M 마리 상어, K번 이동 후 냄새 소멸
int map[MAX][MAX], tmpMap[MAX][MAX];
int priority[MAXSHARK][4][4]; //  각 상어의 방향 우선순위 (ex. priority[1][0][1]: 1번 상어가 위를 보고 있을 때 두번 째 우선순위)
int dy[] = { -1, 1, 0, 0 };  // 위, 아래, 왼쪽, 오른쪽 (1, 2, 3, 4) / 1~4 -> 0~3
int dx[] = { 0, 0, -1, 1 };

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) { // 격자 상태 입력
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != EMPTY) {
				shark[map[i][j]] = {i, j, 0, true}; // 상어 정보 저장
				smell[i][j] = { K, map[i][j] }; // 냄새 정보 저장
			}
			else smell[i][j] = { 0, 0 }; // smell 정보 초기화
		}
	}
	for (int m = 1; m <= M; m++) { // 각 상어의 방향 설정
		int dir; cin >> dir;
		shark[m].d = dir-1; // 1~4 -> 0~3
	}
	for (int m = 1; m <= M; m++) { // 각 상어의 방향 우선순위
		for (int d = 0; d < 4; d++) { // d 방향을 바라볼 때
			for (int p = 0; p < 4; p++) { // p 번째 우선순위 = dir-1
				int dir; cin >> dir;
				priority[m][d][p] = dir-1; // 1~4 -> 0~3
			}
		}
	}
}

bool isContinue() { // 다른 상어가 남아 있는지 확인
	for (int i = 2; i <= M; i++) {
		if (shark[i].isin) return true;
	}
	return false;
}

void moveShark() { // 상어이동 + 냄새뿌림
	memset(tmpMap, EMPTY, sizeof(tmpMap)); // 초기화
	memset(tmpSmell, EMPTY, sizeof(tmpSmell)); // 초기화
	for (int i = 1; i <= M; i++) { // 상어들이 동시에 움직임
		if (!shark[i].isin) continue; // 상어가 격자 밖으로 나간 경우는 pass
		int y = shark[i].y; // i번 상어의 현재 위치
		int x = shark[i].x; // i번 상어의 현재 위치
		int d = shark[i].d; // i번 상어가 현재 바라보는 방향
		int move_y=y, move_x=x, chance=1; // 상어가 이동할 방향
		for (int j = 0; j < 4; j++) { // i번 상어가 d를 보고 있을 때 j 번째 우선순위
			int nd = priority[i][d][j];
			int ny = y + dy[nd];
			int nx = x + dx[nd];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // 범위를 벗어나는 경우
			if (smell[ny][nx].remain_smell == EMPTY) { // 냄새가 없는 칸을 발견한 경우
				move_y = ny;
				move_x = nx;
				shark[i].d = nd; // 상어가 바라보는 방향 update
				break;
			}
			else if (smell[ny][nx].shark_num == i && chance) { // 자신이 냄새를 남긴 방향
				move_y = ny;
				move_x = nx;
				shark[i].d = nd; // 상어가 바라보는 방향 update
				chance = 0;
			}
		}
		// 정한 방향으로 이동 + 냄새를 남김 (더 큰 상어가 있는 경우 번호가 큰 상어는 격자 밖으로 나감)
		if (tmpMap[move_y][move_x] == EMPTY) {
			shark[i].y = move_y;
			shark[i].x = move_x;
			tmpMap[move_y][move_x] = i;
			tmpSmell[move_y][move_x].remain_smell = K + 1; // 냄새를 남김
			tmpSmell[move_y][move_x].shark_num = i;
		}
		else {
			int before_num = tmpMap[move_y][move_x]; // 이전에 있던 상어 번호
			if (before_num > i) { // i번호를 가진 상어가 격자안에 상어를 밀어내는 경우
				shark[before_num].isin = false;
				shark[i].y = move_y;
				shark[i].x = move_x;
				tmpMap[move_y][move_x] = i;
				tmpSmell[move_y][move_x].remain_smell = K + 1;
				tmpSmell[move_y][move_x].shark_num = i;
			}
			else shark[i].isin = false;
		}
	}
	for (int i = 0; i < N; i++) { // 이동 후 모습
		for (int j = 0; j < N; j++) {
			map[i][j] = tmpMap[i][j];
			if (tmpSmell[i][j].remain_smell>0) smell[i][j] = tmpSmell[i][j];
		}
	}
}

void removeSmell() { // 냄새 사라짐
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (smell[i][j].remain_smell > 0) smell[i][j].remain_smell--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	int ans = 0;
	while (isContinue() && ans<=1000) {
		moveShark();
		removeSmell();
		ans++;
	}
	if (ans > 1000) cout << -1; // 1,000초가 넘어도 다른 상어가 격자에 남아 있으면 -1 출력
	else cout << ans;
}