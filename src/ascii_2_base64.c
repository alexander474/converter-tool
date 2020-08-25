/*
 * I saw no point of inventing "the wheel" again so i took some inspiration for
 * the base64 encoder/decoder. This was purely because of the complex mathematics
 * required to solve this
 *
 * RESOURCE:
 * URL: https://nachtimwald.com/2017/11/18/base64-encode-and-decode-in-c/
 * DATE: 06.10.2019
 */
#include "ascii_2_base64.h"

struct Settings settings;
const char b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void ascii_2_base64() {
    char buffer[1024];

    if(settings.isFile == 0) {
        scanf("%[^0]s", buffer);
        fflush(stdin);
        printf("%s", base64_encode(buffer, strlen(buffer)));
    }else if(settings.isFile == 1){
        fscanf(settings.input, "%[^0]s",buffer);
        fflush(settings.input);
        char *outptr = base64_encode(buffer, strlen(buffer));
        fprintf(settings.output, "%s",  outptr);
        free(outptr);
    }

}

size_t getSize(size_t in){
    size_t size = 0;

    size = in;
    if(in % 3 != 0) size += 3 - (in % 3);
    size /= 3;
    size *= 4;

    return size;
}

char * base64_encode(const char* input, size_t len){
    char *output = 0;
    size_t  elen = 0;
    size_t  i = 0;
    size_t  j = 0;
    size_t  v = 0;

    if (input == NULL || len == 0) return NULL;

    elen = getSize(len);
    output = malloc(elen+1);
    output[elen] = '\0';

    for (i=0, j=0; i<len; i+=3, j+=4) {
        v = input[i];
        v = i+1 < len ? v << 8 | input[i+1] : v << 8;
        v = i+2 < len ? v << 8 | input[i+2] : v << 8;

        output[j]   = b64chars[(v >> 18) & 0x3F];
        output[j+1] = b64chars[(v >> 12) & 0x3F];
        if (i+1 < len) {
            output[j+2] = b64chars[(v >> 6) & 0x3F];
        } else {
            output[j+2] = '=';
        }
        if (i+2 < len) {
            output[j+3] = b64chars[v & 0x3F];
        } else {
            output[j+3] = '=';
        }
    }


    return output;
}