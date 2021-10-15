def solution():
    import sys
    input = sys.stdin.readline
    num = [int(input()) for _ in range(4)]
    if (num[0]==8 or num[0]==9) and num[1]==num[2] and (num[3]==8 or num[3]==9):
        print("ignore")
    else:
        print("answer")
solution()