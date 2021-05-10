#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

typedef struct {
    short int row;
    short int col;
    short int dir;
}element;

typedef struct {
    short int vert;
    short int horiz;
}offsets;

stack<element> s;

offsets movedir[8];

void initMove(){
    movedir[0].vert = -1;
    movedir[0].horiz = 0;

    movedir[1].vert = -1;
    movedir[1].horiz = 1;

    movedir[2].vert = 0;
    movedir[2].horiz = 1;

    movedir[3].vert = 1;
    movedir[3].horiz = 1;

    movedir[4].vert = 1;
    movedir[4].horiz = 0;

    movedir[5].vert = 1;
    movedir[5].horiz = -1;

    movedir[6].vert = 0;
    movedir[6].horiz = -1;

    movedir[7].vert = -1;
    movedir[7].horiz = -1;
}

int main(){
    ifstream read("maze.txt");
    ofstream write;
    //read.open("maze.txt");
    int size = sizeof(read);
    string str;
    int cnt = 0;
    int r, c;

    initMove();

    while(getline(read, str)){
        cnt++;
    }

    cout<<"세로 길이 : "<<cnt<<endl;
    cout<<"가로 길이 : "<<str.length()<<endl;


    r = cnt;
    c = str.length();

    int mark[r+2][c+2];
    /* mark 배열 초기화 */
    cout<<"------------mark 초기화-----------"<<endl;
    for(int i=0; i<r+2; i++){
        for(int j=0; j<c+2; j++){
            if(i==0 || i==r+1){
                mark[i][j] = 0;
            }
            else if(j==c+1 || j==0){
                mark[i][j] = 0;
            }
            else
                mark[i][j] = 1;   
        }
    }
    cout<<"<<mark 원본>>"<<endl;
    for(int i=0; i<r+2; i++){
        for(int j=0; j<c+2; j++){
            cout<<mark[i][j];
        }
        printf("\n");
    }

    char **maze;
    
    maze = new char*[r+2];
    for(int i=0; i<r+2; i++){
        maze[i] = new char[c+2];
        memset(maze[i], '1', sizeof(char)*(c+2));
    }

    read.close();
    ifstream read2("maze.txt");
    int i=1;
    while(getline(read2, str)){        
        for(int j=1; j<c+1; j++){
            maze[i][j] = str[j-1];
        }
        i++;
    }
    cout<<"<<미로 원본>>"<<endl;
    for(int i=0; i<r+2; i++){
        for(int j=0; j<c+2; j++){
            cout<<maze[i][j];
        }
        printf("\n");
    }

    element e, position, tmp;
    e.col=1;
    e.dir=0;
    e.row=1;
    s.push(e);
    mark[1][1] = 0;
    int row, col, nextRow, nextCol, dir, found = 0; // found가 1이 되면 경로 검색 완료 후 탈출
    while(!s.empty() && found == 0){
        position = s.top();
        s.pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while(dir<8 && found==0){
            nextRow = row + movedir[dir].vert;
            nextCol = col + movedir[dir].horiz;
            //cout<<nextRow<<" "<<nextCol<<" "<<"방향 : "<<dir<<endl;
            if(nextRow == r+1 && nextCol == c+1)
                found = 1;

            else if(maze[nextRow][nextCol]!='1' && mark[nextRow][nextCol]){
                //maze[nextRow][nextCol] = '1';
                mark[nextRow][nextCol] = 0;
                tmp.row = row;
                tmp.col = col;
                tmp.dir = ++dir;

                s.push(tmp);
                row = nextRow; col = nextCol; dir = 0;
            }
            else
                dir++;
        }
    }
    printf("\n");
    printf("\n");
    for(int i=1; i<r+1; i++){
        for(int j=1; j<c+1; j++){
            cout<<mark[i][j];
        }
        printf("\n");
    }

    read2.close();
    


    /*
        메모리 해제
    */
   /*
    for(int i=0; i<c+2; i++){
        delete [] maze[i];
    }

    delete [] maze;
    */
    return 0;
}