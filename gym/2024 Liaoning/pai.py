import os


T = 1

while T :
    os.system("python gen.py >in")
    os.system("./E <in >wrong")
    os.system("./Estd <in >right")

    if os.system("diff wrong right") :
        break
    else :
        print("ok" , T)
    
    T = T + 1