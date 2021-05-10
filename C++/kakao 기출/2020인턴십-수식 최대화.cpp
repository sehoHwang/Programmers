/** 솔루션 **/

/*
    1. 우선순위의 전체 조합에 대해 순열(next_permutation)을 사용하였다.

    2.  
        - vector<char> exp -> 식에 있는 중복되지 않는 연산자를 저장하는 벡터

        - vector<char> exp_loc -> 후에 피연산자 두개를 연산하기 위해 존재하는 연사자들을 순서대로 저장하는 벡터

        - vector<long long> num -> 숫자만 저장하는 벡터

    3. next_permutation을 사용해 exp에 대한 순열을 while문으로 돌린다.

    4. 각 exp 순서에 대해 연산을 한다.

    5. 각 while문마다 최댓값을 찾는다.

    <<< 식이 있는 문자열을 계산할 때, 문자열 자체에서 순회하여 연산을 하고 다시 문자열에 저장하는 것보다는

    각 속성 값에 해당하는 벡터를 통해 인덱스로 접근해 연산을 하는 것이 훨씬 간단하니 다음에는 이 방법을 사용해볼 것! >>>

*/


#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long answer = 0;
vector<char> exp;
vector<char> exp_loc;
vector<long long> num;

long long solution(string expression) {

    string tmp = "";
    for(int i=0; i<expression.size(); i++){
        
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
            num.push_back(stoll(tmp));
            tmp="";
            if(find(exp.begin(), exp.end(), expression[i]) == exp.end()){
                exp.push_back(expression[i]);
            }
            exp_loc.push_back(expression[i]);
        }
        else{
            tmp += expression[i];
        }
    }
    num.push_back(stoll(tmp));
    sort(exp.begin(), exp.end());
    do{
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = exp_loc;
        
        for(int i=0; i<exp.size(); i++){
            for(int j=0; j<tmp_loc.size(); j++){
                if(exp[i] == tmp_loc[j]){
                    if(exp[i] == '*'){
                        tmp_num[j] = tmp_num[j] * tmp_num[j+1];
                    } else if(exp[i] == '+'){
                        tmp_num[j] = tmp_num[j] + tmp_num[j+1];
                    } else{
                        tmp_num[j] = tmp_num[j] - tmp_num[j+1];
                    }
                    tmp_loc.erase(tmp_loc.begin() + j);
                    tmp_num.erase(tmp_num.begin() + j+1);
                    j--;
                }
            }
        }
        answer = max(answer, abs(tmp_num[0]));
    }while(next_permutation(exp.begin(), exp.end()));
    
    
    return answer;
}