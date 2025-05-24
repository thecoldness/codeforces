#include <bits/stdc++.h>

const int Max_n = 1e6 + 5;

int T , n , k;

int a[Max_n] , st[Max_n] , tp , pre[Max_n] , lst[Max_n];

std::vector<int> v[Max_n];

using ll = long long;

int p[Max_n];

void solve()
{
	std::cin >> n >> k;
	for(int i = 1 ; i <= n ; ++ i)
		std::cin >> a[i];

    int ans = 0;

    for(int i = 1 ; i <= n ; ++ i)
        for(int j = i ; j <= n ; ++ j)
        {
            int mx = 0 , cnt = 0;
            for(int l = i ; l <= j ; ++ l)
            if(a[l] > mx) mx = a[l] , cnt = 1;
            else if(a[l] == mx) ++ cnt;

            if(cnt >= k) ++ ans;
        }

	std::cout << ans << '\n';
}

int main()
{
	std::cin >> T;
	while(T --)
		solve();
}
/*
2
 5 2
 1 3 3 2 2
 4 3
 1 4 2 1
*/