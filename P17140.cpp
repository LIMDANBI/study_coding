#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int r, c, k;
int Count[MAX];
int A[MAX][MAX];
int rowNum = 3, colNum = 3; // 행 개수, 열 개수

void input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) cin >> A[i][j];
	}
}

void Roperation() { // R 연산
	queue<int> q;
	int maxElement = 0; // 가장 긴 row 길이 저장
	int rowSize[MAX]; // 변한 row의 길이 저장
	for (int i = 1; i <= rowNum; i++) {
		memset(Count, 0, sizeof(Count));
		vector<int> v;
		for (int j = 1; j <= colNum; j++) {
			int num = A[i][j];
			if (Count[num] == 0 && num != 0) v.push_back(num);
			Count[num]++;
		}
		priority_queue<pair<int, int>> pq; // 수의 등장 횟수, 수 
		for(int k=0; k<v.size(); k++){ // 한번이라도 나온 원소들 (0은 제외)
			int num = v[k];
			int cnt = Count[num];
			pq.push({ -cnt, -num }); // 오름차순 정렬
		}
		rowSize[i] = (int) v.size()*2;
		maxElement = max(maxElement, rowSize[i]); // maxElement update
		while (!pq.empty()) {
			int cnt = -pq.top().first;
			int num = -pq.top().second;
			pq.pop();
			q.push(num);
			q.push(cnt);
		}
	}
	if (maxElement > 100) maxElement = 100; // 100 이상은 무시
	for (int i = 1; i <= rowNum; i++) {
		for (int j = 1; j <= maxElement; j++) { // 가장 큰 열을 가지는 행과 길이를 맞춰줌
			if (j <= rowSize[i]) {
				A[i][j] = q.front();
				q.pop();
			}
			else A[i][j] = 0;
		}
	}
	colNum = maxElement;
}

void Coperation() { // C 연산
	queue<int> q;
	int maxElement = 0; // 가장 긴 col 길이 저장
	int colSize[MAX]; // 변한 col의 길이 저장
	for (int j = 1; j <= colNum; j++) {
		memset(Count, 0, sizeof(Count));
		vector<int> v;
		for (int i = 1; i <= rowNum; i++) {
			int num = A[i][j];
			if (Count[num] == 0 && num!=0) v.push_back(num);
			Count[num]++;
		}
		priority_queue<pair<int, int>> pq; // 수의 등장 횟수, 수 
		for (int k = 0; k < v.size(); k++) { // 한번이라도 나온 원소들 (0은 제외)
			int num = v[k];
			int cnt = Count[num];
			pq.push({ -cnt, -num }); // 오름차순 정렬
		}
		colSize[j] = (int)v.size() * 2;
		maxElement = max(maxElement, colSize[j]); // maxElement update
		while (!pq.empty()) {
			int cnt = -pq.top().first;
			int num = -pq.top().second;
			pq.pop();
			q.push(num);
			q.push(cnt);
		}
	}
	if (maxElement > 100) maxElement = 100; // 100 이상은 무시
	for (int j = 1; j <= colNum; j++) {
		for (int i = 1; i <= maxElement; i++) { // 가장 큰 열을 가지는 행과 길이를 맞춰줌
			if (i <= colSize[j]) {
				A[i][j] = q.front();
				q.pop();
			}
			else A[i][j] = 0;
		}
	}
	rowNum = maxElement;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	int ans = 0;
	while (A[r][c]!=k && ans<=100) {
		if (rowNum >= colNum) Roperation();
		else Coperation();
		ans++;
	}
	if (ans > 100) cout << -1; // 100초가 지나도 A[r][c] = k가 되지 않으면 -1을 출력
	else cout << ans;
}