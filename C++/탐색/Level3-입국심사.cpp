/** 솔루션 **/

/*
    1. 이분 탐색
    
*/


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
long long tmpresult = 0;
long long isCorrect(long long x, vector<int> times){
    long long result = 0;
    for(int i=0; i<times.size(); i++){
        result += x/times[i];
    }
    return result;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long new_n = (long long)(n);
    long long num = times.size();
    long long s = 1;
    long long e = (long long)times[times.size()-1]*(long long)n;
    long long answer = e;
    long long mid;
    int count = 0;
    while(s <= e) {
        mid = (s + e) / 2;

        long long corr = isCorrect(mid, times);
        
        if(corr < n){
            s = mid + 1;
        }
        else{
            if(mid<=answer)
                answer = mid;
            e = mid-1;
        }
    }
    
    return answer;
}