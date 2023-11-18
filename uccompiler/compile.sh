echo 'yacc'
yacc -d -v uccompiler.y
echo 'lex'
lex uccompiler.l
echo 'cc'
cc -o uccompiler y.tab.c lex.yy.c tree.c
zip uccompiler.zip uccompiler.y uccompiler.l tree.h tree.c
cd ..
bash test.sh uccompiler/uccompiler
