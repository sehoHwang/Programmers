/** 솔루션 **/

/*
    전형적인 DP 문제

    total 2차원 배열을 두고 저장해두어 필요없는 연산을 스킵한다.
*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int total[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    total[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); i++){
        for(int j=0; j<triangle[i].size(); j++){
            if(total[i][j] < total[i-1][j] + triangle[i][j])
                total[i][j] = total[i-1][j] + triangle[i][j];
            if(j+1<=triangle[i].size()-1 && total[i][j+1] < total[i-1][j] + triangle[i][j+1])
                total[i][j+1] = total[i-1][j] + triangle[i][j+1];
        }
    }
    int h = triangle.size();
    int max = 0;
    for(auto i : total[h-1]){
        if(max < i)
            max = i;
    }
    return max;
}