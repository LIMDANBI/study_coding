def solution():
    import sys
    input = sys.stdin.readline
    empty_container = list(map(int, input().split()))
    empty_container*=5
    print(sum(empty_container))
solution()