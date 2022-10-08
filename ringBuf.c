#include <stdio.h>
#include <stdlib.h>
#include "ringBuf.h"

void initRingBuf(t_ringBuf* ringBuf, double initialValue, unsigned int size)
{
    size = 1 << size;
    ringBuf->content = malloc(size * sizeof(double));
    for(unsigned int i = 0; i < size; i++)
    {
        ringBuf->content[i] = initialValue;
    }
    ringBuf->mask = size - 1;
    ringBuf->offset = 0;
}

void deinitRingBuf(t_ringBuf* ringBuf)
{
    free(ringBuf->content);
    ringBuf->mask = 0;
    ringBuf->offset = 0;
}

void rollRingBuf(t_ringBuf* ringBuf)
{
    ringBuf->offset = (ringBuf-> offset - 1) & ringBuf->mask;
}

double getRingBuf(t_ringBuf* ringBuf, unsigned int element)
{
    return ringBuf->content[(element + ringBuf->offset) & ringBuf->mask];
}

void setRingBuf(t_ringBuf* ringBuf, unsigned int element, double value)
{
    ringBuf->content[(element + ringBuf->offset) & ringBuf->mask] = value;
}