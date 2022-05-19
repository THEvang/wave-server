#!/bin/bash

mkdir -p server

./waves_lc > Spectrum.csv
mv Spectrum.csv server/

mosquitto_pub -t Waveserver/Spectrum -r -f server/Spectrum.csv
