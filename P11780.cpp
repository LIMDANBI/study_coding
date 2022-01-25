#include<iostream>
#include<vector>
#define INF 1000001
#define MAX 101
using namespace std;

int N, M, a, b, c; 
int dist[MAX][MAX];
int route[MAX][MAX];
vector<int> path;

void find_path(int i, int j){ // 경로 찾기
    int p = route[i][j];
    while (p!=0){
        path.push_back(p);
        p = route[i][p];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    // dist 초기화
    for(int i=1; i<=N; i++){ 
        for(int j=1; j<=N; j++) {
            if(i!=j) dist[i][j] = INF;
        }
    }

    // edge 정보 저장
    while (M--){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        route[a][b] = a;
    }

    // floyd algorithm + 경로 저장
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                int before_cost = dist[i][j];
                int new_cost = dist[i][k]+dist[k][j];
                if(new_cost<before_cost) {
                    dist[i][j] = new_cost;
                    route[i][j] = route[k][j];
                }
            }
        }
    }

    // 출력
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(dist[i][j]==INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) cout << "0\n";
            else{
                find_path(i,j);
                if(path.empty() && dist[i][j]==INF) cout << '0';
                else{
                    cout << path.size() + 1 << ' ';
                    for(int i=path.size()-1; i>=0; i--)
                        cout << path[i] << ' ';
                    cout << j << ' ';
                } 
                cout << '\n';
            }
            path.clear();
        } 
    }
}