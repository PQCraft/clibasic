PRINT "Press Ctrl+C to exit..."
DO
    K$ = INKEY$()
    L = LEN(K$)
    IF ASC(K$) <> 0
        P = 0
        'LOCATE 1
        IF ASC(K$, LEN(K$) - 1) = 10: LOCATE , CURY() - 1: ENDIF
        PUT "\r\t\t  [", LEN(K$), "]"
        DOWHILE P < L
            PUT ", ", ASC(K$, P)
            P = P + 1
        LOOP
        PUT "\n"
    ENDIF
LOOP
