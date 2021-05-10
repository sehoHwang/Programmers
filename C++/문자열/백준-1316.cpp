/** 솔루션 **/

/*
    1. 패키징된 문자열이라면 정렬을 하지않고 중복제거를 한 경우와 정렬을 하고 중복제거를 진행했을때, 길이가 같아야 한다는 조건을 사용하였다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

int main(){
    vector<vector<char>> v;
    int n;
    string tmp;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin>>tmp;
        vector<char> tv;
        for(int j=0; j<tmp.length(); j++){
            tv.push_back(tmp[j]);
        }
        v.push_back(tv);
    }
    
    for(int i=0; i<n; i++){
        vector<char> temp;
        temp = v[i];
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        if(v[i].size() == temp.size())
            answer++;

    }

    cout<<answer;

    return 0;
}