plain_text = input()
key = input()
key_len, tmp = len(key), 0

for i in plain_text:
    if(i == ' '):
        print(' ', end='')
    else:
        position = ord(key[tmp])-96
        if 97<=ord(i)-position<=122:
            print(chr(ord(i)-position), end='')
        else:
            print(chr(ord(i)-position+26), end='')
    tmp+=1
    if key_len<=tmp:
        tmp%=key_len