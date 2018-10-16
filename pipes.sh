#!/bin/bash
if [ $# -eq 0 ]; then 
    echo "El script no tiene parámetros, por favor introduzca uno."
elif [ $# -gt 1 ]; then
    echo "El script está recibiendo más de un parámetro, por favor introduzca solo uno."
else 
    ls | grep $1 | sort -r
fi