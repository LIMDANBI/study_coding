import math

def calculate_min(start, end):
    s_hour, s_min = int(start[:2]), int(start[3:])
    e_hour, e_min = int(end[:2]), int(end[3:])
    return (e_hour*60+e_min) - (s_hour*60+s_min)
    
def solution(fees, records):
    answer = []
    
    # 1. car number to idx
    car_num_to_idx = {}
    cnt = 0
    for r in records:
        num = r.split(' ')[1]
        if not num in car_num_to_idx:
            car_num_to_idx[num] = cnt
            cnt+=1
    tstamp = [0 for _ in range(cnt)] # 입차 기록
    total_miniute = [0 for _ in range(cnt)] # 차 별 총 주차 시간
    
    
    # 2. 차 별 총 주차 시간 계산 
    for r in records:
        hhmm, num, inout  = r.split() # 시각 차량번호 내역
        idx = car_num_to_idx[num]
        if inout == 'IN':
            tstamp[idx] = hhmm # 입차
        else:
            total_miniute[idx]+=calculate_min(tstamp[idx], hhmm)
            tstamp[idx] = 0 # 출차
    
    for i in range(cnt):
        if tstamp[i]:
            total_miniute[i]+=calculate_min(tstamp[i], "23:59")
    
    # 3. 주차 요금 계산
    fee = []
    for i in range(cnt):
        if total_miniute[i]<=fees[0]:
            fee.append(fees[1])
        else:
            fee.append(fees[1]+math.ceil((total_miniute[i]-fees[0])/fees[2])*fees[3])
    
    # 4. 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아서 return
    cars = list(car_num_to_idx.keys()) # dict to list
    car_and_fee = []
    for i in range(len(cars)):
        car_and_fee.append([cars[i], fee[i]])
    car_and_fee = sorted(car_and_fee)
    for i in range(len(car_and_fee)):
        answer.append(car_and_fee[i][1])
    return answer