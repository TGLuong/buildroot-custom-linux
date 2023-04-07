#!/bin/sh

while [ true ]
do
    for var in 1 2 3 4 5
    do
        /root/proc1 &
        sleep 1
    done
    killall -9 proc1
done