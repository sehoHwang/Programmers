/** 솔루션 **/

/*
    1. 플로이드 와샬을 이용

    2. a가 b를 이기고, b가 c를 이길 경우, a가 c를 이긴 것에 true 표시

    3. 여기서 거쳐가야 하는 노드인 첫번째 for 문의 인자 i가 바로 b에 해당
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;
bool arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0; i<results.size(); i++){
        int y = results[i][0];
        int x = results[i][1];
        arr[y][x] = true;
    }
    
    for(int i=1; i<=n; i++){ // 거쳐야 하는 정점
        for(int j=1; j<=n; j++){ // 시작 정점
            for(int z=1; z<=n; z++){
                if(arr[j][i] && arr[i][z])
                    arr[j][z] = true;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(arr[i][j] || arr[j][i])
                count++;
        }
        if(count == n-1)
            answer++;
    }
    
    return answer;
}