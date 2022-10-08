#include "complex.h"

t_complex complexAdd(t_complex x, t_complex y)
{
    t_complex result;
    result.re = x.re + y.re;
    result.im = x.im + y.im;
    return result;
}

t_complex complexSub(t_complex x, t_complex y)
{
    t_complex result;
    result.re = x.re - y.re;
    result.im = x.im - y.im;
    return result;
}

t_complex complexMul(t_complex x, t_complex y)
{
    t_complex result;
    result.re = x.re * y.re - x.im * y.im;
    result.im = x.re * y.im + x.im * y.re;
    return result;
}

double complexSAbs(t_complex x)
{
    return x.re * x.re + x.im * x.im; 
}