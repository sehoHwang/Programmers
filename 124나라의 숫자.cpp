#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int q,r;
    while(n){
        q = n/3;
        r = n%3;
        
        if(r == 1){
            answer = '1'+answer;
            n=q;
        }
        else if(r == 2){
            answer = '2'+answer;
            n=q;
        }
        else if(r == 0){
            answer = '4'+answer;
            n=q-1;
        }
    }
    
    return answer;
}