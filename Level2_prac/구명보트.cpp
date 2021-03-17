/** 문제설명 **/

/*
    무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

    예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

    구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

    사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

*/

/** 솔루션 **/

/*
    1. 오름차순으로 정렬을 한다.
    2. 맨 앞 값과 맨 뒷 값을 더했을 때 limit을 초과하면 맨 뒷 값만 빼준다.
    3. limit을 초과하지 않으면 둘 값을 뺀다.
    
    * 효율성을 위한 sol
     
    * 맨 뒷 값이 limit/2 보다 작거나 같을 시에는 무조건 2명씩 탈 수 있으므로 바로 answer를 구한다.
    
    * pop_back()을 사용할 때 시간 초과가 발생하였다. 이를 방지하기 위해, 실제로 vector에서 값을 지우는게 아니라 인덱스값만 증감시켜서 해결하였다.
    * 
    * while문 조건을 (s<=e)로 잡았다.
    
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int convertA(char a){
    return min(a-'A', 'Z'-a+1);
}

int solution(string name) {
    int answer = 0;
    int cur = 0;
    int n = name.length();
    int tmp = n-1;
    
    for(int i=0; i<name.length(); i++){
        if(name[i]=='A')
            cur = i;
        while(cur<name.length() && name[cur]=='A')
            cur++;
        if(i==0)
            //tmp = min(tmp, i+n-cur+min(i, n-cur));
            tmp = min(tmp, n-cur);
        else
            tmp = min(tmp, (i-1)+n-cur+min(i-1, n-cur));
        
        answer += convertA(name[i]);
    }
    
    answer += tmp;
    
    return answer;
}



