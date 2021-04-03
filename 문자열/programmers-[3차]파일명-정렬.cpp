/** 솔루션 **/

/*
    1. tmp_files 벡터를 생성해 files의 모든 알파벳을 소문자로 통일시켜 저장

    2. 문자열(head), 숫자(number), 문자열에 해당하는 tmp_files상의 인덱스를 tuple<string, string, int>자료구조 사용해서 저장
    -> 추후에 원본 문자열을 인덱스를 통해 출력하기 위해
    
    3. head와 number가 같을 시, 기존 순서대로 출력시키기 위해 stable_sort STL을 사용 
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;

bool compare(tuple<string, string, int> v1, tuple<string, string, int> v2){
    
    if(get<0>(v1) == get<0>(v2)){
        return atoi(get<1>(v1).c_str()) < atoi(get<1>(v2).c_str());
    }
    else if(get<0>(v1) == get<0>(v2) && get<1>(v1) == get<1>(v2)){
        return v1 < v2;
    }
    else{
        return get<0>(v1) < get<0>(v2);
    }
}

bool test_compare(string v1, string v2){
    return atoi(v1.c_str()) < atoi(v2.c_str());
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> tmp_files;
    vector<tuple<string,string,int>> v;
    tmp_files = files;
    
    for(int i=0; i<tmp_files.size(); i++){
        for(int j=0; j<tmp_files[i].length(); j++){
            tmp_files[i][j] = tolower(tmp_files[i][j]);
        }
    }
    
    for(int i=0; i<files.size(); i++){
        int j=0;
        string head = "";
        string number = "";
        while(!(tmp_files[i][j]<='9' && tmp_files[i][j]>='0') && j!=tmp_files[i].size()){
            head+=tmp_files[i][j];
            j++;
        }
        while(tmp_files[i][j]<='9' && tmp_files[i][j]>='0' && j!=tmp_files[i].size()){
            number += tmp_files[i][j];
            j++;
        }
        v.push_back(make_tuple(head, number, i));
    }
    
    stable_sort(v.begin(), v.end(), compare);

    
    for(int i=0; i<v.size(); i++){
        int index = get<2>(v[i]);
        answer.push_back(files[index]);
    }
    
    return answer;
}