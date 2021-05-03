#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int cost[26][26];
vector<vector<int>> tmp_board;
struct Car{
    int r, c, dir, cost;
};

int dir_r[4] = {-1, 1, 0, 0};
int dir_c[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> board) {
    int len = board.size();
    int answer = len*len*500;
    tmp_board = board;
    fill(&cost[0][0], &cost[len][len], answer);
    queue<Car> q;
    q.push({0,0,5,0});
    board[0][0] = 1;
    while(!q.empty()){
        Car car = q.front();
        q.pop();
        int cost = car.cost;
        int dir = car.dir;
        //cout<<"loc : " <<car.r<<" "<<car.c<<" 방향 : "<<car.dir<<" 비용 : "<<car.cost<<endl; 
        if(car.r == len-1 && car.c == len-1){
            cout<<"cost ; "<<cost<<endl;
            answer = min(answer, car.cost);
            continue;
        }
        
        for(int i=0; i<4; i++){
            int next_r = car.r + dir_r[i];
            int next_c = car.c + dir_c[i];
            
            if(next_r>=0 && next_r<len && next_c>=0 && next_c<len && board[next_r][next_c]!=1){
                //cout<<next_r<<" "<<next_c<<" "<<board[next_r][next_c]<<" "<<dir<<endl;
                if(dir==5){
                    if(board[next_r][next_c]==0 || board[next_r][next_c] >= cost+100){
                        cout<<"haha"<<endl;
                        q.push({next_r, next_c, i, cost+100});
                        board[next_r][next_c] = cost+100;
                    }
                }
                else if(dir == 0 || dir == 1){
                    if(i<=1){
                        if(board[next_r][next_c]==0 || board[next_r][next_c] >= cost+100){
                            q.push({next_r, next_c, i, cost+100});
                            board[next_r][next_c] = cost+100;
                        }
                    }
                    else{
                        if(board[next_r][next_c]==0 || board[next_r][next_c] >= cost+600){
                            q.push({next_r, next_c, i, cost+600});
                            board[next_r][next_c] = cost+600;
                        }
                    }
                }
                else{
                    if(i<=1){
                        if(board[next_r][next_c]==0 || board[next_r][next_c] >= cost+600){
                            q.push({next_r, next_c, i, cost+600});
                            board[next_r][next_c] = cost+600;
                        }
                    }
                    else{
                        if(board[next_r][next_c]==0 || board[next_r][next_c] >= cost+100){
                            q.push({next_r, next_c, i, cost+100});
                            board[next_r][next_c] = cost+100;
                        }
                    }
                }
            }
        }
    }
    return answer;
}