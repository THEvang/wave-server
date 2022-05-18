#!/bin/bash

mkdir -p server

cd server
../waves_lc

cd ..
./darkhttpd server
