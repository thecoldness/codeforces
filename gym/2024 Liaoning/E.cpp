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

	for(int i = 1 ; i <= n ; ++ i)
	{
		while(tp && a[st[tp]] < a[i])
			lst[st[tp]] = i , -- tp;

		st[ ++ tp] = i;
	}

	while(tp) lst[st[tp]] = n + 1 , -- tp;

	for(int i = n ; i ; -- i)
	{
		while(tp && a[st[tp]] < a[i])
			pre[st[tp]] = i , -- tp;

		st[ ++ tp] = i;
	}

	while(tp) pre[st[tp]] = 0 , -- tp;

	for(int i = 1 ; i <= n ; ++ i)
		v[i].resize(0);

	for(int i = 1 ; i <= n ; ++ i)
	{
		p[i] = v[a[i]].size();
		v[a[i]].push_back(i);
	}

	ll ans = 0;

	for(int i = 1 ; i <= n ; ++ i)
	{
		if(p[i] + k > v[a[i]].size()) continue;

		if(v[a[i]][p[i] + k - 1] > lst[i]) continue;

		if(p[i] == 0)
			ans += 1ll * (i - pre[i]) * (lst[i] - v[a[i]][p[i] + k - 1]);
		else ans += 1ll * (i - std::max(v[a[i]][p[i] - 1] , pre[i])) * (lst[i] - v[a[i]][p[i] + k - 1]);

        // printf("i = %d ans = %lld\n" , i , ans);
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