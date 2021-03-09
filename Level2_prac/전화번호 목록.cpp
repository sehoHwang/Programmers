/** 문제설명 **/

/*
    전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
    전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

    구조대 : 119
    박준영 : 97 674 223
    지영석 : 11 9552 4421
    전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

*/

/** 솔루션 **/

/*
    이중 for문을 도는 풀이법이 있고, 미리 정렬을 한 후 for 문을 한번만 사용하는 풀이법이 있습니다.

    정렬을 하게 되면 인접한 문자열과 비교를 한번만 하면 됩니다.

    아이디어 자체는 후자가 좋았으나 효율성 테스트에서는 이중 for문을 사용한 것이 더 높은 점수를 받았습니다.
*/

/* 이중 for문 풀이법 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int len = phone_book.size();
    
    for(int i=0; i<len; i++){
        string tmp = phone_book[i];
        
        for(int j=0; j<len; j++){
            if(i==j) continue;
            if(phone_book[j].find(tmp)== 0){
               return false;
            }
        }
        
    }
    
    return answer;
}

/* 정렬 풀이법 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int len = phone_book.size();
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<len-1; i++){
        if(phone_book[i+1].find(phone_book[i])==0){
            return false;
        }
    }
    
    return answer;
}