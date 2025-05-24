import random

T = 1

print(T)

while T:
    T -= 1
    n = random.randint(3 , 10)
    k = random.randint(1 , n)

    print(n , k)
    
    for i in range(n):
        print(random.randint(1 , n) , end = ' ')
    
    print()