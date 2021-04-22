#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[100001];
int dp[100001];
int n;


int main(){
    
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    int result = arr[1], answer = arr[1];
    dp[1] = arr[1];
    for(int i=2; i<=n; i++){
        result += arr[i];
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        answer = max(answer, dp[i]);
    }

    cout<<answer;
    return 0;
}