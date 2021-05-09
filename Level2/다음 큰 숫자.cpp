/** 솔루션 **/

/*
    1. 이진수로 변환 후 1의 갯수를 구해주는 함수를 구현하면 끝!
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countOne(int x){
    string tmp = "";
    int r, m;
    int cnt = 0;
    while(x!=0){
        r = x%2;
        m = x/2;
        tmp = to_string(r) + tmp;
        x = x/2;
    }
    if(m==1)
        tmp = "1"+tmp;
    for(int i=0; i<tmp.length(); i++){
        if(tmp[i]=='1'){
            cnt++;
        }
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cur = countOne(n);
    while(1){
        n++;
        if(countOne(n) == cur){
            return n;
        }
    }
    return answer;
}