--###########################################
--# TABLE 
--###########################################

DROP TABLE TEST_EMP_TBL;
CREATE TABLE TEST_EMP_TBL 
(
   EMP_ID   VARCHAR(20),
   EMP_NO   INTEGER,
   DEPT_NO  INTEGER
);

INSERT INTO TEST_EMP_TBL VALUES ( 'hykim'    , 15237, 9746 );
INSERT INTO TEST_EMP_TBL VALUES ( 'bbaejae'  , 15596, 9746 );
INSERT INTO TEST_EMP_TBL VALUES ( 'unclee'   ,    41, 9746 );
INSERT INTO TEST_EMP_TBL VALUES ( 'htkim'    ,  5999, 9746 );
INSERT INTO TEST_EMP_TBL VALUES ( 'leekmo'   ,    15, 3444 );
INSERT INTO TEST_EMP_TBL VALUES ( 'mskim'    ,    14, 3528 );
INSERT INTO TEST_EMP_TBL VALUES ( 'kobul'    ,  4355, 3527 );
INSERT INTO TEST_EMP_TBL VALUES ( 'bluetheme',    19, 3527 );
INSERT INTO TEST_EMP_TBL VALUES ( 'wlgml337' ,    18, 3528 );
INSERT INTO TEST_EMP_TBL VALUES ( 'omegaman' ,    40, 3528 );
INSERT INTO TEST_EMP_TBL VALUES ( 'dplee'    ,  5452, 3527 );

--###########################################
--# PROCEDURE
--###########################################

DROP TYPESET TEST_TYPE;
CREATE TYPESET TEST_TYPE
AS
    TYPE TEST_CUR IS REF CURSOR;
END;
/

CREATE OR REPLACE PROCEDURE PROC_MULTI_RESULTSET
(
   P1 OUT TEST_TYPE.TEST_CUR,
   P2 OUT TEST_TYPE.TEST_CUR,
   P3 OUT TEST_TYPE.TEST_CUR
)
AS
   sSQLStmt VARCHAR(200);
BEGIN

   sSQLStmt :=
    'SELECT EMP_ID, EMP_NO FROM TEST_EMP_TBL WHERE DEPT_NO = 9746 ORDER BY EMP_NO';
   OPEN P1 FOR sSQLStmt;

   sSQLStmt :=
    'SELECT EMP_ID, EMP_NO FROM TEST_EMP_TBL WHERE DEPT_NO = 3527 ORDER BY EMP_NO';
   OPEN P2 FOR sSQLStmt;

   sSQLStmt :=
    'SELECT EMP_ID, EMP_NO FROM TEST_EMP_TBL WHERE DEPT_NO = 3528 ORDER BY EMP_NO';
   OPEN P3 FOR sSQLStmt;

END;
/
   
