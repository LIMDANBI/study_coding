#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k=1;
    while(1){
        set<int> node;
        vector<pair<int, int>> edge;
        int u, v, edgecnt=0, maxnode=0, tmp;
        while(1){
            cin>>u>>v;
            if(u==0 && v==0) {
                if(edgecnt==0) {
                    cout << "Case " << k++ << " is a tree.\n";
                    continue;
                } break;
            }
            if(u<0 && v<0) return 0;
            edgecnt++; node.insert(u); node.insert(v);
            edge.push_back(make_pair(u, v));
            tmp = max(u, v); maxnode = max(tmp, maxnode);
        }
        int root=0, rootCnt=0;
        int cnt[maxnode+1]={};
        int way[maxnode+1][maxnode+1]={};
        for(int i=0; i<edgecnt; i++) {
            cnt[edge[i].second]++;
            way[edge[i].first][edge[i].second] = 1;
        }
        for(int i=0; i<edgecnt; i++){
            if(root!=edge[i].first && cnt[edge[i].first]==0){
                rootCnt++;
                root = edge[i].first;
            }
        }
        if(rootCnt!=1 || node.size()!=edgecnt+1) cout << "Case " << k++ << " is not a tree.\n";
        else{
            queue<int> q; q.push(root);
            int visitcnt=0;
            while(!q.empty()){
                int s = q.front(); q.pop(); visitcnt++;
                for(int i=0; i<maxnode+1; i++){
                    if(way[s][i]==1) q.push(i);
                }
            }
            if(visitcnt==node.size()) cout << "Case " << k++ << " is a tree.\n";
            else cout << "Case " << k++ << " is not a tree.\n";
        }
    }
}

// 방법 2
// #include<iostream>
// #include<vector>
// #include<queue>
// #include<set>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     int k=1;
//     while(1){
//         set<int> node;
//         vector<pair<int, int>> edge;
//         int u, v, edgecnt=0, maxnode=0, tmp;
//         while(1){
//             cin>>u>>v;
//             if(u==0 && v==0) {
//                 if(edgecnt==0) {
//                     cout << "Case " << k++ << " is a tree.\n";
//                     continue;
//                 } break;
//             }
//             if(u<0 && v<0) return 0;
//             edgecnt++; node.insert(u); node.insert(v);
//             edge.push_back(make_pair(u, v));
//             tmp = max(u, v); maxnode = max(tmp, maxnode);
//         }
//         int root=0, rootCnt=0, isone=0;
//         int cnt[maxnode+1]={};
//         int way[maxnode+1][maxnode+1]={};
//         for(int i=0; i<edgecnt; i++) {
//             cnt[edge[i].second]++;
//             way[edge[i].first][edge[i].second] = 0;
//         }
//         for(int i=0; i<edgecnt; i++){
//             if(cnt[edge[i].first]==0){
//                 if(root!=edge[i].first){
//                     rootCnt++;
//                     root = edge[i].first;
//                 }
//             }
//             else if(cnt[i]>1) {
//                 isone = 1; break;
//             }
//         }
//         if(isone || rootCnt!=1 || node.size()!=edgecnt+1) cout << "Case " << k++ << " is not a tree.\n";
//         else cout << "Case " << k++ << " is a tree.\n";
//     }
// }