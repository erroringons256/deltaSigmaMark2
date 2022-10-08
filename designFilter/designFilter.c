#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <random.h>
#include <time.h>

#define NUM_ROOTS 2
#define FREQ_BINS 32
#define ITERS 10
#define M_TAU 2 * M_PI
#define OSR 8
#define OBG 1.5

void getFrequencyResponse(double complex*, double*, double*, int);
inline double sAbs(double complex);
inline double randFloat();
void getFlatTargetResponse(double*, double*);

int main()
{
    srand((unsigned int)time(NULL));
    double complex root[NUM_ROOTS] = {CMPLX(0.8, 0.6), CMPLX(0.8, -0.6)};
    double complex newRoot[NUM_ROOTS];
    double residual = 0.0;
    double frequency[FREQ_BINS];
    double frequencyResponse[FREQ_BINS];
    double target[FREQ_BINS];

    memcpy(newRoot, root, NUM_ROOTS * sizeof(double));

    for(int i = 0; i < FREQ_BINS; i++)
    {
        frequency[i] = 0.5 / FREQ_BINS * i + 0.25 / FREQ_BINS;
    }

    getFrequencyResponse(root, f, frequencyResponse, FREQ_BINS);
    for(int i = 0; i < FREQ_BINS; i++)
    {
        residual += frequencyResponse[i] -
    }
    
    printf("\n");
    double threshold = 100 * FREQ_BINS;
    double threshold_iter = 0.99;
    for(int i = 0; i < ITERS; i++)
    {
        double newResidual = 0.0;
        double complex increment = 0.1 * CMPLX(randFloat(), randFloat());
        unsigned int selection = rand() % NUM_ROOTS;
        newRoot[selection] += increment;
        
    }
    return 0;
}

void getFrequencyResponse(double complex* root, double* f, double* out, int freqBins)
{
    double complex input[freqBins];
    for(int i = 0; i < freqBins; i++)
    {
        double complex tally = CMPLX(1.0, 0.0);
        double complex z = cexp(CMPLX(0, M_TAU * f[i]));
        for(int j = 0; j < NUM_ROOTS; j++)
        {
            tally *= sAbs(z - root[j]);
        }
        out[i] = sqrt(tally);
    }
}

inline double sAbs(double complex x)
{
    return creal(x) * creal(x) + cimag(x) * cimag(x);
}

inline double randFloat()
{
    return (2.0 / RAND_MAX) * (double)rand() - 1;
}

double getFlatTargetResponse(double* f, double* out)
{
    return (f < 0.5 / OSR) * pow(OBG, -OSR) + (f >= 0.5 / OSR) * OBG;
}