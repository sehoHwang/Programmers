/** 문제설명 **/

/*
    어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

    어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

*/

/** 솔루션 **/

/*
    citations를 오름차순으로 정렬을 시킨 후, 제시된 조건에 맞게 if문을 사용하여 해결하였습니다.

    처음에 테스트 케이스 11이 계속 실패하였는데 문제를 잘못 이해하고 코드를 짜서 발생한 오류였습니다.
    *if(cnt == i) 를 if(cnt >= i)로 수정
*/



#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int cnt, cnt2, max;
    
    sort(citations.begin(), citations.end());
    int iter = citations.back();
    max = 0;
    for(int i=0; i<=iter; i++){
        cnt = 0;
        cnt2 = 0;
        for(int a : citations){
            if(a >= i){
                cnt++;
            }
            else{
                cnt2++;
            }
        }
        if(cnt >= i){
            if(cnt2 <= cnt){
                if(max < i){
                    max = i;
                }
            }
        }
    }
    
    answer = max;
    
    return answer;
}