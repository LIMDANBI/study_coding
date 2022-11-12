T = int(input())

def euclid(a, b):
    while b!=0:
        tmp = a%b
        a = b
        b = tmp
    return a

for t in range(1, T + 1):
    s1, s2 = input().split()
    a, b = len(s1), len(s2)
    lcm = a*b//euclid(a, b)
    str1 = s1*(lcm//a)
    str2 = s2*(lcm//b)

    if str1 == str2: print("#{} yes".format(t))
    else: print("#{} no".format(t))