def solution():
    import sys
    AplusB = sys.stdin.readline().rstrip()
    if(len(AplusB)==2): print(int(AplusB[0])+int(AplusB[1]))
    elif(len(AplusB)==3):
        if AplusB[1]=='0': print(10+int(AplusB[2]))
        else: print(10+int(AplusB[0]))
    else: print(20)
solution()