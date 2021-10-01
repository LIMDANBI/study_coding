def roundUp(num):
    if num - int(num) < 0.5:
        return int(num)
    else:
        return int(num)+1

def solution():
    N, emotion = map(int, input().split())
    prob = list(map(float, input().split()))
    prob_g = [1-emotion]
    prob_b = [emotion]
    for i in range(N):
        prob_g.append(prob_g[i]*prob[0]+prob_b[i]*prob[2])
        prob_b.append(prob_g[i]*prob[1]+prob_b[i]*prob[3])
    print(roundUp(prob_g[-1]*1000))
    print(roundUp(prob_b[-1]*1000))
solution()