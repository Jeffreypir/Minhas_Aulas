#!/bin/bash

for f in *Scanner*.pdf; do 
    novo_nome=$(echo "$f" | sed -E 's/Scanner ([0-9]{2}-[0-9]{2}-[0-9]{4}) ([0-9]{2}\.[0-9]{2})/frequencia \1_\2/');
    mv "$f" "$novo_nome";
done

