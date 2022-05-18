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
	
	const char* fmt = "%lf,%lf,%lf,%lf\n";
	
	FILE* spectrum_file = fopen("Spectrum.csv", "w");
	fprintf(spectrum_file, "Frequencies[rad/s],Spectrum[m²/s],Amplitude[m],Phase[rad]\n");
	for (int i = 0; i < N_WAVES; i++) {
		fprintf(spectrum_file, fmt, frequencies[i], s[i], amplitudes[i], phases[i]);
	}

	fclose(spectrum_file);
	
	const char* meta_fmt = "%s\t%lf\n";
	FILE* meta_file = fopen("Meta.txt", "w");
	fprintf(meta_file, meta_fmt, "OMEGA_MIN", omega_min);
	fprintf(meta_file, meta_fmt, "OMEGA_MAX", omega_max);
	fprintf(meta_file, meta_fmt, "OMEGA_DELTA", delta_omega);
	fprintf(meta_file, meta_fmt, "T1", T1);
	fprintf(meta_file, meta_fmt, "HS", Hs);
	fprintf(meta_file, meta_fmt, "N_WAVES", N_WAVES);
	return 0;

}
