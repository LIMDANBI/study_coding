-- 동물 보호소에 들어온 동물 중 아픈 동물의 아이디와 이름을 조회하는 SQL 문 (결과는 아이디 순으로 조회)
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION='Sick' ORDER BY ANIMAL_ID