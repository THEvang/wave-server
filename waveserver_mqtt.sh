#!/bin/bash

mkdir -p server

./waves_lc
mv Spectrum.csv server/
mv Meta.txt server/

mosquitto_pub -t Waveserver/Spectrum -r -f server/Spectrum.csv
mosquitto_pub -t Waveserver/Meta -r -f server/Meta.txt
