/** 문제설명 **/

/*
    0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

*/

/** 솔루션 **/

/*
    string vector에 차례대로 넣은 후  합쳐서 큰 순으로 정렬하였다.
    
    예를 들면, [6, 10, 2]가 있다고 하자. "6" + "10" 을 합친 "610"이 "10" + "6"을 합친 "106" 보다 크므로 return a+b > b+a;를 반환해준다.

    또한, v.at(0)을 사용함으로써 정렬 후 벡터의 첫번째 원소가 0일 경우는 모든 수가 0임을 뜻하므로 0을 반환해준다.
*/



#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    string tmp="";
    vector<string> v;
    
    for(int i=0; i<numbers.size(); i++){
        tmp=to_string(numbers[i]);
        
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), compare);
    
    if(v.at(0) == "0")
        return "0";

    for(string a : v)
        answer+=a;
    
    return answer;
}