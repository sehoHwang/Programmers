/** 솔루션 **/

/*
    1. 문자열의 길이가 원래 길이 - k가 될 때까지 현재 숫자가 다음 숫자보다 작으면 삭제를 진행하였다.

    2. 만약 문자 끝까지 탐색했는데도 더 큰 수를 만나지 못하면 내림차순인 것이기에 while문에서 탈출한다.

    3. 탈출 후 뒷 자리부터 빼준다.
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
string solution(string number, int k) {
	string answer = "";
    int max = number[0]-'0';
    int slice=0;
    int flag = 0;
    int idx;
    int len = number.length()-k;
    while(number.length() != len){
        for(int i=0; i<number.length(); i++){
            if(number[i] < number[i+1]){
                number.erase(i,1);
                break;
            }
            if(i==number.length()-1)
                idx = i;
        }
        if(idx==number.length()-1){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        int i=0;
        while(number.length()!=len){
            number.erase(number.length()-1,1);
        }
    }
    answer = number;
	return answer;
}