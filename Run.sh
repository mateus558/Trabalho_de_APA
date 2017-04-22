#!/bin/bash
echo "Starting Experiments"

make

N=10
while [ $N -le 1000000 ]
do
  echo "Size: $N"
  PATH1="List/ListAmOrd${N}.txt"
  PATH2="List/ListAOrd${N}.txt"
  PATH3="List/ListDOrd${N}.txt"
  PATH4="List/ListRO${N}.txt"

  for i in `seq 1 5`
  do
	 $(./main $PATH1 $i)
 done

  for i in `seq 1 5`
  do
	   $(./main $PATH2 $i)
  done

  for i in `seq 1 5`
  do
    $(./main $PATH3 $i)
  done

  for i in `seq 1 5`
  do
    $(./main $PATH4 $i)
  done
  let "N=N*10"
done
