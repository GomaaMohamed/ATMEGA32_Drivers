/*****************************************************************************
* @file:    STD_TYPES.h
* @author:  Copyright (c) 2023 Gomaa Mohammed.
* @license: GNU GPL version 3 or later.
*			This is free software: you are free to change and redistribute it.  
*			There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Fri, 8 Sep 2023 18:21:12 +0200
* @brief:   Standard Types Library.
******************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       u8;
typedef unsigned int        u16;
typedef unsigned long       u32;


typedef signed char     s8;
typedef signed int      s16;
typedef signed long     s32;

typedef float     f32;
typedef double    f64;

typedef enum
{
    FALSE,
    TRUE
} boolean;

/* NULL PTR */
#define   NULL   (void *)0

#endif
