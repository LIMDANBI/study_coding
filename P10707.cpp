A = int(input()) 
B = int(input()) 
C = int(input())
D = int(input()) 
P = int(input()) 
if C < P :
    if A*P < (B+(P-C)*D):
        print(A*P)
    else:
        print(B+(P-C)*D)
else:
    if A*P < B:
        print(A*P)
    else:
        print(B)