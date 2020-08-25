/*
 * Used this resources for the formulas in cæsar_cyph() function on line 33 -> 50.
 *
 * RESOURCE:
 * URL: https://github.com/Gallefray/vogon/blob/master/main.c
 * DATE: 01.10.2019
 */
#include "rot13_2_ascii.h"


struct Settings settings;
void rot13_2_ascii() {
    unsigned char i;

    if(settings.isFile == 0) {
        while(scanf("%c", &i) != EOF) {
            if(i >= 97 && i <= 122){
                if(i > 109){
                    i -= 13;
                }else if(i <= 109){
                    i += 13;
                }
            }else if(i >= 65 && i <= 90){
                if(i > 77){
                    i -= 13;
                }else if(i <= 77){
                    i += 13;
                }
            }
            printf("%c", i);
        }
        fflush(stdin);
    }else if(settings.isFile == 1){
        while(fscanf(settings.input, "%c", &i) != EOF) {
            if(i >= 97 && i <= 122){
                if(i > 109){
                    i -= 13;
                }else if(i <= 109){
                    i += 13;
                }
            }else if(i >= 65 && i <= 90){
                if(i > 77){
                    i -= 13;
                }else if(i <= 77){
                    i += 13;
                }
            }
            fprintf(settings.output, "%c", i);
        }
        fflush(settings.input);
    }

}