T = int(input())

while T:
    T = T - 1
    n , k = map(int , input().split())
    a = list(map(int , input().split()))
    now = 0
    ans = 0
    for i in range(n):
        if(a[i] >= k) :
            now += a[i]
        elif(a[i] == 0) :
            if now > 0 :
                now -= 1
                ans += 1
    print(ans)