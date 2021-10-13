def solution():
    import sys
    input = sys.stdin.readline
    N, M = map(int, input().split())
    is_new, is_old = False, False

    if M<=2: is_new = True
    if M<=N and not is_old: is_old = True

    if is_new: print("NEWBIE!")
    elif is_old: print("OLDBIE!")
    else: print("TLE!")
solution()