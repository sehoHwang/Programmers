#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map <int, int> m;

    m.insert(make_pair(1,10));
    m.insert(make_pair(10,10));
    m.insert(make_pair(5,15));
    m.insert(make_pair(5,11));
    m.insert(make_pair(5,12));
    m.insert(make_pair(4,10));
    m.insert(make_pair(2,10));
    auto i = m.count(3);

    cout<<i;
    return 0;
}