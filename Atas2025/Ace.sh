#!/bin/bash

# Diretório onde estão os PDFs (altere se necessário)
DIR="${1:-.}"

# Loop pelos arquivos que seguem o padrão
for file in "$DIR"/ACE\ Scanner_*.pdf; do
    # Verifica se o arquivo existe para evitar erros no loop
    [ -e "$file" ] || continue

    # Extrai a data do nome original
    new_name=$(echo "$file" | sed 's/ACE Scanner_/frequencia_/')

    # Renomeia o arquivo
    mv "$file" "$new_name"

    # Mensagem de confirmação
    echo "Renomeado: '$file' → '$new_name'"
done

