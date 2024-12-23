#!/bin/bash

# write chmod +x compile_execute.sh
if [ -z "$1" ]; then
    echo "Por favor, forneça o nome de um ficheiro C."
    exit 1
fi

FILE=$1

if [ ! -f "$FILE" ]; then
    echo "O ficheiro '$FILE' não existe."
    exit 1
fi

OUTPUT="${FILE%.c}"

gcc -o "$OUTPUT" "$FILE"

if [ $? -eq 0 ]; then
    echo -e "Compilação bem-sucedida. A correr o programa...\n"
    ./"$OUTPUT"
else
    echo "Erro na compilação."
    exit 1
fi
