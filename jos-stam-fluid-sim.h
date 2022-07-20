// jos-stam-fluid-sim.h : Logic for fluid simulation

#ifndef JOS_STAM_FLUID_SIM_H
#define JOS_STAM_FLUID_SIM_H

#include <stdint.h>

class fluidSimulation {
public:
	uint32_t N;
	uint32_t frames;
	uint32_t size;
	float *u, *v, *u_prev, *v_prev;
	float *dens, *dens_prev;

	template<typename T1, typename T2>
	constexpr auto IX(T1 i, T2 j) { return ((i)+(N + 2) * (j)); }
	constexpr void SWAP(float *x0, float *x) { float *tmp = x0; x0 = x; x = tmp; }

	void add_source(uint32_t N, float *x, float *s, float dt);
	void set_bnd(uint32_t N, int b, float *x, float *x0);
	void lin_solve(uint32_t N, int b, float *x, float *x0, float a, float c);
	void diffuse(uint32_t N, int b, float *x, float *x0, float diff, float dt);
};

#endif
