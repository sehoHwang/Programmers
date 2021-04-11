#include <cstdio>
#include <queue>

using namespace std;

#define MAX 100000

int main() {

    bool v[MAX+1] = { false, };
    queue<int> q;
    bool traverse;

    int n, k, i, seg = 1, cnt, ans = 0;

    scanf("%d %d", &n, &k);
    q.push(n);

    while(!q.empty()) {
        cnt = 0;
        traverse = false;
        for (i = 0; i < seg; i++) {
            int x = q.front();
            q.pop();

            if (x == k) {
                printf("%d\n", ans);
                return 0;
            }
            v[x] = true;

            if (x + 1 <= MAX && !v[x+1]) {
                q.push(x + 1);
                traverse = true;
                cnt++;
            }
            if (x - 1 >= 0 && !v[x-1]) {
                q.push(x - 1);
                traverse = true;
                cnt++;
            }
            if (2 * x <= MAX && !v[2*x]) {
                q.push(2 * x);
                traverse = true;
                cnt++;
            }            
        }
        seg = cnt;
        if (traverse) ans++;
    }

    printf("%d\n", ans);


    return 0;
}