typedef struct complexStruct
{
    double re;
    double im;
} t_complex;

t_complex complexAdd(t_complex, t_complex);
t_complex complexSub(t_complex, t_complex);
t_complex complexMul(t_complex, t_complex);
double complexSAbs(t_complex);