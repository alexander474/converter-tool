/*
 * I saw no point of inventing "the wheel" again so i took some inspiration for
 * the base64 encoder/decoder. This was purely because of the complex mathematics
 * required to solve this
 *
 * RESOURCE:
 * URL: https://github.com/elzoughby/Base64/blob/master/base64.c
 * DATE: 07.10.2019
 */
#include "base64_2_ascii.h"

struct Settings settings;
const char base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64_2_ascii() {
    char buffer[2048];

    if(settings.isFile == 0) {
        scanf("%s", buffer);
        fflush(stdin);
        printf("%s", base64_decode(buffer, strlen(buffer)));
    }else if(settings.isFile == 1){
        fscanf(settings.input, "%s",buffer);
        fflush(settings.input);
        char *outptr = base64_decode(buffer, strlen(buffer));
        fprintf(settings.output, "%s",  outptr);
        free(outptr);
    }

}

size_t getsize(size_t in){
    size_t size = 0;

    size = in;
    if(in % 3 != 0) size += 3 - (in % 3);
    size /= 3;
    size *= 4;

    return size;
}

char* base64_decode(const char* input, size_t len){
    char *output = 0;
    char counts = 0;
    char buffer[4];
    size_t elen = 0;
    int i = 0, p = 0;

    if (input == NULL || len == 0) return NULL;

    elen = getsize(len);
    output = malloc(elen+1);
    output[elen] = '\0';

    for(i = 0; input[i] != '\0'; i++) {
        char k;
        for(k = 0 ; k < 64 && base64chars[k] != input[i]; k++);
        buffer[counts++] = k;
        if(counts == 4) {
            output[p++] = (buffer[0] << 2) + (buffer[1] >> 4);
            if(buffer[2] != 64)
                output[p++] = (buffer[1] << 4) + (buffer[2] >> 2);
            if(buffer[3] != 64)
                output[p++] = (buffer[2] << 6) + buffer[3];
            counts = 0;
        }
    }

    // todo CHECK IF MALLOC NEEDS TO FREE MEMORY
    return output;
}
