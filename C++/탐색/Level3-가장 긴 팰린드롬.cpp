/** 솔루션 **/

/*
    1. 이분탐색을 활용하였다.

    2. 똑같은 문자열로만 되어있을 경우에는 이분탐색 풀이로 테스트 케이스 12에서 오류가 나와 예외처리를 맨 처음에 진행해주었다.

    3. 코드가 복잡하지만 효율성에 있어서는 훌륭했다.
*/


#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int answer=1;
    int len = s.length();
    int equal = 0;
    for(int i=1; i<len; i++){
        if(s[0]==s[i])
            equal++;
    }
    if(equal+1 == len)
        return len;
    
    for(int i=1; i<len-1; i++){
        int left = i-1;
        int right = i+1;
        int flag = 0;
        int continous = 1;
        while(left>=0 && right<=len-1){
            char l = s[left];
            char r = s[right];
            
            if(l==s[i] && flag==0){
                continous++;
                left--;
                continue;
            }
            if(r==s[i] && flag==0){
                continous++;
                right++;
                continue;
            }
            flag = 1;
            if(l==r){
                continous+=2;
                left--;
                right++;
            }
            else
                break;
        }
        if(continous>answer)
            answer = continous;
    }
    return answer;
}