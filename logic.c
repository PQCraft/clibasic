if (!qstrcmp(tmp[0], "REM")) return true;
if (!qstrcmp(tmp[0], "DO")) {
    if (dlstackp >= 255) {cerr = 12; goto lexit;}
    dlstackp++;
    if (dlstackp > 0) {
        if (dldcmd[dlstackp - 1]) {dldcmd[dlstackp] = true; return true;}
    }
    if (itstackp > -1) {
        if (itdcmd[itstackp]) {dldcmd[dlstackp] = true; return true;}
    }
    int p = j;
    while (cmd[p] != '\0') {if (cmd[p] != ' ') {cerr = 1; return true;} p++;}
    dldcmd[dlstackp] = false;
    dlstack[dlstackp] = cmdpos;
    dlpline[dlstackp] = progLine;
    return true;
}
if (!qstrcmp(tmp[0], "DOWHILE")) {
    if (dlstackp >= 255) {cerr = 12; goto lexit;}
    dlstackp++;
    if (itstackp > -1) {
        if (itdcmd[itstackp]) {dldcmd[dlstackp] = true; return true;}
    }
    if (dlstackp > 0) {
        if (dldcmd[dlstackp - 1]) {dldcmd[dlstackp] = true; return true;}
    }
    copyStrSnip(cmd, j + 1, strlen(cmd), tmp[1]);
    uint8_t testval = logictest(tmp[1]);
    if (testval != 1 && testval != 0) return true;
    if (testval == 1) dlpline[dlstackp] = progLine;
    if (testval == 1) dlstack[dlstackp] = cmdpos;
    dldcmd[dlstackp] = (bool)testval;
    dldcmd[dlstackp] = !dldcmd[dlstackp];
    return true;
}
if (!qstrcmp(tmp[0], "LOOP")) {
    if (dlstackp <= -1) {cerr = 6; return true;}
    if (dlstackp > -1) {
        if (dldcmd[dlstackp]) {dlstackp--; return true;}
    }
    if (itstackp > -1) {
        if (itdcmd[itstackp]) return true;
    }
    cp = dlstack[dlstackp];
    progLine = dlpline[dlstackp];
    lockpl = true;
    dldcmd[dlstackp] = false;
    dlstackp--;
    int p = j;
    while (cmd[p] != '\0') {if (cmd[p] != ' ') {cerr = 1; return true;} p++;}
    didloop = true;
    return true;
}
if (!qstrcmp(tmp[0], "LOOPWHILE")) {
    if (dlstackp <= -1) {cerr = 6; return true;}
    if (itstackp > -1) {
        if (itdcmd[itstackp]) return true;
    }
    if (dlstackp > -1) {
        if (dldcmd[dlstackp]) {dlstackp--; return true;}
    }
    copyStrSnip(cmd, j + 1, strlen(cmd), tmp[1]);
    uint8_t testval = logictest(tmp[1]);
    if (testval != 1 && testval != 0) return true;
    if (testval == 1) {cp = dlstack[dlstackp]; progLine = dlpline[dlstackp]; lockpl = true;}
    dldcmd[dlstackp] = false;
    dlstackp--;
    didloop = true;
    return true;
}
if (!qstrcmp(tmp[0], "IF")) {
    if (itstackp >= 255) {cerr = 13; return true;}
    itstackp++;
    if (itstackp > -2) {
        if (itdcmd[itstackp - 1]) {itdcmd[itstackp] = true; return true;}
    }
    if (dlstackp > -1) {
        if (dldcmd[dlstackp]) {itdcmd[itstackp] = true; return true;}
    }
    copyStrSnip(cmd, j + 1, strlen(cmd), tmp[1]);
    uint8_t testval = logictest(tmp[1]);
    if (testval != 1 && testval != 0) return true;
    itdcmd[itstackp] = (bool)!testval;
    return true;
}
if (!qstrcmp(tmp[0], "ELSE")) {
    if (itstackp <= -1) {cerr = 8; goto lexit;}
    if (itstackp > 0) {
        if (itdcmd[itstackp - 1]) return true;
    }
    if (dlstackp > -1) {
        if (dldcmd[dlstackp]) return true;
    }
    if (didelse) {cerr = 11; return true;}
    didelse = true;
    itdcmd[itstackp] = !itdcmd[itstackp];
    return true;
}
if (!qstrcmp(tmp[0], "ENDIF")) {
    if (itstackp <= -1) {cerr = 7; goto lexit;}
    itdcmd[itstackp] = false;
    didelse = false;
    itstackp--;
    return true;
}