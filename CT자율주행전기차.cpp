#include<iostream>
#include<vector>
#include<queue>
#define MAX 21
#define EMPTY 0
#define WALL 1
#define NOTVISIT -1
using namespace std;

int n, m;
struct CAR { int y, x, c; } car;

struct PASSENGER {
	bool isarrive;
	int num, sy, sx, dy, dx, dist;
	bool operator < (const PASSENGER& info) const {
		if (dist == info.dist) {
			if (sy == info.sy) return sx > info.sx; // 열 번호가 가장 작은 승객
			return sy > info.sy; // 행 번호가 가장 작은 승객
		}
		return dist > info.dist; // 최단거리가 가장 짧은 승객
	}
};
vector<PASSENGER> passenger;

int map[MAX][MAX], dist_map[MAX][MAX];
int my[] = { -1,1,0,0 };
int mx[] = { 0,0,-1,1 };

void input() {
	cin >> n >> m >> car.c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> map[i][j];
	}
	cin >> car.y >> car.x;
	car.y--; car.x--;
	int sy, sx, dy, dx;
	for (int i = 0; i < m; i++) {
		cin >> sy >> sx >> dy >> dx;
		passenger.push_back({ false, i, sy - 1, sx - 1, dy - 1, dx - 1, 0 });
	}
}

void init_dist_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) dist_map[i][j] = NOTVISIT;
	}
}

void find_path() {
	init_dist_map();
	queue<pair<int, int>> q;
	q.push({ car.y, car.x });
	dist_map[car.y][car.x] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + my[d];
			int nx = x + mx[d];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == WALL) continue;
			if (dist_map[ny][nx] == NOTVISIT || dist_map[y][x] + 1 < dist_map[ny][nx]) {
				dist_map[ny][nx] = dist_map[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

bool move() {
	priority_queue<PASSENGER> pq;
	for (int i = 0; i < (int)passenger.size(); i++) {
		if (passenger[i].isarrive) continue; // 이미 목적지에 바래다 준 손님인 경우 
		int sy = passenger[i].sy;
		int sx = passenger[i].sx;
		int dist = dist_map[sy][sx];
		if (dist == NOTVISIT || dist >= car.c) continue;
		PASSENGER p = passenger[i];
		p.dist = dist; pq.push(p);
	}

	if (pq.size() == 0) return false;

	// 승객을 태우러감
	car.y = pq.top().sy;
	car.x = pq.top().sx;
	car.c -= pq.top().dist;
	passenger[pq.top().num].isarrive = true;

	find_path();

	int dy = pq.top().dy;
	int dx = pq.top().dx;
	if (dist_map[dy][dx] == NOTVISIT || dist_map[dy][dx]>car.c) return false;

	// 승객을 목적지에 데려다 줌
	car.y = dy;
	car.x = dx;
	car.c += dist_map[dy][dx];
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	bool impossible = false;
	for (int i = 0; i < m; i++) {
		find_path();
		if (!move()) {
			impossible = true;
			break;
		}
	}
	if (impossible) cout << -1;
	else cout << car.c;
}