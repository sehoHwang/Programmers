/** 문제설명 **/

/*
    124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.
        1. 124 나라에는 자연수만 존재합니다.
        2. 124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.
        10 진법     1   2   3   4   5   6   7   8   9   10
        124 나라    1   2   4   11  12  14  21  22  24  41
*/

/** 솔루션 **/

/*
    규칙을 찾는 것이 point!
    -나머지가 1일 경우 : 1
    -나머지가 2일 경우 : 2
    -나머지가 0일 경우 : 4
    를 answer에 더해주는데 3을 예로 들면 몫이 1이 남기 때문에 1을 빼줘야 한다.
    즉 입력값 n에 대해 3에 의해 나눠지는 경우에는 몫에 1을 추가로 빼주어서 해결하였다.
*/


#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int q,r;
    while(n){
        q = n/3;
        r = n%3;
        
        if(r == 1){
            answer = '1'+answer;
            n=q;
        }
        else if(r == 2){
            answer = '2'+answer;
            n=q;
        }
        else if(r == 0){
            answer = '4'+answer;
            n=q-1;
        }
    }
    
    return answer;
}
