#include<iostream>
#include<cstring>
#define MAX 101
#define EMPTY 0
using namespace std;

struct SHARK {
	int r, c, s, d, z;  // 위치, 속력, 이동방향, 크기
	bool isdead; // 죽은 상어인지
};
SHARK shark[MAX * MAX];

int ans = 0;
int R, C, M; //격자판의 크기, 상어의 수
int fish_manR = 0, fish_manC = 0; // 낚시왕 위치
int map[MAX][MAX], tmpMap[MAX][MAX]; // 상어가 있는지
int dr[] = { -1, 1, 0, 0 }; // 위 아래 오른쪽 왼쪽 (1~4 -> 0~3)
int dc[] = { 0, 0, 1, -1 };

void input() {
	cin >> R >> C >> M;
	int r, c, s, d, z; // 위치, 속력, 이동방향, 크기
	for (int i = 1; i <= M; i++) {
		cin >> r >> c >> s >> d >> z;
		map[r][c] = i; // 상어 여부 저장 (EMPTY(0) 아닌 경우 상어 존재)
		shark[i] = { r, c, s, d - 1, z, false }; // 상어 정보 저장
	}
}

void catchShark() {
	fish_manC++; // 낚시왕이 오른쪽으로 한 칸 이동
	for (int r = 1; r <= R; r++) {
		if (map[r][fish_manC] == EMPTY) continue;
		int sharkNum = map[r][fish_manC];
		int y = shark[sharkNum].r;
		int x = shark[sharkNum].c;
		// 상어를 잡음
		ans += shark[sharkNum].z;
		map[y][x] = EMPTY;
		shark[sharkNum].isdead = true;
		return;
	}
}

void moveShark() {
	memset(tmpMap, EMPTY, sizeof(tmpMap)); // 초기화
	for (int i = 1; i <= M; i++) { // i 번째로 들어온 상어
		if (shark[i].isdead) continue; // 이미 죽은 상어인 경우 이동 x
		int s = shark[i].s; // 상어의 속력 (칸/초)
		int r = shark[i].r;
		int c = shark[i].c;
		int d = shark[i].d;
		if (d < 2) s %= (2 * R - 2);
		else s %= (2 * C - 2);
		while (s--) { // s칸 이동
			r += dr[d];
			c += dc[d];
			if (r<1 || r>R || c<1 || c>C) { // 범위를 벗어나는 경우
				if (d == 0 || d == 2) d++; // 이동 방향을 반대로 바꿈
				else d--;
				shark[i].d = d; // 바뀐 방향 저장
				r += dr[d] * 2; // 잘못 갔던 것까지 돌려 놓기 위해 *2
				c += dc[d] * 2;
			}
		}
		// 상어 위치 정보 수정
		shark[i].r = r;
		shark[i].c = c;
		if (tmpMap[r][c] == EMPTY) tmpMap[r][c] = i; // 비어 있는 경우
		else { // 다른 상어가 있는 경우
			int before = tmpMap[r][c];
			if (shark[before].z > shark[i].z) shark[i].isdead = true;
			else {
				shark[before].isdead = true;
				tmpMap[r][c] = i;
			}
		}
	}
	for (int i = 1; i <= R; i++) { // 배열 복사
		for (int j = 1; j <= C; j++) map[i][j] = tmpMap[i][j];
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	while (fish_manC < C) {
		catchShark(); // 상어 잡음
		moveShark(); // 상어 이동
	}
	cout << ans;
}