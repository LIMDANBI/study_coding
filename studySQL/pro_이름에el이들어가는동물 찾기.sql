-- 이름에 "EL"이 들어가는 개의 아이디와 이름을 조회하는 SQL문 (결과는 이름 순으로 조회)
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
WHERE ANIMAL_TYPE = 'Dog' AND NAME LIKE '%el%'
ORDER BY NAME;