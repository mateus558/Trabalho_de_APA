#!/bin/bash
echo "Starting Experiments"
make
N=10
echo "Size: $N"
./main List/ListAmOrd${N}.txt 1
./main List/ListAmOrd${N}.txt 2
./main List/ListAmOrd${N}.txt 3
./main List/ListAmOrd${N}.txt 4
./main List/ListAmOrd${N}.txt 5
./main List/ListAOrd${N}.txt 1
./main List/ListAOrd${N}.txt 2
./main List/ListAOrd${N}.txt 3
./main List/ListAOrd${N}.txt 4
./main List/ListAOrd${N}.txt 5
./main List/ListDOrd${N}.txt 1
./main List/ListDOrd${N}.txt 2
./main List/ListDOrd${N}.txt 3
./main List/ListDOrd${N}.txt 4
./main List/ListDOrd${N}.txt 5
./main List/ListRO${N}.txt 1
./main List/ListRO${N}.txt 2
./main List/ListRO${N}.txt 3
./main List/ListRO${N}.txt 4
./main List/ListRO${N}.txt 5
