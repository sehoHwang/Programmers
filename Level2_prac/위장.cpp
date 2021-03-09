/** 문제설명 **/

/*
    스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

    예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 
    
    다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

    즉, 겹치지 않는 의상 조합을 선택하되 종류 당 최대 하나의 아이템만 착용이 가능합니다.
*/

/** 솔루션 **/

/*
    -map을 사용

    - find함수를 사용해 map에서 해당 종류가 발견될 시, 숫자를 증가시키고
      발견을 못할 시에는 map을 추가한다.

*/


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for(auto i : clothes){
        if(m.find(i[1]) == m.end()){
            m.insert(make_pair(i[1], 1));
        }
        else{
            m.find(i[1]) -> second ++;
        }
    }
    
    for(auto i=m.begin(); i!=m.end(); i++){
        answer *= (i->second+1);
    }
    
    
    return answer-1;
}