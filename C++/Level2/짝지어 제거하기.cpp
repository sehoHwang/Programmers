/** 솔루션 **/

/*
    1. 짝지어 제거가 가능할때마다 인덱스를 조정하면 O(n)을 초과하므라 시간 초과가 나온다.

    2. stack을 사용하여 push를 하면서 top과 같을 경우 pop을 하는 방식으로 구현하였다.
*/


#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<char> fifo;

int solution(string s)
{
    int answer = 0;
    
    for(int i=0; i<s.length(); i++){
        if(!fifo.empty()){
            if(s[i] == fifo.top()){
                fifo.pop();
                continue;
            }
            else
                fifo.push(s[i]);
        }
        else
            fifo.push(s[i]);
    }
    
    if(fifo.empty())
        return 1;
    
    return answer;
}