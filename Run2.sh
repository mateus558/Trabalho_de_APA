#!/bin/bash

function Exp () {
	N=10
	while [ $N -le 1000000 ]
	do
		for i in `seq 0 5`
		do
			res=$res$'\n'$(./main Lists/List$1$N.txt $i)
		done
		let "N=N*10"
	done
}

Exp AOrd
Exp AmOrd
Exp DOrd
Exp RO

