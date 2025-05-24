#include <bits/stdc++.h>

const int Max_n = 5e3 + 5;

using ld = long double;

using ll = long long;

ll x[Max_n] , y[Max_n] , n;

ld f[Max_n] , g[Max_n][Max_n];

int logm[Max_n];

int main()
{
    std::cin >> n;
    for(int i = 1 ; i <= n ; ++ i)
        std::cin >> x[i] >> y[i];

    for(int i = 1 ; i <= n ; ++ i)
        for(int j = i ; j <= n ; ++ j)
        {
            g[i][j] = std::sqrtl((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            g[i][j] = std::max(g[i][j] , g[i][j - 1]);
        }

    f[0] = 0;
    
    for(int i = 1 ; i <= n ; ++ i)
    {
        f[i] = f[i - 1];

        ld val = 0;

        for(int j = i - 2 ; j >= 0 ; -- j)
        {
            val = std::max(val , g[j + 1][i]);
            f[i] = std::max(f[i] , f[j] + val);
        }
    }

    printf("%.10Lf\n" , f[n]);
}
/*
7 
1 0
0 1
0 0
1 1
1 2
3 2
3 3
*/