#include "hex_2_ascii.h"

struct Settings settings;
void hex_2_ascii() {
    unsigned int i;

    if(settings.isFile == 0) {
        while(scanf("%x", &i) != EOF) {
            printf("%c", i);
        }
        fflush(stdin);
    }else if(settings.isFile == 1){
        while(fscanf(settings.input, "%x", &i) != EOF) {
            fprintf(settings.output, "%c", i);
        }
        fflush(settings.input);
    }

}