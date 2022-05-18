#!/bin/bash

mkdir -p server
./waves_lc
gnuplot plot.gnuplot

mv Spectrum.csv server/
mv Spectrum.png server/

./darkhttpd server
