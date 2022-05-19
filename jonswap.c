#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N_WAVES 80

int
main(int argc, char* argv[]) {
	
	if (argc != 3) {
		printf("usage: jonswap Hs T0\n");
		return 1;
	}

	double Hs;
	double T0;

	sscanf(argv[1], "%lf", &Hs);
	sscanf(argv[2], "%lf", &T0);

	double phases[N_WAVES];
	double frequencies[N_WAVES];
	double s[N_WAVES];
	double amplitudes[N_WAVES];
	
	double omega_min = 0.1;
	double omega_max = 3.0;
	double delta_omega = (omega_max - omega_min) / N_WAVES;
	
	double T1 = 0.834 * T0;
	double Hs_squared = Hs * Hs;
	double gamma = 3.3;
	srand(time(NULL));
	for (int i = 0; i < N_WAVES; i++) {
		phases[i] = 2.0 * 3.14 * rand() / RAND_MAX;
		frequencies[i] = omega_min + i * delta_omega;
		double w = frequencies[i];
		double sigma = frequencies[i] <= 5.24 / T1 ? 0.07 : 0.09;
		double Y = exp( - pow(( 0.191 * w * T1 -1) / (sqrt(2) * sigma), 2));
		s[i] = 155 * (Hs_squared / pow(T1, 4)) * pow(w, -5) * exp( -944 / pow(T1, 4) * pow(w, -4)) * pow(gamma, Y);
		amplitudes[i] = sqrt(2.0 * s[i] * delta_omega);
	}
	
	const char* fmt = "%lf,%lf,%lf,%lf\n";
	
	printf("Frequencies[rad/s],Spectrum[m²/s],Amplitude[m],Phase[rad]\n");
	for (int i = 0; i < N_WAVES; i++) {
		printf(fmt, frequencies[i], s[i], amplitudes[i], phases[i]);
	}

	return 0;
}
