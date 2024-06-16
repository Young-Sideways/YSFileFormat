/*******************************************************************************
 * @file ysff.h
 * @author Young Sideways
 * @brief 
 * @version 0.2.3
 * @date 15.06.2024
 * @copyright young.sideways@mail.ru, Copyright (c) 2024. All right reserved.
 ******************************************************************************/

#ifndef YSFF_H_
#define YSFF_H_

#pragma once

#include <string.h>
#include <wchar.h>
#include <uchar.h>

#include "ysff_type.h"

#define YSFF_FIELD(value) _Generic( (value)                                                                                                                                                          , \
    int8_t         : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_SIGNED    | YS_INT_8          ), .data.v_uint8_t     = (int8_t         )value                                                   }, \
    int16_t        : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_SIGNED    | YS_INT_16         ), .data.v_uint16_t    = (int16_t        )value                                                   }, \
    int32_t        : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_SIGNED    | YS_INT_32         ), .data.v_uint32_t    = (int32_t        )value                                                   }, \
    int64_t        : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_SIGNED    | YS_INT_64         ), .data.v_uint64_t    = (int64_t        )value                                                   }, \
    __int128_t     : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_SIGNED    | YS_INT_128        ), .data.v_uint128_t   = (__int128_t     )value                                                   }, \
    uint8_t        : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_UNSIGNED  | YS_INT_8          ), .data.v_int8_t      = (uint8_t        )value                                                   }, \
    uint16_t       : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_UNSIGNED  | YS_INT_16         ), .data.v_int16_t     = (uint16_t       )value                                                   }, \
    uint32_t       : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_UNSIGNED  | YS_INT_32         ), .data.v_int32_t     = (uint32_t       )value                                                   }, \
    uint64_t       : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_UNSIGNED  | YS_INT_64         ), .data.v_int64_t     = (uint64_t       )value                                                   }, \
    __uint128_t    : (ys_field_t){ .type = (YS_TYPE_INT    | YS_INT_UNSIGNED  | YS_INT_128        ), .data.v_int128_t    = (__uint128_t    )value                                                   }, \
    float          : (ys_field_t){ .type = (YS_TYPE_FLOAT  | YS_FLOAT_SINGLE  | YS_FLOAT_REAL     ), .data.v_float       = (float          )value                                                   }, \
    float _Complex : (ys_field_t){ .type = (YS_TYPE_FLOAT  | YS_FLOAT_SINGLE  | YS_FLOAT_COMPLEX  ), .data.v_float_c     = (float _Complex )value                                                   }, \
    double         : (ys_field_t){ .type = (YS_TYPE_FLOAT  | YS_FLOAT_DOUBLE  | YS_FLOAT_REAL     ), .data.v_double      = (double         )value                                                   }, \
    double _Complex: (ys_field_t){ .type = (YS_TYPE_FLOAT  | YS_FLOAT_DOUBLE  | YS_FLOAT_COMPLEX  ), .data.v_double_c    = (double _Complex)value                                                   }, \
    char*          : (ys_field_t){ .type = (YS_TYPE_STRING | YS_STRING_SINGLE | YS_STRING_CHAR_8  ), .data.v_string_t    = (ys_string_t){ .offset = (int64_t)(void*)value, .size = strlen((char*)value)  } }, \
    wchar_t*       : (ys_field_t){ .type = (YS_TYPE_STRING | YS_STRING_MULTI  | YS_STRING_CHAR_8  ), .data.v_string_t    = (ys_string_t){ .offset = (int64_t)(void*)value, .size = wstrlen((wchar_t*)value) } }, \
    char16_t*      : (ys_field_t){ .type = (YS_TYPE_STRING | YS_STRING_SINGLE | YS_STRING_CHAR_16 ), .data.v_string_t    = (ys_string_t){ .offset = (int64_t)(void*)value, .size = 0              } }, \
    char32_t*      : (ys_field_t){ .type = (YS_TYPE_STRING | YS_STRING_SINGLE | YS_STRING_CHAR_32 ), .data.v_string_t    = (ys_string_t){ .offset = (int64_t)(void*)value, .size = 0              } }, \
    ys_timestamp_t : (ys_field_t){ .type = (YS_TYPE_TIMESTAMP                                     ), .data.v_timestamp_t = value                                                                  }, \
    ys_uuid_t      : (ys_field_t){ .type = (YS_TYPE_UUID                                          ), .data.v_uuid_t      = value                                                                  }, \
    default        : (ys_field_t){ .type = (YS_UNDEFINED                                          ), .data.v_uuid_t      = DEFAULT_UUID                                                           }, \
    )

#endif // !YSFF_H_
