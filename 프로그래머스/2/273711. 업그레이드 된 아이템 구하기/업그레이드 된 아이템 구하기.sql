SELECT T.ITEM_ID, I.ITEM_NAME, I.RARITY
FROM ITEM_TREE T
-- 1. 트리와 정보 테이블을 조인해서 '현재 아이템(자식)'의 정보를 가져옴
JOIN ITEM_INFO I ON T.ITEM_ID = I.ITEM_ID
-- 2. 다시 정보 테이블을 조인해서 '부모 아이템'의 정보를 확인함
JOIN ITEM_INFO P ON T.PARENT_ITEM_ID = P.ITEM_ID
-- 3. 부모 아이템의 희귀도가 'RARE'인 것만 필터링
WHERE P.RARITY = 'RARE'
ORDER BY T.ITEM_ID DESC;