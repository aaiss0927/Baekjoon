-- 코드를 입력하세요
SELECT FIRST_HALF.FLAVOR
FROM FIRST_HALF, ICECREAM_INFO
WHERE (FIRST_HALF.FLAVOR = ICECREAM_INFO.FLAVOR) && (FIRST_HALF.TOTAL_ORDER > 3000) && (ICECREAM_INFO.INGREDIENT_TYPE = 'fruit_based')
ORDER BY FIRST_HALF.TOTAL_ORDER DESC