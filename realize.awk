BEGIN { FS=","}
{	       
	w=$1; 
	a=$3;
	e=$4;
	k = w * w / 9.81;
        for (i = 1; i < 100; i++) {
	   A[i] += $3 * cos(k * i + e); 
	}
}
END {
	for (i = 1; i < 100; i++) {
		print A[i]
	}
}
