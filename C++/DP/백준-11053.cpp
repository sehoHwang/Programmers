/** 솔루션 **/

/*
    1. LIS(가장 긴 증가하는 부분 수열) 기법 사용

    2. lower_bound를 사용한다.
*/


#include <iostream>
#include <vector>

using namespace std;
int n;
int arr[1001];
int result[1001];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    result[1] = arr[1];
    int size = 1;
    for(int i= 2; i<=n; i++){
        if(result[size] < arr[i]){
            result[++size] = arr[i];
        }
        else{
            auto it = lower_bound(result+1, result+size+1, arr[i])-arr;
            arr[it] = arr[i];
        }
    }

    cout<<size;

    return 0;
}