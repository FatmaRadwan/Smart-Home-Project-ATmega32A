/*Header File Guard*/
#ifndef     BIT_MATH_H
#define     BIT_MATH_H


#define     SET_BIT(VAR , BIT_NUM)        VAR|=(1<<BIT_NUM)
#define     CLR_BIT(VAR , BIT_NUM)        VAR&=~(1<<BIT_NUM)
#define     TGL_BIT(VAR , BIT_NUM)        VAR^=(1<<BIT_NUM)

#define     GET_BIT(VAR , BIT_NUM)        (VAR >> BIT_NUM) & 1

#define     CIR_RIGHT(VAR , BIT_NUM)      (VAR >> BIT_NUM)| (VAR << (sizeof(VAR)-BIT_NUM))
#define     CIR_LEFT(VAR , BIT_NUM)       (VAR << BIT_NUM)| (VAR >> (sizeof(VAR)-BIT_NUM))

#define     SET_HIGH(VAR)                 VAR|= (15 << (sizeof(VAR)-4))
#define     CLR_HIGH(VAR)                 VAR&=~(15 << (sizeof(VAR)-4))
#define     TGL_HIGH(VAR)                 VAR^= (15 << (sizeof(VAR)-4))

#define     SET_LOW(VAR)                  VAR|=(15)
#define     CLR_LOW(VAR)                  VAR&=~(15)
#define     TGL_LOW(VAR)                  VAR^=(15)


#endif