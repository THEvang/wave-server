#!/bin/bash

T1=10;
HS=8

./waves_lc $HS $T1 > Spectrum.csv

LC_ALL=C awk -f realize.awk Spectrum.csv > heights.txt
