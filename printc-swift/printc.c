//
//  printc.c
//  printc
//
//  Created by hejunqiu on 2017/7/17.
//  Copyright © 2017年 hejunqiu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int printImpl(const char *text, size_t textLength, bool hasMark) {
    char *buffer = NULL;
    if (hasMark) {
        buffer = calloc(textLength + 7, 1);
    } else {
        buffer = (char *)text;
        goto end;
    }
    memcpy(buffer, "\e[", 2);
    memcpy(buffer + 2, text, textLength);
    memcpy(buffer + 2 + textLength, "\e[0m", 4);
end:
    ;
    int ret = fprintf(stderr, buffer);
    return ret;
}
