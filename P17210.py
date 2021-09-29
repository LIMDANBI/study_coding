n = int(input())
way = int(input())
if n<6:
    for i in range(n-1):
        way = not way
        print(int(way))
else: print("Love is open door")