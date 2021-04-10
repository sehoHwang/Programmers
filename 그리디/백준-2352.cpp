/** 솔루션 **/

/*
    1. dp를 이용한 LIS(최장 증가 수열)은 n^2의 시간 복잡도를 가지므로 lower_bounder를 사용해서 해결.

    2. cache라는 배열을 선언 후 cache[1] = arr[1]를 대입하고 cache의 현재 최대 인덱스를 가리키는 size를 1로 초기화 한다.

    3. arr의 인덱스를 증가시키며 현재 cache[size]보다 클 경우 size를 늘려 대입한다.

    4. 그렇지 않을 경우, lower_bounder를 사용해 최적의 자리에 대입을 한다.
*/

#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int n;
int ans = 0;
int arr[40001];
int cache[40001];

int main(){
    int tmp;
    int size = 1;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    
    cache[1] = arr[1];
    
    for(int i=2; i<=n; i++){
        if(cache[size] < arr[i]){
            cache[++size] = arr[i];
            continue;
        }
        int it = lower_bound(cache+1, cache+size+1, arr[i])-cache;
        cout<<"it : "<<it<<endl;
        cache[it] = arr[i];
    }
    
    cout<<size;
    return 0;
}