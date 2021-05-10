/** 솔루션 **/

/*
    1. stack을 사용하여 쉽게 구현
*/

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int idx = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            idx++;
        }
        else{
            idx--;
            if(idx<0)
                return false;
        }
    }
    if(idx>0)
        return false;
    else 
        return true;

    return answer;
}