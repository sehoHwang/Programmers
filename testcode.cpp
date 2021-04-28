#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

int arr[100001];
int dp[100001];
int n;


int main(){
    
    unordered_map<string,int> m;
    m.insert(make_pair("naver", 1));
    m.insert(make_pair("coupang", 2));
    m.insert(make_pair("webtoon", 3));
    for(auto it : m)
        cout<<it.first<<endl;
    return 0;
}