#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int length;
int result = 0;
vector<string> v;

void dp(string str){
    string tmp;
    int len = str.length();
    /*if(len==length){
        auto i = find(v.begin(), v.end(), str);
        if(i==v.end()){
            v.push_back(str);
            result++;
        }
    }*/
    if(len > length)
        return;
    auto i = find(v.begin(), v.end(), str);
    if(i==v.end()){
        v.push_back(str);
        int num = str[len-1]-'0';
        tmp = to_string(num+1);
        if(num+1<10){
            tmp = to_string(num+1);
            dp(str+tmp);
        }

        if(num-1>=0){
            tmp = to_string(num-1);
            dp(str+tmp);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    length = n;
    string str = "";
    for(int i=1; i<=9; i++){
        str = to_string(i);
        dp(str);
    }

    for(auto i : v){
        if(i.length()==n){
            result++;
        }
    }

    //sort(v.begin(), v.end());
    
    //v.erase(unique(v.begin(), v.end()), v.end());

    //for(auto i : v) {
      //  cout<<"result : "<<i<<endl;
    //}

    cout<<result%1000000000;

    return 0;
}