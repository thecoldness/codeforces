#include <iostream>

typedef long long ll;

const int Max_n = 1e3 + 5;

int n;

ll read()
{
    ll a , b , c , d;
    scanf("%lld.%lld.%lld.%lld" , &a , &b , &c , &d);
    ll t = (a << 24) + (b << 16) + (c << 8) + d;
    // printf("read = %lld\n" , t);
    return t;
}

ll s , a[Max_n] , p , val;

int main()
{
    s = read();
    scanf("/%lld" , &p);

    // printf("%lld %lld\n" , s , p);
    std::cin >> n;

    for(int i = 31 ; i >= 32 - p ; -- i)
        val = val | (1ll << i);

    for(int i = 1 ; i <= n ; ++ i)
    {
        a[i] = read();
        if((a[i] & val) == (s & val))
            puts("YES");
        else puts("NO");
    }

}