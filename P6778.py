def solution():
    import sys
    input = sys.stdin.readline
    antenna = int(input())
    eye = int(input())
    if antenna<=3 and 4<=eye: print("TroyMartian")
    if antenna<=6 and 2<=eye: print("VladSaturnian")
    if antenna<=2 and 3<=eye: print("GraemeMercurian")
solution()