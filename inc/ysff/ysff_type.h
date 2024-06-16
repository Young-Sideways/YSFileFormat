/*******************************************************************************
 * @file ysff.h
 * @author Young Sideways
 * @brief 
 * @date 15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef YSFF_TYPE_H_
#define YSFF_TYPE_H_

#pragma once

#pragma region --- INCLUDE ---

#include <stdint.h>
#include <stdlib.h>

#pragma endregion

#pragma region --- MACRO ---

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

#pragma endregion

#pragma region --- TYPEDEF ---

typedef struct ys_timestamp_s {
    int64_t sec ;
    int32_t nsec;
} ys_timestamp_t;

typedef struct ys_uuid_s {
    uint64_t hi;
    uint64_t lo;
} ys_uuid_t;

typedef enum ys_data_type_e : uint8_t {
    YS_UNDEFINED  = 0x0,

    YS_NONE       = 0x1,

    YS_INT        = 0x2,
    YS_FLOAT      = 0x3,
    YS_STRING     = 0x4,
    YS_TIMESTAMP  = 0x5,
    YS_UUID       = 0x6

    // RESERVED
} ys_data_type_t;

typedef enum ys_int_sign_e : uint8_t {
    YS_INT_SIGNED   = 0x0,
    YS_INT_UNSIGNED = 0x1
} ys_int_sign_t;
typedef enum ys_int_type_e : uint8_t {
    YS_INT_8  = 0x0,
    YS_INT_16 = 0x1,
    YS_INT_32 = 0x2,
    YS_INT_64 = 0x3
} ys_int_type_e;

typedef enum ys_float_type_e : uint8_t {
    YS_FLOAT_SINGLE = 0x0,
    YS_FLOAT_DOUBLE = 0x1
} ys_float_type_t;

typedef enum : uint8_t {
    YS_STRING_ASCII,
    YS_STRING_MULTI,
    YS_STRING_UTF8 ,
    YS_STRING_UTF16,
    YS_STRING_UTF32
} ys_encoding_t;

typedef enum ys_byte_order_e : uint8_t {
    YS_BIG_ENDIAN    = 0x0,
    YS_LITTLE_ENDIAN = 0x1,
} ys_byte_order_t;

typedef uint32_t ys_size_t;
#define YST_DATA_SIZE_MIN UINT32_C(0)
#define YST_DATA_SIZE_MAX UINT32_MAX



/*
------------------------------------------------ DATA FIELDS EXPLANATION ------------------------------------------------

INTEGER :   [                                             0 byte                                               ]
      bits: [   0..2    ][           3             ][                    4..6                      ][    7     ]
            [  YS_INT   ][ YS_INT_SIGNED | YS_INT_UNSIGNED ][ YS_INT_8 | YS_INT_16 | YS_INT_32 | YS_INT_64 ][ RESERVED ]

FLOAT   :   [                                             0 byte                                               ]
      bits: [   0..2    ][            3            ][                           4..7                           ]
            [ YS_FLOAT  ][  YS_SINGLE | YS_DOUBLE  ][                         RESERVED                         ]

STRING  :   [                                             0 byte                                               ]
      bits: [   0..2    ][            3            ][                           4..7                           ]
            [ YS_STRING ][  YS_SINGLE | YS_DOUBLE  ][                         RESERVED                         ]         
*/
#pragma endregion



#endif // !YSFF_TYPE_H_
