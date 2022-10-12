#include<iostream>
#include<vector>
#define MAX 100
using namespace std;

struct INFO {
    int y, x, d; // d=1인 경우 좌우, d=2인 경우 상하로만 움직임
    bool iscaught; // 잡힌 도망자인지
};
vector<INFO> runaway;

struct PATH { int y, x, d; };

int sy, sx;
int n, m, h, k;
bool tree[MAX][MAX];
vector<int> map[MAX][MAX];
vector<PATH> path;
int dy[] = { -1, 0, 1, 0 }; // 상 우 하 좌
int dx[] = { 0, 1, 0, -1 };

void make_2d_to_1d() {
    int cnt = 0;
    sy = sx = n / 2; // 술래의 초기 위치 
    path.push_back({ sy, sx, 0 });
    for (int d = 0; sy != 0 || sx != 0; d = (d + 1) % 4) {
        if (d % 2 == 0) cnt++;
        for (int c = 0; c < cnt; c++) {
            sy += dy[d]; sx += dx[d];
            if (c == cnt - 1) path.push_back({ sy, sx, 1 });
            else path.push_back({ sy, sx, 0 });
            if (sy == 0 && sx == 0) break;
        }
    }
    int psize = path.size();
    path[psize - 1].d = 1;
    for (int i = psize - 2; i > 0; i--) { // 왕복 경로
        if (path[i].d) path.push_back({ path[i].y, path[i].x, 2 }); // 돌아오는 경로 !!!!
        else path.push_back(path[i]);
    }
}

void input() {
    cin >> n >> m >> h >> k;
    int y, x, d;
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> d;
        runaway.push_back({ y - 1, x - 1, d, false });
    }
    for (int i = 0; i < h; i++) {
        cin >> y >> x;
        tree[y - 1][x - 1] = true;
    }
}

void move_runaway() {
    for (int i = 0; i < (int)runaway.size(); i++) {
        if (runaway[i].iscaught) continue; // 이미 잡힌 도망자인 경우
        int y = runaway[i].y;
        int x = runaway[i].x;
        int dist = abs(sy - y) + abs(sx - x);
        if (dist > 3) continue; // 술래와의 거리가 3 이하인 도망자만 움직임
        int d = runaway[i].d;
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) { // 격자를 벗어나는 경우
            d = (d + 2) % 4; // 방향을 반대로 틀어줌
            ny = y + dy[d];
            nx = x + dx[d];
            if (ny == sy && nx == sx) runaway[i].d = d; // 술래가 있는 경우, 틀어준 방향만 저장
            else runaway[i] = { ny, nx, d, false }; // 술래가 없는 경우, 해당 칸으로 이동
        }
        else if (ny != sy || nx != sx) runaway[i] = { ny, nx, d, false };  // 격자를 벗어나지 않고 술래가 없는 경우, 해당 칸으로 이동
    }
}

int change_dir(int sd, int p_dir) {
    if (p_dir == 1) sd = (sd + 1) % 4; // 가는 경로
    else if (p_dir == 2) sd = (sd + 3) % 4; // 돌아오는 경로 !!!! 방향변환 방식 다름 
    if (sy == 0 && sx == 0) sd = 2;
    else if (sy == n / 2 && sx == n / 2) sd = 0;
    return sd;
}

int catch_runaway(int d) {
    int caught = 0;
    for (int outlook = 0; outlook < 3; outlook++) { // 시야 = 현재 칸을 포함하여 3칸
        int ny = sy + dy[d] * outlook;
        int nx = sx + dx[d] * outlook;
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || tree[ny][nx]) continue; // 범위를 벗어나는 경우, 나무가 있어서 가려지는 경우
        for (int r = 0; r < (int)runaway.size(); r++) {
            if (ny == runaway[r].y && nx == runaway[r].x && !runaway[r].iscaught) {
                runaway[r].iscaught = true;
                caught++;
            }
        }
    }
    return caught;
}

void solution() {
    int ans = 0;

    int sd = 0; // 술래의 방향
    sy = sx = n / 2;

    int idx = 1; // path의 index
    int psize = path.size();

    for (int turn = 1; turn <= k; turn++) {

        // 1. 도망자 움직임
        move_runaway();

        // 2. 술래가 움직임
        sy = path[idx].y;
        sx = path[idx].x;
        // 방향이 바뀌는 경우 방향을 바로 틀어줌
        sd = change_dir(sd, path[idx].d);
        idx = (idx + 1) % psize;

        // 3. 도망자를 잡음
        ans += turn * catch_runaway(sd);
    }
    cout << ans; // 술래가 k번의 턴 동안 얻게되는 총 점수
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    make_2d_to_1d();
    solution();
}