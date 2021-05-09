/** 문제설명 **/

/*
    문자열 압축
    ex) aabbccdd => 2a2b2c2d은 문자를 1씩 나눴을 경우
        ababcdcdababcdcd => 2ab2cd2ab2cd는 문자를 2씩 나눴을 경우
    길이를 몇으로 잘라서 문자를 압축해야 제일 짧아지는지 구하는 문제

*/

/** 솔루션 **/

/*
    문자 길이의 절반보다 큰 수는 나누어도 압축 정도에 변화가 없으므로 1~length까지의 테스트 케이스를 for문으로 구현

    substr 함수를 사용해 간단하게 비교

    * 비교 시 문자열이 다를 때 count가 1일 경우엔 tmp에 그대로 넣지만, 1보다 클 경우에는 to_string(count)를 추가하여 넣어줌
*/



#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string result="";
    int answer = 0;
    int min = s.length();
    int count;
    for(int i=1; i<=s.length()/2; i++){
       string tmp = s.substr(0,i);
        count = 1;
        result="";
        for(int j=i; j<=s.length(); j+=i){
            if(tmp == s.substr(j,i))
               count++;
               
            else{
                if(count==1){
                    result+=tmp;
                }
                else{
                    result+=(to_string(count)+tmp);
                    
                }
                tmp = s.substr(j,i);
                    count = 1;
            }
        }
        
        if(s.length()%i != 0){
            result+=s.substr((s.length()/i)*i);
        }
        
        if(min > result.length()){
            min = result.length();
        }
    }
    
    answer = min;
    
    return answer;
}