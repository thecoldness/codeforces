#include <bits/stdc++.h>

const int Max_n  = 105;

int dx , dy , n;

using ll = __int128;
using ld = long double;

const ld eps = 1e-11L;

template<typename T> struct Point 
{
    T x , y;

    Point operator + (const Point &a) const
    {
        return {x + a.x , y + a.y};
    }

    Point operator - (const Point &a) const
    {
        return {x - a.x , y - a.y};
    }

    Point operator * (T k) const
    {
        return {x * k , y * k};
    }

    Point operator / (T k) const
    {
        return {x / k , y / k};
    }

    T operator * (const Point &a) const
    {
        return x * a.x + y * a.y;
    }

    T operator ^ (const Point &a) const
    {
        return x * a.y - y * a.x;
    }

    int to_left(const Point &a) const
    {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }
};

struct argcmp
{
    bool operator ()(const Point<ll> &a , const Point<ll> &b) const
    {
        const auto quad = [] (const Point<ll> &a)
        {
            if(a.y < -eps) return 1;
            if(a.y > eps) return 4;
            if(a.x < -eps) return 5;
            if(a.x > eps) return 3;
            return 2;
        };
        const int qa = quad(a) , qb = quad(b);
        if(qa != qb) return qa < qb;
        const auto t = a ^ b;
        return t > 0;
    }
};

template<typename T> struct Line
{
    Point<T> p , v;

    bool operator == (const Line &a) const
    {
        return v.to_left(a.v) == 0 && v.to_left(p - a.p) == 0;
    }

    int to_left(const Point<T> &a) const
    {
        return v.to_left(a - p);
    }

    bool operator < (const Line &a) const
    {
        if(std::max(v ^ a.v , -(v ^ a.v)) <= eps && v * a.v >= -eps) return to_left(a.p) == -1;
        return argcmp()(v,a.v);
    }

    Point<T> inter(const Line &a) const
    {
        return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v));
    }
};

Point<ll> a[Max_n];

int p[Max_n];

std::vector<Line<ll> > halfinter(std::vector<Line<ll> > l)
{
    const auto check = [](const Line<ll> &a , const Line<ll> &b , const Line<ll> &c)
    {
        const Point p = a.v * (b.v ^ c.v) , q = b.p * (b.v ^ c.v) + b.v * (c.v ^ (b.p - c.p)) - a.p * (b.v ^ c.v);

        return p.to_left(q) < 0;
    };

    std::sort(l.begin() , l.end());

    std::deque<Line<ll> >q;
    for(size_t i = 0 ; i < l.size() ; ++ i)
    {
        if(i > 0 && l[i - 1].v.to_left(l[i].v) == 0 && l[i - 1].v * l[i].v > eps) continue;
        while(q.size() > 1 && check(l[i] , q.back() , q[q.size() - 2])) q.pop_back();
        while(q.size() > 1 && check(l[i] , q[0] , q[1])) q.pop_front();

        if(!q.empty() && q.back().v.to_left(l[i].v) <= 0) return std::vector<Line<ll> > ();
        q.push_back(l[i]);
    }

    while(q.size() > 1 && check(q[0] , q.back() , q[q.size() - 2])) q.pop_back();
    while(q.size() > 1 && check(q.back() , q[0] , q[1])) q.pop_front();
    return std::vector<Line<ll> > (q.begin() , q.end());
}

int main()
{
    std::cin >> dx >> dy >> n;
    for(int i = 1 ; i <= n ; ++ i)
    {
        int x , y;
        std::cin >> x >> y;
        a[i] = {x , y};
    }

    for(int i = 1 ; i <= n ; ++ i)
    {
        int x;
        std::cin >> x;
        p[x] = i;
    }

    std::vector<Line<ll> > l;

    for(int i = 1 ; i <= n ; ++ i)
    {
        for(int j = i + 1 ; j <= n ; ++ j)
        {
            if(p[i] > p[j])
                l.push_back({a[i] , a[j] - a[i]});
            else l.push_back({a[i] , a[i] - a[j]});

        }
    }

    l.push_back({{0 , 0} , {1 , 0}}) , l.push_back({{dx , 0} , {0 , 1}});
    l.push_back({{dx , dy} , {-1 , 0}}) , l.push_back({{0 , dy} , {0 , -1}});

    

    std::vector<Line<ll> > tmp = halfinter(l);

    // std::cout << tmp.size() << '\n';

    if(tmp.size() == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }

    std::vector<Line<ld> > e;

    for(Line<ll> &x : tmp)
        e.push_back({{static_cast<ld>(x.p.x) , static_cast<ld>(x.p.y)} , {static_cast<ld>(x.v.x) , static_cast<ld>(x.v.y)}});

    std::vector<Point<ld> > pp;
    
    ld ans = 0;
    for(int i = 1 ; i < tmp.size() ; ++ i)
        pp.push_back(e[i].inter(e[i - 1]));
    
    pp.push_back(e.back().inter(e[0]));

    for(int i = 1 ; i < pp.size() ; ++ i)
        ans += pp[i - 1] ^ pp[i];
    ans += pp.back() ^ pp[0];

    printf("%.10Lf\n" , ans / 2);
}
/*
100000 100000 6
99999 1
1 1
1 2
50 700
10000 6789
8000 99900
2 1 3 4 5 6
*/