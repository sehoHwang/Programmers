#include <iostream>
#include <string>
#include <vector>
using namespace std;

string change(string tmp){
    int sF, sE;
    int flag = 0;
    string op;
    string result = "";
    for(int i=0; i<tmp.length()-1; i++){
        if(tmp[i]=='+' || tmp[i]=='*' || tmp[i]=='-' || tmp[i]=='/'){
            flag++;
            sF = stoi(tmp.substr(0, i+1));
            op = tmp.substr(i,1);
            sE = stoi(tmp.substr(i+1));
            if(flag==1){
                result+=to_string(sF)+op+to_string(sE);
            }
            else
                result+=op+to_string(sE);
        }
    }
    return result;
}

int main(){
    string S;
    vector<string> v;
    cin>>S;
    S = change(S);
    int len = S.length();
    int maxSum = 0;
    int idx;
    string tmp="";
    for(int i=0; i<S.length(); i++){
        if(S[i]>='0' && S[i]<='9'){
            tmp+=S[i];
            if(i==S.length()-1)
                v.push_back(tmp);
        }
        else{
            v.push_back(tmp);
            tmp = "";
            v.push_back(S.substr(i,1));
        
        }
    }
    
    for(auto i : v){
        cout<<i<<endl;
    }

    for(int i=0; i<v.size()-2; i++){
        int op1, op2;
        if(v[i]=="+"){
            op1 = stoi(v[i-1]);
            op2 = stoi(v[i+1]);
        } else if(v[i] == "-"){
            
        } else if(v[i] == "*"){
            
        } else if(v[i] == "/"){

        }
    }
 
    return 0;
}