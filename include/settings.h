#ifndef C_ON_LINUX_HOME_EXAM_SETTINGS_H
#define C_ON_LINUX_HOME_EXAM_SETTINGS_H

#include <stdio.h>

struct Settings{
    int isFile;
    FILE *input;
    FILE *output;
};

extern struct Settings settings;


#endif //C_ON_LINUX_HOME_EXAM_SETTINGS_H
