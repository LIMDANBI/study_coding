def solution():
    t1 = input()
    t2 = input()

    s1, s2 = int(t1[6:]), int(t2[6:])
    m1, m2 = int(t1[3:5]), int(t2[3:5])
    h1, h2 = int(t1[0:2]), int(t2[0:2])

    h, m, s = 0, 0, 0
    
    if s2-s1 < 0 :  # 초
        m2 -=1
        s = s2+60-s1
    else:
        s = s2-s1

    if m2-m1 < 0 : # 분
        h2 -=1
        m = m2+60-m1
    else:
        m = m2-m1

    h = h2-h1 # 시
    if h < 0:
        h+=24

    print("{:0>2}:{:0>2}:{:0>2}".format(h, m, s))

solution()