/** 문제설명 **/

/*
    조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.

    ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA
*/

/** 솔루션 **/

/*
    converA 함수 : 입력 문자열에서 A가 되는 길이 중 짧은 값을 반환.

    총 4가지 케이스에 대해서 생각을 해보았다.

    1) A로 이루어진 문자열이 가운데에 위치하고, 전체 문자열 시작점 - A로 이루어진 문자열 시작점이 작은 경우
    2) 1)과 동일한 조건에서 전체 문자열 끝 - A로 이루어진 문자열 끝이 더 작은 경우
    3) 모든 문자열이 A로 이루어진 경우
    4) 왼쪽으로 쭉 방문할 경우

    변수 tmp를 name의 길이-1로 설정을 하고, 1), 2), 3) 경우 중 min 값을 반환하게 코드를 작성하였다.

    또한, A가 name[0]에 위치할 경우에는 4)의 경우로 적용하였다.    
    
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int convertA(char a){
    return min(a-'A', 'Z'-a+1);
}

int solution(string name) {
    int answer = 0;
    int cur = 0;
    int n = name.length();
    int tmp = n-1;
    
    for(int i=0; i<name.length(); i++){
        if(name[i]=='A')
            cur = i;
        while(cur<name.length() && name[cur]=='A')
            cur++;
        if(i==0)
            //tmp = min(tmp, i+n-cur+min(i, n-cur));
            tmp = min(tmp, n-cur);
        else
            tmp = min(tmp, (i-1)+n-cur+min(i-1, n-cur));
        
        answer += convertA(name[i]);
    }
    
    answer += tmp;
    
    return answer;
}



