/** 솔루션 **/

/*
    1. 각 위치에서의 거리에 대한 정보를 담는 arr 배열 선언 후 단순 탐색을 진행하는 간단한 문제였다.
*/


#include <string>
#include <vector>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int arr[12][12]={
        {0, 4, 3, 4, 3, 2, 3, 2, 1, 2},
        {4, 0, 1, 2, 1, 2, 3, 2, 3, 4},
        {3, 1, 0, 1, 2, 1, 2, 3, 2, 3},
        {4, 2, 1, 0, 3, 2, 1, 4, 3, 2},
        {3, 1, 2, 3, 0, 1, 2, 1, 2, 3},
        {2, 2, 1, 2, 1, 0, 1, 2, 1, 2},
        {3, 3, 2, 1, 2, 1, 0, 3, 2, 1},
        {2, 2, 3, 4, 1, 2, 3, 0, 1, 2},
        {1, 3, 2, 3, 2, 1, 2, 1, 0, 1},
        {2, 4, 3, 2, 3, 2, 1, 2, 1, 0},
        {1, 3, 4, 5, 2, 3, 4, 1, 2, 3}, // *
        {1, 5, 4, 3, 4, 3, 2, 3, 2, 1}  // #
    };
    int curL = 10;
    int curR = 11;
    for(auto i : numbers){
        if(i==1 || i==4 || i==7){
            answer+="L";
            curL = i;
        } else if(i==3 || i==6 || i==9){
            answer+="R";
            curR = i;
        } else{
            if(arr[curL][i] == arr[curR][i]){
                if(hand == "right"){
                    answer+="R";
                    curR = i;
                } else{
                    answer+="L";
                    curL = i;
                }
            }
            else{
                int minDis = min(arr[curL][i], arr[curR][i]);
                if(minDis == arr[curL][i]){
                    answer+="L";
                    curL = i;
                } else{
                    answer+="R";
                    curR = i;
                }
            }
        }
        
    }
    
    
    return answer;
}