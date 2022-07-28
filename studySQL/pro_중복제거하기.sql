-- 동물 보호소에 들어온 동물의 이름은 몇 개인지 조회하는 SQL 문 (이름이 NULL인 경우는 집계 x)
SELECT COUNT(DISTINCT NAME)
FROM ANIMAL_INS
WHERE NAME IS NOT NULL;