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


/** 솔루션 **/

/*
    
    1. 처음 이 문제를 해결할때는 tmp 문자열을 전역 변수로 두고 pop_back()을 하면서 문제를 풀었다면

    2. 이번에는 전역 변수 없이 string 변수를 값 복사를 하면서 해결하였다.
    
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;
int len;
vector<int> v;
bool visit[7];

bool isPrime(int x){
    if(x==0 || x==1)
        return false;
    else if(x==2 || x==3)
        return true;
    
    for(int i=2; i<=sqrt(x); i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
    
}

void dfs(string s, int total, string numbers){
    
    int num = stoi(s);
    if(isPrime(num)){
        v.push_back(num);
    }
    
    if(total == len)
        return;
    
    
    for(int i=0; i<len; i++){
       if(!visit[i]){
           string tmp = s + numbers.substr(i,1);
           visit[i] = true;
           dfs(tmp, total+1, numbers);
           visit[i] = false;
       }
    }
}

int solution(string numbers) {
    int answer = 0;
    len = numbers.length();
    
    for(int i=0; i<len; i++){
        string tmp = numbers.substr(i,1);
        visit[i] = true;
        dfs(tmp, 1, numbers);
        visit[i] = false;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    answer = v.size();
    return answer;
}