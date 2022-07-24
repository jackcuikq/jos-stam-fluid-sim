// jos-stam-fluid-sim.cpp : Defines the entry point for the application.
//

#include "jos-stam-fluid-sim.h"
#include <iostream>
#include <fstream>
#include <cmath>
#define PI_OVER_180 0.01745329252

const int frames = 400;
const int N = 200;
const int size = (N + 2) * (N + 2);

static float u[size], v[size], u_prev[size], v_prev[size];
static float dens[size], dens_prev[size];

int main()
{
	float visc = 0.0000001f;
	float dt = 0.1f;
	float diff = 0.0000001f;
	float angle = (rand() % 360) * PI_OVER_180;
	float noise;
	int radius = N / 20;

	std::ofstream file;
	file.open("fluid_sim.dat");
	file << N << "," << frames << "," << "\n";

	srand(time(NULL));

	for (int i = 0; i < frames; ++i) {
		//noise = (rand() % 30 - 15) * PI_OVER_180;
		noise = PI_OVER_180;
		angle += noise;
		for (int x = 0; x < N + 2; x++) {
			for (int y = 0; y < N + 2; y++) {
				if (((N - 1) / 2 - x) * ((N - 1) / 2 - x) + ((N - 1) / 2 - y) * ((N - 1) / 2 - y) < radius * radius) {
					dens[IX(x, y)] = 15;
					u_prev[IX(x, y)] = cos(angle);
					v_prev[IX(x, y)] = sin(angle);
				}
			}
		}

		vel_step(N, u, v, u_prev, v_prev, visc, dt);
		dens_step(N, dens, dens_prev, u, v, diff, dt);

		for (int x = 1; x < N + 1; ++x) {
			for (int y = 1; y < N + 1; ++y) {
				file << dens[IX(x, y)] << ",";
			}
		}
		file << "," << "\n";
	}
	file.close();
	return 0;
}
