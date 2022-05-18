#!/bin/bash

mkdir -p server

cd server
../waves_lc
gnuplot ../plot.gnuplot

cd ..
./darkhttpd server
