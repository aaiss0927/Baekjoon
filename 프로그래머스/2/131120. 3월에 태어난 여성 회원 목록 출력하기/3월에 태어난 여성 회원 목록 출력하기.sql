-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, LEFT(DATE_OF_BIRTH, 10)
FROM MEMBER_PROFILE
WHERE MONTH(DATE_OF_BIRTH) = '3' && GENDER = 'W' && TLNO != 'NULL'