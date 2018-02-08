ALTER SESSION SET EXPLAIN PLAN = ON;
ALTER SYSTEM SET TRCLOG_EXPLAIN_GRAPH = 1;

SET TIMING ON;
SET TIMESCALE MILSEC;

SELECT 
       C_CUSTKEY,
       C_NAME,
       SUM(L_EXTENDEDPRICE * (1 - L_DISCOUNT)) AS REVENUE,
       C_ACCTBAL,
       N_NAME,
       C_ADDRESS,
       C_PHONE,
       C_COMMENT
FROM CUSTOMER,
     ORDERS,
     LINEITEM,
     NATION
WHERE C_CUSTKEY = O_CUSTKEY
  AND L_ORDERKEY = O_ORDERKEY
  AND O_ORDERDATE >= DATE'01-OCT-1993'
  AND O_ORDERDATE < ADD_MONTHS(DATE'01-OCT-1993', 3)
  AND L_RETURNFLAG = 'R'
  AND C_NATIONKEY = N_NATIONKEY
GROUP BY C_CUSTKEY,
         C_NAME,
         C_ACCTBAL,
         C_PHONE,
         N_NAME,
         C_ADDRESS,
         C_COMMENT
ORDER BY REVENUE DESC
LIMIT 20;

ALTER SYSTEM SET TRCLOG_EXPLAIN_GRAPH = 0;
