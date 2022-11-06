def solution(new_id):
    answer = ''
    
    # step 1. 대문자를 대응되는 소문자로 치환
    new_id = new_id.lower()
    
    # step 2. 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    for c in new_id:
        if c.islower() or c.isdigit() or c in ['-', '_', '.']:
            answer+=c
    
    # step 3. 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    while '..' in answer:
        answer = answer.replace('..', '.')
    
    # step 4. 마침표(.)가 처음이나 끝에 위치한다면 제거
    if len(answer) and answer[0] == '.':
        answer = answer[1:]
    if len(answer) and answer[-1] == '.':
        answer = answer[:-1]
    
    # step 5. 빈 문자열이라면, "a"를 대입
    if answer == '':
        answer = 'a'
    
    # step 6. 길이가 16자 이상이면, 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거 (끝 마침표 제거)
    if len(answer) > 15:
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]
    
    # step 7. 길이가 2자 이하라면, 마지막 문자를 길이가 3이 될 때까지 반복해서 끝에 붙임
    while len(answer) <= 2:
        answer += answer[-1]
    
    return answer