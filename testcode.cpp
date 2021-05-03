#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

int arr[100001];
int dp[100001];
int n;

int test[20][20];
int main(){

    fill(&test[0][0], &test[20][20], 25*25*500);
    
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            cout<<test[i][j]<<" ";
        }
        printf("\n");
    }
    return 0;
}