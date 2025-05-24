#include <iostream>

typedef long double ld;

const int Max_n = 1e3 + 5;

ld a[Max_n][5];

int n , m , k , b , e;

int px[4] , py[4];

ld dis(ld a , ld b , ld c , ld d)
{
    return std::sqrtl((a - c) * (a - c) + (b - d) * (b - d));
}

ld calc_3(int x , int y , int a , int b , int c)
{
    return dis(x , y , px[a] , py[a]) + dis(px[a] , py[a] , px[b] , py[b]) + dis(px[b] , py[b] , px[c] , py[c]) + dis(px[c] , py[c] , px[3] , py[3]);
}

void calc(int id)
{
    int x , y;
    std::cin >> x >> y;
    a[id][0] = 0;
    a[id][1] = dis(x , y , px[0] , py[0]) + dis(px[0] , py[0] , px[3] , py[3]);
    a[id][1] = std::min(a[id][1] , dis(x , y , px[1] , py[1]) + dis(px[1] , py[1] , px[3] , py[3]));
    a[id][1] = std::min(a[id][1] , dis(x , y , px[2] , py[2]) + dis(px[2] , py[2] , px[3] , py[3]));

    a[id][2] = dis(x , y , px[0] , py[0]) + dis(px[0] , py[0] , px[1] , py[1]) + dis(px[1] , py[1] , px[3] , py[3]);
    a[id][2] = std::min(a[id][2] , dis(x , y , px[1] , py[1]) + dis(px[1] , py[1] , px[0] , py[0]) + dis(px[0] , py[0] , px[3] , py[3]));

    a[id][2] = std::min(a[id][2] , dis(x , y , px[0] , py[0]) + dis(px[0] , py[0] , px[2] , py[2]) + dis(px[2] , py[2] , px[3] , py[3]));
    a[id][2] = std::min(a[id][2] , dis(x , y , px[2] , py[2]) + dis(px[2] , py[2] , px[0] , py[0]) + dis(px[0] , py[0] , px[3] , py[3]));
    
    a[id][2] = std::min(a[id][2] , dis(x , y , px[1] , py[1]) + dis(px[1] , py[1] , px[2] , py[2]) + dis(px[2] , py[2] , px[3] , py[3]));
    a[id][2] = std::min(a[id][2] , dis(x , y , px[2] , py[2]) + dis(px[2] , py[2] , px[1] , py[1]) + dis(px[1] , py[1] , px[3] , py[3]));

    a[id][3] = calc_3(x , y , 0 , 1 , 2);
    a[id][3] = std::min(a[id][3] , calc_3(x , y , 0 , 2 , 1));
    a[id][3] = std::min(a[id][3] , calc_3(x , y , 1 , 0 , 2));
    a[id][3] = std::min(a[id][3] , calc_3(x , y , 1 , 2 , 0));
    a[id][3] = std::min(a[id][3] , calc_3(x , y , 2 , 0 , 1));
    a[id][3] = std::min(a[id][3] , calc_3(x , y , 2 , 1 , 0));

    // printf("%Lf %Lf %Lf\n" , a[id][1] , a[id][2] , a[id][3]);
}

ld f[Max_n][Max_n];

int main()
{
    std::cin >> n >> m >> k;
    std::cin >> b >> e;
    for(int i = 0 ; i <= 3 ; ++ i)
        std::cin >> px[i] >> py[i];
    
    for(int i = 1 ; i <= k ; ++ i)
        calc(i);

    int N = std::max((n - 1) / b , (m - 1) / b) + 1;

    f[0][0] = 0;

    for(int i = 1 ; i <= N ; ++ i)
        f[0][i] = 1e18;
    
    for(int i = 1 ; i <= k ; ++ i)
        for(int j = 0 ; j <= N ; ++ j)
        {
            // printf("val : %Lf %Lf %Lf\n" , a[i][1] , a[i][2] , a[i][3]);
            f[i][j] = f[i - 1][j];
            // printf("f[%d][%d] = %Lf\n" , i , j , f[i][j]);
            if(j >= 1)
                f[i][j] = std::min(f[i][j] , f[i - 1][j - 1] + a[i][1]);
            // printf("f[%d][%d] = %Lf\n" , i , j , f[i][j]);
            if(j >= 2)
                f[i][j] = std::min(f[i][j] , f[i - 1][j - 2] + a[i][2]);
            // printf("f[%d][%d] = %Lf\n" , i , j , f[i][j]);
            if(j >= 3)
                f[i][j] = std::min(f[i][j] , f[i - 1][j - 3] + a[i][3]);

            // printf("f[%d][%d] = %Lf\n" , i , j , f[i][j]);
            
        }

    printf("%.10Lf\n" , f[k][N]);
    
}