#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
#define Max 55
 
int n, ans = -1;
vector<int> v[Max];
bool visit[Max];
 
int bfs(int start)
{
    memset(visit, false, sizeof(visit));
    visit[start] = true;
 
    queue<pair<int, int> > q;
    q.push({ start, 0 });
 
    while (!q.empty())
    {
        int qs = q.size();
 
        while (qs--)
        {
            int here = q.front().first;
            int len = q.front().second;
 
            q.pop();
 
            if (len >= 2) {
                continue;
            }
 
            for (auto next : v[here]) {
                if (!visit[next]) {
                    visit[next] = true;
                    q.push({ next, len + 1 });
                }
            }
        }
    }
 
    int ret = 0;
 
    for (int i = 0; i < n; i++) {
        if (visit[i] && i != start) {
            ++ret;
        }
    }
 
    return ret;
}
 
int main()
{
    //freopen("C:\\Users\\park7\\Desktop\\sample_input.txt", "r", stdin);
    cin.tie(0);
    scanf("%d", &n);
    getchar();
 
    char c;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == 'Y') {
                v[i].push_back(j);
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        ans = max(ans, bfs(i));
    }
 
    printf("%d\n", ans);
 
    return 0;
}
