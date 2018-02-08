/***********************************************************************
 * Copyright 1999-2015, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

CREATE OR REPLACE PACKAGE BODY DBMS_CONCURRENT_EXEC AS

TYPE TEXT_LIST IS TABLE OF VARCHAR(8192);
DEGREE         INTEGER := 0;
STATUS         INTEGER := 0;
EXEC_TEXT_LIST TEXT_LIST;

FUNCTION INITIALIZE ( IN_DEGREE INTEGER DEFAULT NULL ) RETURN INTEGER AS
REAL_DEGREE INTEGER;
BEGIN
    REAL_DEGREE := NVL(IN_DEGREE, 0);

    IF( REAL_DEGREE < 0 ) THEN
        RETURN -1;
    END IF;

    IF( DBMS_CONCURRENT_EXEC.STATUS = 0 ) THEN
        REAL_DEGREE := CONCURRENT_INITIALIZE(REAL_DEGREE);

        DBMS_CONCURRENT_EXEC.STATUS := 1;
        DBMS_CONCURRENT_EXEC.DEGREE := REAL_DEGREE;
    ELSE
        REAL_DEGREE := -1;
    END IF;

    RETURN REAL_DEGREE;
END;

FUNCTION REQUEST ( TEXT VARCHAR(8192) ) RETURN INTEGER AS
REQ_ID  INTEGER;
RET_TMP INTEGER;
RET_VAL INTEGER;
BEGIN
    REQ_ID := EXEC_TEXT_LIST.COUNT();

    IF( DBMS_CONCURRENT_EXEC.STATUS = 3 ) THEN
        RETURN -1;
    END IF;

    IF( TEXT IS NULL ) THEN
        RETURN -1;
    END IF;

    IF( DBMS_CONCURRENT_EXEC.STATUS = 0 ) THEN
        RET_TMP := CONCURRENT_INITIALIZE(DBMS_CONCURRENT_EXEC.DEGREE);
        DBMS_CONCURRENT_EXEC.DEGREE := RET_TMP;
        DBMS_CONCURRENT_EXEC.STATUS := 1;
    END IF;

    IF( DBMS_CONCURRENT_EXEC.DEGREE = 0 ) THEN
        RETURN -1;
    END IF;

    BEGIN
        EXEC_TEXT_LIST(REQ_ID) := TEXT;
        DBMS_CONCURRENT_EXEC.STATUS := 2;
        RET_VAL := CONCURRENT_REQUEST( REQ_ID, 'EXEC ' || TEXT );
    EXCEPTION WHEN OTHERS THEN
        IF( EXEC_TEXT_LIST.EXISTS(REQ_ID) = TRUE ) THEN
            RET_TMP := EXEC_TEXT_LIST.DELETE(REQ_ID);
        END IF;
        RET_VAL := -1;
    END;

    RETURN RET_VAL;
END;

FUNCTION WAIT_ALL RETURN INTEGER AS
RC INTEGER;
BEGIN
    RC := CONCURRENT_WAIT();
    DBMS_CONCURRENT_EXEC.STATUS := 3;
    RETURN RC;
END;

FUNCTION WAIT_REQ ( REQ_ID INTEGER ) RETURN INTEGER AS
BEGIN
    IF( REQ_ID > DBMS_CONCURRENT_EXEC.EXEC_TEXT_LIST.COUNT() - 1 ) THEN
        RETURN -1;
    END IF;
    IF( REQ_ID IS NOT NULL ) THEN
        RETURN CONCURRENT_WAIT( REQ_ID );
    END IF;

    RETURN -1;
END;

FUNCTION FINALIZE RETURN INTEGER AS
RC INTEGER;
BEGIN
    RC := EXEC_TEXT_LIST.DELETE();

    IF( DBMS_CONCURRENT_EXEC.STATUS = 2 ) THEN
        RC := CONCURRENT_WAIT();
        DBMS_CONCURRENT_EXEC.STATUS := 3;
    END IF;

    RC := CONCURRENT_FINALIZE();

    DBMS_CONCURRENT_EXEC.DEGREE := 0;
    DBMS_CONCURRENT_EXEC.STATUS := 0;

    RETURN RC;
END;

FUNCTION GET_DEGREE_OF_CONCURRENCY
RETURN INTEGER
AS
BEGIN
    RETURN DBMS_CONCURRENT_EXEC.DEGREE;
END;

FUNCTION GET_ERROR_COUNT RETURN INTEGER AS
BEGIN
    RETURN CONCURRENT_GET_ERRCOUNT();
END;

FUNCTION GET_ERROR ( REQ_ID   IN  INTEGER,
                     TEXT     OUT VARCHAR(8192),
                     ERR_CODE OUT INTEGER,
                     ERR_MSG  OUT VARCHAR(8192) ) RETURN INTEGER AS
RET     INTEGER;
ERR_SEQ INTEGER;
BEGIN
    IF ( DBMS_CONCURRENT_EXEC.STATUS = 0 ) THEN
        ERR_CODE := 0;
        RET      := -1;
        ERR_MSG  := NULL;
        TEXT     := NULL;
        RETURN RET;
    END IF;

    ERR_SEQ := CONCURRENT_GET_ERRSEQ( REQ_ID );
    IF ( (ERR_SEQ < (DBMS_CONCURRENT_EXEC.DEGREE * 2)) AND (ERR_SEQ >= 0 ) ) THEN
        ERR_CODE := CONCURRENT_GET_ERRCODE( ERR_SEQ );
        IF( ERR_CODE = 0 ) THEN
            RET := -1;
            ERR_MSG := NULL;
            TEXT    := NULL;
        ELSE
            RET     := REQ_ID;
            ERR_MSG := CONCURRENT_GET_ERRMSG( ERR_SEQ );
            TEXT    := CONCURRENT_GET_TEXT( ERR_SEQ );
        END IF;
    ELSE
        ERR_CODE := 0;
        RET      := -1;
        ERR_MSG  := NULL;
        TEXT     := NULL;
    END IF;
    RETURN RET;
END;

FUNCTION GET_LAST_REQ_ID RETURN INTEGER AS
BEGIN
   RETURN EXEC_TEXT_LIST.COUNT() - 1;
END;

FUNCTION GET_REQ_TEXT (REQ_ID INTEGER) RETURN VARCHAR(8192) AS
BEGIN
   IF( EXEC_TEXT_LIST.EXISTS(REQ_ID) = TRUE ) THEN
       RETURN EXEC_TEXT_LIST(REQ_ID);
   ELSE
       RETURN NULL;
   END IF;
END;

PROCEDURE PRINT_ERROR ( REQ_ID INTEGER ) AS
ERR_CODE INTEGER;
TEXT     VARCHAR(8192);
ERR_MSG  VARCHAR(8192);
RC       VARCHAR(16384);
ERR_SEQ  INTEGER;
BEGIN
    IF ( DBMS_CONCURRENT_EXEC.STATUS = 0 ) THEN
        RETURN;
    END IF;

    ERR_SEQ := CONCURRENT_GET_ERRSEQ( REQ_ID );
    IF ( (ERR_SEQ < (DBMS_CONCURRENT_EXEC.DEGREE * 2)) AND (ERR_SEQ >= 0 ) ) THEN
        ERR_CODE := CONCURRENT_GET_ERRCODE( ERR_SEQ );
        IF( ERR_CODE = 0 ) THEN
            ERR_MSG := NULL;
            TEXT    := NULL;
        ELSE
            ERR_MSG := CONCURRENT_GET_ERRMSG( ERR_SEQ );
            TEXT    := CONCURRENT_GET_TEXT( ERR_SEQ );
        END IF;
        RC := PRINT_OUT( 'REQ_ID   : ' || REQ_ID   || CHR(10) );
        RC := PRINT_OUT( 'TEXT     : ' || TEXT     || CHR(10) );
        RC := PRINT_OUT( 'ERR_CODE : ' || ERR_CODE || CHR(10) );
        RC := PRINT_OUT( 'ERR_MSG  : ' || ERR_MSG  || CHR(10) );
    ELSE
        NULL;
    END IF;
END;

END;
/
