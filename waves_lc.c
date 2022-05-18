#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N_WAVES 80

int
main(int argc, char* argv[]) {

	double phases[N_WAVES];
	double frequencies[N_WAVES];
	double s[N_WAVES];
	double amplitudes[N_WAVES];
	
	double omega_min = 0.1;
	double omega_max = 3.0;
	double delta_omega = (omega_max - omega_min) / N_WAVES;
	
	double wp = 0.4;
	double T1 = 0.834 * 2.0 * 3.14 / wp;
	double Hs = 1.0;
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

	const char* fmt = "%lf\n";
	
	FILE* phases_file = fopen("Epsilons.txt", "w");
	FILE* frequencies_file = fopen("Frequencies.txt", "w");
	FILE* spectrum_file = fopen("Spectrum.txt", "w");
	FILE* amplitudes_file = fopen("Amplitudes.txt", "w");

	for (int i = 0; i < N_WAVES; i++) {
		fprintf(phases_file, fmt, phases[i]);
		fprintf(frequencies_file, fmt, frequencies[i]);
		fprintf(spectrum_file, fmt, s[i]);
		fprintf(amplitudes_file, fmt, amplitudes[i]);
	}

	const char* last_fmt = "%lf\n";
	fprintf(phases_file, last_fmt, phases[N_WAVES]);
	fprintf(frequencies_file, last_fmt, frequencies[N_WAVES]);
	fprintf(spectrum_file, last_fmt, s[N_WAVES]);
	fprintf(amplitudes_file, last_fmt, amplitudes[N_WAVES]);

	fclose(phases_file);
	fclose(frequencies_file);
	fclose(spectrum_file);
	fclose(amplitudes_file);

	return 0;
}
