typedef struct ringBufStruct
{
    double* content;
    unsigned int mask;
    unsigned int offset;
} t_ringBuf;

void initRingBuf(t_ringBuf* ringBuf, double initialValue, unsigned int size);
void deinitRingBuf(t_ringBuf* ringBuf);
void rollRingBuf(t_ringBuf* ringBuf);
double getRingBuf(t_ringBuf* ringBuf, unsigned int element);
void setRingBuf(t_ringBuf* ringBuf, unsigned int element, double value);