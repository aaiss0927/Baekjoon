SELECT MCDP_CD AS "진료과 코드", COUNT(*) AS "5월예약건수"
FROM APPOINTMENT
WHERE EXTRACT(YEAR FROM APNT_YMD) = 2022
  AND EXTRACT(MONTH FROM APNT_YMD) = 5
GROUP BY MCDP_CD
ORDER BY COUNT(*) ASC, MCDP_CD ASC;