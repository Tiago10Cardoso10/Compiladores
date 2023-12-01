echo 'yacc'
yacc -d -v uccompiler.y
echo 'lex'
lex uccompiler.l
echo 'cc'
cc -o uccompiler y.tab.c lex.yy.c uccompiler.c
zip uccompiler.zip uccompiler.y uccompiler.l uccompiler.h uccompiler.c
cd ..
bash test.sh uccompiler/uccompiler
