#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];
int total;

int main(){
    int n;
    int answer;
    int count = 0;
    scanf("%d", &n);
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+1;
        if(i%3==0)
            dp[i] = min(dp[i],dp[i/3]+1);
        if(i%2==0)
            dp[i] = min(dp[i],dp[i/2]+1);
    }

    printf("%d", dp[n]);
    return 0;
}