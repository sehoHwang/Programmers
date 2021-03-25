#include <iostream>
#include <vector>

using namespace std;
// for git test
int main() {
    int N, P, V;
    vector<int> n;
    vector<int> p;
    vector<int> v;
    vector<int> result;

    while(1){
        scanf("%d %d %d", &N, &P, &V);
        if(N==0 && P == 0 && V==0)
            break;
        else{
            n.push_back(N);
            p.push_back(P);
            v.push_back(V);
        }
    }
    for(int i=0; i<n.size(); i++){
        int cnt = v[i]/p[i];
        int tmp;
        if(v[i]%p[i] > n[i])
            tmp = n[i]*cnt + n[i];
        else
            tmp = n[i]*cnt + v[i]%p[i];
        
        result.push_back(tmp);
    }

    for(int i=0; i<result.size(); i++){
        if(i==result.size()-1)
            cout<<"Case "<<i+1<<": "<<result[i];
        else{
            cout<<"Case "<<i+1<<": "<<result[i]<<endl;
        }
    }
}