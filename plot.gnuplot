set datafile separator ','
set xlabel "Frequency[rad/s]"
set ylabel "Amplitude[m]/Spectrums[m^2s/rad]"
set key autotitle columnhead

set style line 100 lt 1 lc rgb "grey" lw 0.5
set grid ls 100

set style line 101 lw 3 lt rgb "#f62aa0"
set style line 102 lw 3 lt rgb "#26dfd0"

set terminal png
set output "Spectrum.png"
plot "Spectrum.csv" using 1:2 with lines ls 101, "Spectrum.csv" using 1:3 with lines ls 102
