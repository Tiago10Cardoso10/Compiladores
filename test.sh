#!/usr/bin/env bash
#
#  Utilização
#    bash test.sh ./path/to/jucompiler
#
#  Funcionalidade
#  Compara todos os casos de teste na pasta meta1
#  Cria o ficheiro *casoteste*.out_temp com resultado de correr cada caso de teste

if [[ -z "$1" ]]; then
    echo "Missing argument executable"
    echo "Usage: $0 executable"
    echo "Example: $0 ./path/to/uccompiler"
    exit 1
fi

exe="$1"

accepted=0
total=0

for inp in testes/*.uc; do
        total=$(( $total + 1 ))
        echo "$inp"
        out=${inp%.uc}.out
        tmp=${inp%.uc}.out_temp
        flag="-t"
        #if [[ "$inp" == *_e2.c ]]; then
        #    flag="-e2"
        #fi
        if $exe $flag < "$inp" > "$tmp"; then
            lines=$(diff $out $tmp | wc -l)
            if [[ $lines -gt 0 ]]; then
                echo -e $(printf " \e[31m Wrong Answer, run 'diff $out $tmp' to see the differences\e[0m")
            else
                accepted=$(( $accepted + 1 ))
                echo -e $(printf " \e[32m Right Answer, run 'diff $out $tmp' to see the differences\e[0m")
            fi
        else
            echo " Runtime Error, failed to execute '$exe'"
        fi
    done

echo "Accepted: $accepted / $total"
