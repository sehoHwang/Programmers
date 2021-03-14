/** 문제설명 **/

/*
    한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

    각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.
*/

/** 솔루션 **/

/*
    
    문제 해결을 위해선, 숫자로 만들 수 있는 모든 순열을 구한 후 중복 제거를 해준다.

    중복 제거가 된 순열들이 소수인지 아닌지 판별한다.

    1. 깊이우선탐색 (재귀)

    2. 백트래킹
    
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> result;
bool flag[7] = {false};
string tmp;

void dfs(string numbers, int cur_len){
    if(cur_len == numbers.length()){
        return;
    }
    for(int i=0; i<numbers.length(); i++){
        if(!flag[i]){
            flag[i] = true;
            tmp += numbers.substr(i,1);
            result.push_back(stoi(tmp));
            dfs(numbers, cur_len+1);
            tmp.pop_back();
            flag[i] = false;
        }
    }
}

bool isPrime(int a){
    if(a==0 || a==1){
        return false;
    }
    else if(a==2 || a==3){
        return true;
    }
    for(int i=2; i<=sqrt(a); i++){
        if(a%i==0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    dfs(numbers, 0);
    
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    for(auto i : result){
        if(isPrime(i))
            answer++;
    }
    
    return answer;
}

