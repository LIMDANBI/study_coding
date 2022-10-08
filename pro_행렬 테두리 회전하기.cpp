#include <string>
#include <vector>
using namespace std;

int map[101][101];

void make_map(int row, int col){
    int num = 1;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++) map[i][j] = num++;
    } 
}

int rotate(int y1, int x1, int y2, int x2){
    int min_val = map[y1][x1];
    int tmp = map[y1][x1];
    for(int i=y1; i<y2; i++) { // 좌
        map[i][x1] = map[i+1][x1];
        min_val = min(min_val, map[i+1][x1]);
    }
    for(int i=x1; i<x2; i++){ // 하
        map[y2][i] = map[y2][i+1]; 
        min_val = min(min_val, map[y2][i+1]);
    }
    for(int i=y2; i>y1; i--){ // 우
        map[i][x2] = map[i-1][x2]; 
        min_val = min(min_val, map[i-1][x2]);
    }
    for(int i=x2; i>x1; i--){ // 상
        map[y1][i] = map[y1][i-1];
        min_val = min(min_val, map[y1][i-1]);
    }
    map[y1][x1+1] = tmp;
    return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer; // 회전에 의해 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return 
    make_map(rows, columns);
    for(int i=0; i<queries.size(); i++){
        int min_val = rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        answer.push_back(min_val);
    }
    return answer;
}