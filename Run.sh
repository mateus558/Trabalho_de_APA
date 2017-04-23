#!/bin/bash
echo "Starting Experiments"

make

N=10
while [ $N -le 1000000 ]
do
  echo "Size: $N"
  PATH1="Lists/ListAmOrd${N}.txt"
  PATH2="Lists/ListAOrd${N}.txt"
  PATH3="Lists/ListDOrd${N}.txt"
  PATH4="Lists/ListRO${N}.txt"
  
  echo
  echo $PATH1
  echo
  for i in `seq 0 5`
  do
  	echo "Executing algorithm $i..."
	res=$(./main $PATH1 $i)
  done
  
  echo
  echo $PATH2
  echo
  for i in `seq 0 5`
  do
  	echo "Executing algorithm $i..."
	res=$(./main $PATH2 $i)
  done
  
  echo
  echo $PATH3
  echo
  for i in `seq 0 5`
  do
  	echo "Executing algorithm $i..."
    res=$(./main $PATH3 $i)
  done
  
  echo
  echo $PATH4
  echo
  for i in `seq 0 5`
  do
  	echo "Executing algorithm $i..."
    res=$(./main $PATH4 $i)
  done
  let "N=N*10"
done
