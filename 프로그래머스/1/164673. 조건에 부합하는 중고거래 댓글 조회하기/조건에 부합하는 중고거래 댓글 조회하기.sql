-- 코드를 입력하세요
SELECT USED_GOODS_BOARD.TITLE, USED_GOODS_BOARD.BOARD_ID, USED_GOODS_REPLY.REPLY_ID, 
        USED_GOODS_REPLY.WRITER_ID, USED_GOODS_REPLY.CONTENTS, LEFT(USED_GOODS_REPLY.CREATED_DATE, 10)
FROM USED_GOODS_BOARD, USED_GOODS_REPLY
WHERE USED_GOODS_BOARD.BOARD_ID = USED_GOODS_REPLY.BOARD_ID && 
        YEAR(USED_GOODS_BOARD.CREATED_DATE) = '2022' && MONTH(USED_GOODS_BOARD.CREATED_DATE) = '10'
ORDER BY USED_GOODS_REPLY.CREATED_DATE, USED_GOODS_BOARD.TITLE
