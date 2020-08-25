#include "ascii_2_hex.h"

struct Settings settings;
void ascii_2_hex() {
    char buffer[1024];

    if(settings.isFile == 0) {
        scanf("%[^0]s", buffer);
        fflush(stdin);
    }else if(settings.input != NULL && settings.output != NULL){
        fscanf(settings.input, "%[^0]s",buffer);
        fflush(settings.input);
    }

    for(int i = 0; buffer[i] != '\0'; i++){
        if(settings.isFile == 0) {
            if (buffer[i + 1] != '\0') {
                printf("%02x ", buffer[i]);
            } else {
                printf("%02x", buffer[i]);
            }
        }else if(settings.isFile == 1){
            if (buffer[i + 1] != '\0') {
                fprintf(settings.output, "%02x ", buffer[i]);
            } else {
                fprintf(settings.output, "%02x", buffer[i]);
            }
        }
    }

}

