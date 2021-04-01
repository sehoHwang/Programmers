#include <iostream>

using namespace std;

typedef enum {
    lparen, rparen, plus, minus,
    times, divide, mode, eos, operand
} precedence;

int main(){
    precedence token;
    token = times;
    cout<<token;
    return 0;
}