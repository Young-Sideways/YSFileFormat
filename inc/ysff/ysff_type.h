/*******************************************************************************
 * @file      ysff.h
 * @author    Young Sideways
 * @brief     
 * @date      15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef YSFF_TYPE_H_
#define YSFF_TYPE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdint.h>

#pragma endregion

/*
--------------------------------------------------------------------- DATA FIELDS EXPLANATION ----------------------------------------------------------------------

bytes   :   [                                                                        0 byte                                                                        ]
bits    :   [        0        ][        1        ][        2        ][        3        ][        4        ][        5        ][        6        ][        7        ]

INTEGER   : [                        YS_INT                         ][            YS_INT_SIGNED           ][                       YS_INT_8                        ]
                                                                                 YS_INT_UNSIGNED                                   YS_INT_16
                                                                                 YS_INT_BITFIELD                                   YS_INT_32
                                                                                                                                   YS_INT_64
                                                                                                                                   YS_INT_128

FLOAT     : [                       YS_FLOAT                        ][           YS_FLOAT_SINGLE          ][           YS_FLOAT_REAL            ][    RESERVED     ]
                                                                                 YS_FLOAT_DOUBLE                     YS_FLOAT_IMAGINARY
                                                                                                                      YS_FLOAT_COMPLEX

STRING    : [                       YS_STRING                       ][          YS_STRING_SINGLE          ][          YS_STRING_CHAR_8           ][    RESERVED     ]
                                                                                YS_STRING_MULTI                       YS_STRING_CHAR_16
                                                                                                                      YS_STRING_CHAR_32

*/

#pragma region --- MACRO ---

#define YS_UNDEFINED        (0x0 )

#define YS_TYPE_INT         (0x1 )
#define YS_TYPE_FLOAT       (0x2 )
#define YS_TYPE_STRING      (0x3 )
#define YS_TYPE_TIMESTAMP   (0x4 )
#define YS_TYPE_UUID        (0x5 )
#define YS_TYPE_MASK        (0x7 )


#define YS_INT_SIGNED       (0x8 )
#define YS_INT_UNSIGNED     (0x10)
#define YS_INT_BITFIELD     (0x18)
#define YS_INT_SIGN_MASK    (0x18)

#define YS_INT_8            (0x20)
#define YS_INT_16           (0x40)
#define YS_INT_32           (0x60)
#define YS_INT_64           (0x80)
#define YS_INT_128          (0xA0)
#define YS_INT_SIZE_MASK    (0xE0)



#define YS_FLOAT_SINGLE     (0x8 )
#define YS_FLOAT_DOUBLE     (0x10)
#define YS_FLOAT_SIZE_MASK  (0x18)

#define YS_FLOAT_REAL       (0x20)
#define YS_FLOAT_IMAGINARY  (0x40)
#define YS_FLOAT_COMPLEX    (0x60)
#define YS_FLOAT_TYPE_MASK  (0x60)



#define YS_STRING_SINGLE    (0x8 )
#define YS_STRING_MULTI     (0x10)
#define YS_STRING_MASK      (0x18)

#define YS_STRING_CHAR_8    (0x20)
#define YS_STRING_CHAR_16   (0x40)
#define YS_STRING_CHAR_32   (0x60)
#define YS_STRING_CHAR_MASK (0x60)



#define DEFAULT_TIMESTAMP   \
    (ys_timestamp_t){       \
        .sec  = INT64_C(0), \
        .nsec = INT32_C(0)  \
    }
#define DEFAULT_UUID        \
    (ys_uuid_t){            \
        .hi = UINT64_C(0),  \
        .lo = UINT64_C(0)   \
    };



#define YS_SIZE_MIN UINT32_C(0)
#define YS_SIZE_MAX UINT32_MAX

#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct ys_timestamp_s {
    int64_t sec ;
    int32_t nsec;
} ys_timestamp_t;

typedef struct ys_uuid_s {
    uint64_t lo;
    uint64_t hi;
} ys_uuid_t;

typedef uint32_t ys_size_t;

typedef struct ys_string_s {
    uint64_t  offset;
    ys_size_t size  ;
} ys_string_t;

typedef struct ys_int128_s {
    uint64_t lo;
    int64_t  hi;
} ys_int128_t;
typedef struct ys_uint128_s {
    uint64_t lo;
    uint64_t hi;
} ys_uint128_t;

typedef struct { float value; }  ys_float_i ;
typedef struct { double value; } ys_double_i;

typedef struct ys_float_c_s {
    float real;
    float imaginary;
} ys_float_c;
typedef struct ys_double_c_s {
    double real;
    double imaginary;
} ys_double_c;

typedef union ys_data_u {
    uint8_t         v_uint8_t    ;
    uint16_t        v_uint16_t   ;
    uint32_t        v_uint32_t   ;
    uint64_t        v_uint64_t   ;
    __uint128_t     v_uint128_t  ;
    int8_t          v_int8_t     ;
    int16_t         v_int16_t    ;
    int32_t         v_int32_t    ;
    int64_t         v_int64_t    ;
    __int128_t      v_int128_t   ;

    float           v_float      ;
    double          v_float_i    ;
    float _Complex  v_float_c    ;
    double          v_double     ;
    double          v_double_i   ;
    double _Complex v_double_c   ;

    ys_string_t     v_string_t   ;

    ys_timestamp_t  v_timestamp_t;
    ys_uuid_t       v_uuid_t     ;
} ys_data_t;

typedef struct ys_field_s {
    uint8_t   type;
    ys_data_t data;
} ys_field_t;

#pragma endregion

#endif // !YSFF_TYPE_H_
