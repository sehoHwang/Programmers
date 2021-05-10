/** 솔루션 **/

/*
    전형적인 DP 문제

    1. dp[max] 배열 생성

    2. vector<int> v에 입력값들 저장

    3. dp를 인덱스를 하나씩 늘려가면서 저장하는데, 이전 값과의 합이 현재 인덱스의 v값보다 크면 dp[i]를 이전 값과의 합으로 갱신

    4. dp[i] 갱신 후 ans와 dp[i]를 비교. (이전 값들의 합의 최대값보다 현재 값이 높을 수 있으니)
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int tmp;
    int dp[100001];
    scanf("%d", &n);
    vector<int> v;
    for(int i=0; i<n; i++){
        cin>>tmp;
        dp[i] = tmp;
        v.push_back(tmp);
    }
    int ans = v[0];
    dp[0] = v[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1]+ v[i], v[i]);
        ans = max(ans, dp[i]);    
    }

    cout<<ans;
    
    return 0;
}