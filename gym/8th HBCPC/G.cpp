#include <iostream>
#include <algorithm>

const int Max_n = 1e6 + 5;

int n , m , k;

std::string s;

int solve(std::string s)
{
    int p[Max_n];
    int a = 0 , b = 0 , c = 0 , t = s.size() / 2 , tp = 0 , ans = 0;

    s = s + s;

    for(int i = 0 ; i + 1 < s.size() ; i += 2)
    {
        if(s[i] == s[i + 1])
        {
            if(s[i] == '0')
                p[ ++ tp] = 0;
            else if(s[i] == '1')
                p[ ++ tp] = 1;
        }
        else p[ ++ tp] = 2;
    }

    int r = 0;
    for(int l = 1 ; l <= tp ; ++ l)
    {
        r = std::max(r , l - 1);

        while(r < tp && r <= l + t - 2)
        {
            if(p[r + 1] == 0)
            {
                if(a == n) break;
                ++ a;
            }
            if(p[r + 1] == 1)
            {
                if(b == k) break;
                ++ b;
            }
            if(p[r + 1] == 2)
            {
                if(c == m) break;
                ++ c;
            }

            ++ r;
        }

        ans = std::max(ans , r - l + 1);
        if(l <= r)
        {
            if(p[l] == 0) -- a;
            if(p[l] == 1) -- b;
            if(p[l] == 2) -- c;
        }
        else a = b = c = 0;
    }

    return ans * 2;

}

int main()
{
    std::cin >> n >> m >> k;
    std::cin >> s;

    std::string a = "";

    for(int i = 1 ; i < s.size() ; ++ i)
        a += s[i];
    a += s[0];

    std::cout << std::max(solve(s) , solve(a)) << '\n';
}