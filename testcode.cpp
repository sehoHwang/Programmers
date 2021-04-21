#include <iostream>
#include <map>

using namespace std;

int main(){
    multimap <int, int> m;

    m.insert(make_pair(1,10));
    m.insert(make_pair(1,15));
    m.insert(make_pair(5,15));
    m.insert(make_pair(5,11));
    m.insert(make_pair(5,12));
    m.insert(make_pair(4,10));
    m.insert(make_pair(2,10));
    
    for(auto &it : m){
        cout<<it.second;
    }

    return 0;
}