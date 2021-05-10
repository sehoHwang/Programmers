#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> m;
vector<long long> answer;
long long find_num(long long num){
    if(m[num] == 0){
        m[num] = num+1;
        answer.emplace_back(num);
        return num;
    }
    return m[num] = find_num(m[num]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    for(int i=0; i<room_number.size(); i++){
        long long num = room_number[i];
        if(m[num] == 0){
            m[num] = num+1;
            answer.emplace_back(num);
        }
        else{
            find_num(m[num]);
        }
    }
    
    return answer;
}