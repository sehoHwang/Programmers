/** 문제설명 **/

/*
    Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

    Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

    Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.
*/

/** 솔루션 **/

/*
    yellow의 가로, 길이에 대한 모든 경우의 수를 구하기 위해

    1. getDivisor 함수를 통해 약수를 구한다. (vector, pair 자료구조를 사용)
    2. 반복문을 통해 yellow의 가로, 세로 길이가 언제일 때 brown을 만족하는지 구한다.
    
*/


#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


vector<pair<int, int>> getDivisor(int n){
    vector<pair<int, int>> d;
    
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            if(i==sqrt(n)){
                d.push_back(make_pair(i,i));
            }
            else{
                d.push_back(make_pair(i, n/i));
            }
        }
    }
    return d;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> d;
    
    d = getDivisor(yellow);
    
    int a, b;
    
    for(auto i : d){
        a = i.first+2;
        b = i.second+2;
        
        if(a*b-yellow == brown){
            answer.push_back(b);
            answer.push_back(a);
        }
    }
    
    return answer;
}


