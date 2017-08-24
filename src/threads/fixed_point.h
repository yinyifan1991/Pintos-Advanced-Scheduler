#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

/* Basic definitions of fixed point. */
typedef int fixed_t;
/* 16 LSB used for fractional part. */
#define F (1 << 16)

/* Convert integer to fixed point */
#define z2fp(x) ((fixed_t)(x * F))

/* Convert x to integer (rounding to nearest) */
#define fp2z_nearest(x) (x >= 0 ? ((x + (1 * (F - 1))) / F) \
           : ((x - (1 * (F - 1))) / F))

/* Convert x to integer (rounding toward zero) */
#define fp2z_0(x) (x / F)


/* fixed point plus fixed point */
#define fp_plus(x,y) (x + y)

/* fixed point minus fixed point */
#define fp_minus(x,y) (x - y)

/* Multiply two fixed point */
#define fp_multiply(x,y) ((fixed_t)(((int64_t) x) * y / F))

/* Divide two fixed-point */
#define fp_divide(x,y) ((fixed_t)((((int64_t) x) * F) / y))


/* fixed point plus integer */
#define fp_plus_mix(x,y) (x + (y * F))

/* fixed point minus integer */
#define fp_minus_mix(x,y) (x - (y * F))

/* Multiply a fixed point by an integer */
#define fp_multiply_mix(x,y) (x * y)

/* Devide a fixed point by an integer */
#define fp_divide_mix(x,y) (x / y)


#endif /* thread/fixed_point.h */
