def solution():
    import sys
    input = sys.stdin.readline
    antenna = int(input())
    eye = int(input())
    if antenna>=3 and eye<=4: print("TroyMartian")
    if antenna<=6 and eye>=2: print("VladSaturnian")
    if antenna<=2 and eye<=3: print("GraemeMercurian")
solution()