#include <stdio.h>

#include "ysff/ysff.h"


int main() {
    ys_field_t arr[] = {
        YSFF_FIELD(5),
        YSFF_FIELD(5.9)
    };
    printf("arr[0] : %d\n", arr[0].type & YS_TYPE_MASK);
    printf("arr[1] : %d\n", arr[1].type & YS_TYPE_MASK);
    return 0;
}