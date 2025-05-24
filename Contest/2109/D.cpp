#include <bits/stdc++.h>

typedef long long ll;

const int Max_n = 2e5 + 5;

std::vector<int> v[Max_n];

int n , m , l , a[Max_n] , dis[2][Max_n];

ll odd , even;

bool vis[2][Max_n];

std::queue<std::pair<int , int> > q;

void bfs()
{
    dis[0][1] = 0;
    vis[0][1] = true;
    q.push({1 , 0});

    while(q.size())
    {
        auto [now , t] = q.front();
        q.pop();

        for(int nex : v[now])
        {
            if(vis[t ^ 1][nex]) continue;
            vis[t ^ 1][nex] = true;
            dis[t ^ 1][nex] = dis[t][now] + 1;

            q.push({nex , t ^ 1});
        }
    }
}

void solve()
{
    std::cin >> n >> m >> l;
    for(int i = 1 ; i <= n ; ++ i)
        dis[0][i] = dis[1][i] = 1e9 , vis[0][i] = vis[1][i] = false;
    
    for(int i = 1 ; i <= n ; ++ i)
        v[i].clear();
    
    for(int i = 1 ; i <= l ; ++ i)
        std::cin >> a[i];
    
    odd = even = 0;
    int mina = 2e9;
    for(int i = 1 ; i <= l ; ++ i)
    {
        odd += a[i];
        if(a[i] & 1)
            mina = std::min(mina , a[i]);
    }
    
    if(odd & 1)
        even = odd - mina;
    else even = odd , odd -= mina;

    for(int i = 1 ; i <= m ; ++ i)
    {
        int x , y;
        std::cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs();

    for(int i = 1 ; i <= n ; ++ i)
    if((vis[0][i] && dis[0][i] <= even) || (vis[1][i] != 1e9 && dis[1][i] <= odd))
        printf("1");
    else printf("0");

    puts("");
}

int main()
{
    int T;
    std::cin >> T;
    while(T --)
        solve();
}
