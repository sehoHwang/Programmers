#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool calc(int n, int k, vector<int> stones){
    int cnt = 0;
    for(int i=0; i<stones.size(); i++){
        if(stones[i] - n <=0){
            cnt++;
        }
        else{
            cnt = 0;
        }
        if(cnt >= k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int s = 1;
    int e = *max_element(stones.begin(), stones.end());
    int mid;
    
    while(s<=e){
        mid = (s+e)/2;
        int calc_result = calc(mid, k, stones);
        if(!calc_result){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    answer = s;
    return answer;
}