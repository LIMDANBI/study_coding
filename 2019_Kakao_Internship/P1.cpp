#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    stack<int> basket; // 바구니
    int N = board.size(); // N * N 
    
    for(auto col : moves){
        int row = 0;
        while (row<N && board[row][col-1]==0) row++;
        if(row==N) continue; // 인형이 없는 경우
        if(basket.empty()) basket.push(board[row][col-1]); // 바구니가 비어있는 경우
        else { // 바구니가 비어있지 않은 경우
            if(basket.top() == board[row][col-1]){ // 인형이 터지는 경우
                answer+=2; // 터진 인형 개수 count
                basket.pop();
            }
            else basket.push(board[row][col-1]);
        }
        board[row][col-1] = 0; // 인형을 뽑았으므로 빈칸
    }
    return answer;
}