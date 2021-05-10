#include <iostream>

using namespace std;

int arr[1001][10]; // arr[단계 수][끝자리 수]

int main(){
    int result = 0;
    int n;
    scanf("%d", &n);

    for(int i=0; i<=9; i++){
        arr[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        arr[i][0] = arr[i-1][0];
        for(int j=1; j<=9; j++){
            for(int z = 0; z<=j; z++){
                arr[i][j] += (arr[i-1][z])%10007;
            }
        }
    }
    
    for(int i=0; i<=9; i++){
        result = (result + arr[n][i])%10007;
    }
    cout<<result;
    return 0;
}