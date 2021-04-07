/** 솔루션 **/

/*
    1. 시간 제한이 1초이기에 dfs가 아닌 이분탐색으로 해결

    2. 정렬을 수행한 후, 덧셈의 절댓값을 i, j를 통해 인덱스를 조절해가며 작은 값으로 변경

    3. sum이 0보다 작으면 i를 증가, 0보다 크거나 작으면 j를 감소시켜 0에 근접하게 함
*/


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int tmp;
    long long arr[100001];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);
    long long min = 100001;
    int i=0;
    int j = n-1;
    int index_i, index_j;
    while(i<j){
        long long sum = arr[i] + arr[j];

        if(llabs(sum) < min){
            min = llabs(sum);
            index_i = i;
            index_j = j;
        }

        if(sum<0)
            i++;
        else
            j--;
    }
    cout<<arr[index_i]<<" "<<arr[index_j]<<endl;

    return 0;
}