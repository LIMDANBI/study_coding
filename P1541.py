def solution():
    expression = input()
    nums, operator, nums2 = [], [], []
    begin = 0
    for i in range(len(expression)):
        if expression[i]=='+' or expression[i]=='-':
            operator.append(expression[i])
            nums.append(int(expression[begin:i]))
            begin = i+1
    nums.append(int(expression[begin:len(expression)]))
    tmp = nums[0]
    for i in range(len(operator)):
        if operator[i] == '+':
            tmp+=nums[i+1]
        else:
            nums2.append(tmp)
            tmp = nums[i+1]
    nums2.append(tmp)
    ans = nums2[0]*2
    for i in nums2: ans-=i
    print(ans)
solution()