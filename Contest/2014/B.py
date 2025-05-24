T = int(input())

while T:
    T -= 1
    n , k = map(int , input().split())
    if n & 1:
        if (int((k + 1) / 2)) & 1 :
            print("NO")
        else:
            print("YES")
    else :
        if int(k / 2) & 1:
            print("NO")
        else:
            print("YES")