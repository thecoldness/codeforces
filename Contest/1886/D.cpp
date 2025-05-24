#include <bits/stdc++.h>

int n , m;

std::string s;

const int mod = 998244353;

int quickpow(long long x , long long y)
{
    long long ret = 1;
    for(; y ; y >>= 1 , x = x * x % mod)
        if(y & 1) ret = ret * x % mod;
    
    return ret;
}

int main()
{
    std::cin >> n >> m;
    std::cin >> s; // 0 ~ n - 2

    long long ans = 1;

    for(int i = n - 2 ; i >= 1 ; -- i)
        if(s[i] == '?') ans = ans * i % mod;
    
    if(s[0] == '?') std::cout << "0\n";
    else std::cout << ans << '\n';

    while(m --)
    {
        int x;
        std::string tmp;
        char y;
        std::cin >> x >> tmp;
        y = tmp[0];
        -- x;
        if(x)
        {
            if(s[x] != '?')
                ans = ans * x % mod;
            
            if(y != '?')
                ans = ans * quickpow(x , mod - 2) % mod;
        }
        s[x] = y;
        if(s[0] == '?') std::cout << "0\n";
        else std::cout << ans << '\n';
    }
}