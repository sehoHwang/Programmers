#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L, l;
    int answer = 0;
    vector<int> loc;
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++){
        scanf("%d", &l);
        loc.push_back(l);
    }

    sort(loc.begin(), loc.end());
    int idx = 0;
    while(1){
        if(idx == loc.size()-1){
            answer++;
            break;
        }
        int tmp = loc[idx];
        int jump = 0;
        while(loc[idx+jump+1]-loc[idx] <= L-1){
            jump++;
            if(idx+jump==loc.size()-1)
                break;
        }
        idx += jump;
        answer+=1;
        
        idx++;
    }
    
    cout<<answer;

    return 0;
}