#include <iostream>

const int mod = 1e9 + 7;

typedef long long ll;

int a[20];

long long quickpow(ll x , int y)
{
    long long ret = 1;
    for(; y ; y >>= 1 , x = x * x % mod)
        if(y & 1) 
            ret = ret * x % mod;
    
    return ret;
}

long long calc(ll x , int t)
{
    ll ret = 0 , base = 10;
    for(; t ; t >>= 1 , x = (x * base + x) % mod , base = base * base % mod)
        if(t & 1)
            ret = (ret * base + x) % mod;
    
    return ret;
}

void solve()
{
    int m;
    std::cin >> m;
    for(int i = 0 ; i <= 9 ; ++ i)
        std::cin >> a[i];
    
    if(m == 1)
    {
        for(int i = 0 ; i <= 9 ; ++ i)
            if(a[i])
            {
                std::cout << i << '\n';
                return;
            }
    }

    long long ans = 0;

    for(int i = 1 ; i <= 9 ; ++ i)
        if(a[i])
        {
            ans = i , -- a[i] , -- m;
            break;
        }
    
    for(int i = 0 ; i <= 9 ; ++ i)
    {
        int t = std::min(a[i] , m);
        ans = (ans * quickpow(10 , t) % mod + calc(i , t)) % mod;
        m -= t;
        if(m == 0) break;
    }
    std::cout << ans << '\n';
}

int main()
{
    int T;
    std::cin >> T;
    while(T --)
        solve();
}