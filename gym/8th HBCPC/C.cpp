#include <algorithm>
#include <iostream>
#include <set>
#include <iostream>
#include <vector>
#include <queue>

const int Max_n = 2e6 + 5;

struct node
{
    int l , r , id;
}a[Max_n];

#define fi first
#define se second
#define PII std::pair<int , int>

std::priority_queue< PII , std::vector<PII> , std::greater<PII> > s;

int n , cnt;

std::vector<int> ans;

bool cmp(node a , node b)
{
    return a.l < b.l;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 1 ; i <= n ; ++ i)
    {
        int x , y;
        std::cin >> x >> y;
        a[i] = {x , y , i};
    }

    std::sort(a + 1 , a + n + 1 , cmp);

    int j = 1;

    for(int i = 0 ; i < n ; ++ i)
    {
        while(j <= n && a[j].l <= i)
            s.push({a[j].r , a[j].id}), ++ j;
 
        while(s.size() && s.top().fi < i)
            s.pop();

        if(s.empty())
        {
            break;
        }
        else
        {
            ans.push_back(s.top().se);
            s.pop();
            ++ cnt;
        }

    }

    std::cout << cnt << '\n';

    for(int i = 0 ; i < ans.size() ; ++ i)
        std::cout << ans[i] << ' ';
    std::cout << '\n';
}