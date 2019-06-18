#ifndef NUMANALYSIS_H
#define NUMANALYSIS_H

#include <cmath>
#include <cstdio>
#define DIFF1_STEP 1e-4
#define DIFF2_STEP 1e-4
#define DIFF3_STEP 1e-3
#define DIFF4_STEP 1e-3
#define INTT_SLICE_COUNT 100
#define ODE_STEP 1e-5
#define EPS 1e-7
#define bg(a, b) ((a) - (b)) >= EPS
#define ls(a, b) ((a) - (b)) <= EPS
#define eq(a, b) (bg((a), (b))) && (ls((a), (b)))

#endif
