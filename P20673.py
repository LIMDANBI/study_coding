def solution():
    import sys
    input = sys.stdin.readline
    p = int(input())
    q = int(input())
    if(p<=50 and q<=10): print("White")
    elif(30<q): print("Red")
    else: print("Yellow")
solution()