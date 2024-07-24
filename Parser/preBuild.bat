win_flex --wincompat C_grammar.l
IF  %ERRORLEVEL% NEQ 0 (
	ECHO "win_flex failed"
	EXIT 1
	)
win_bison -d -Wno-other C_grammar.y
IF  %ERRORLEVEL% NEQ 0 (
	ECHO "win_bison failed"
	EXIT 2
	)
EXIT 0