#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include "ringBuf.h"

#ifdef _WIN32
#define cpuid(info, x) __cpuidex(info, x, 0)

#else
#include <cpuid.h>
void cpuid(int info[4], int InfoType)
{
    __cpuid_count(InfoType, 0, info[0], info[1], info[2], info[3]);
}

#endif

#define BUFFER_SIZE 4096

void encode1Bit(char*, char*, unsigned int);

int main(int argc, char* argv[])
{
    t_ringBuf test;
    initRingBuf(&test, 0.5, 4);
    if(argc < 3)
    {
        printf("Too few arguments given!\n");
        return 1;
    }
    else if(argc > 3)
    {
        printf("Warning! Trailing arguments detected! Discarding...\n");
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];
    int cpuInfo[4];
    cpuid(cpuInfo, 1);
    char SSE4a;
    char osUsesXSAVE_XRSTORE = (cpuInfo[2] & (1 << 27)) != 0;
    printf("%d\n", osUsesXSAVE_XRSTORE);
    printf("Hello!\n");
    return 0;
}

void encode1Bit(char* input, char* output, unsigned int length)
{
    for(unsigned int i = 0; i < length; i++)
    {
        unsigned int j = 8 * i;
        output[i] = input[j] << 7 |
                    input[j + 1] << 6 |
                    input[j + 2] << 5 |
                    input[j + 3] << 4 |
                    input[j + 4] << 3 |
                    input[j + 5] << 2 |
                    input[j + 6] << 1 |
                    input[j + 7];
    }
}