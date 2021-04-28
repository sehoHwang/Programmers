/** 솔루션 **/

/*
    1. 장르 별로 노래가 속해 있으며, 노래 별로 고유 번호가 있다.(index)

    2. 장르 별로 재생시간이 긴 노래를 2개 선택해 앨범에 담는 문제이다.

    3. 장르 별 전체 재생시간이 긴 장르부터 앨범에 담는다.
    -> 즉, 장르 별 재생시간에 대해 sort, 장르 전체 재생시간에 대한 sort 총 두 개의 sort가 필요하다.

    4. 자료구조는 unordered_map<string, vector<pair<int,int>>>와
               unordered_map<string, int>를 사용하였다.
*/


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare_m(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

bool compare_total(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,vector<pair<int,int>>> m;
    unordered_map<string,int> total;
    vector<pair<string,int>> total_v;
    for(int i=0; i<genres.size(); i++){
        m[genres[i]].push_back(make_pair(plays[i], i));
        total[genres[i]] += plays[i];
    }
    
    for(auto &it : m){
        sort(it.second.begin(), it.second.end(), compare_m);
    }
    
    total_v.assign(total.begin(), total.end());
    sort(total_v.begin(), total_v.end(), compare_total);
    
    for(int i=0; i<total_v.size(); i++){
        string tmp = total_v[i].first;
        for(int j=0; (j<m[tmp].size()) && (j<2); j++){
            answer.push_back(m[tmp][j].second);
        }
    }
    
    return answer;
}