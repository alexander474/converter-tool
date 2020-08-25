#ifndef C_ON_LINUX_HOME_EXAM_ASCII_2_BASE64_H
#define C_ON_LINUX_HOME_EXAM_ASCII_2_BASE64_H

#include "settings.h"
#include <stdlib.h>
#include <memory.h>

void ascii_2_base64();

char * base64_encode(const char* input, size_t len);

size_t getSize(size_t in);

#endif
