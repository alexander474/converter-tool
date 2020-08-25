#include "ascii_2_hex.h"
#include "ascii_2_rot13.h"
#include "hex_2_ascii.h"
#include "rot13_2_ascii.h"
#include "ascii_2_base64.h"
#include "base64_2_ascii.h"

enum Mode {
    HEX_2_ASCII,
    ASCII_2_HEX,
    rot13_2_ASCII,
    ASCII_2_rot13,
    ASCII_2_BASE64,
    BASE64_2_ASCII,
    MODE_ERROR
};

struct Settings settings;

enum Mode getMode(char *program_name) {

  if (!program_name)
    return MODE_ERROR;

  if (strcmp("/hex2ascii", program_name) == 0)
    return HEX_2_ASCII;
  if (strcmp("/ascii2hex", program_name) == 0)
    return ASCII_2_HEX;
  if (strcmp("/rot132ascii", program_name) == 0)
    return rot13_2_ASCII;
  if (strcmp("/ascii2rot13", program_name) == 0)
    return ASCII_2_rot13;
  if (strcmp("/ascii2base64", program_name) == 0)
      return ASCII_2_BASE64;
  if (strcmp("/base642ascii", program_name) == 0)
      return BASE64_2_ASCII;

  return MODE_ERROR;
}

int main(int argc, char *argv[]) {
    char *program_name = strrchr(argv[0], '/');
    if (!(argc == 1 || argc == 3)) {
        printf("Usages:\n");
        printf(".%s\n", program_name);
        printf(".%s <input file> <output file>\n", program_name);
        return EXIT_FAILURE;
    }
    char *input_name = argv[1];
    char *output_name = argv[2];

    FILE *fptIN = 0;
    FILE *fptOUT = 0;

  if((fptIN = fopen(input_name, "r")) == NULL){
      // Could probably use error print here
      printf("COULD NOT FIND FILE: %s\n", input_name);
      return EXIT_FAILURE;
  }
  if((fptOUT = fopen(output_name, "w")) == NULL){
      if(fptIN != NULL){
          /*
           * Need to close first file before exit if the second file
           * didnt open.
          */
          fclose(fptIN);
      }
      printf("COULD NOT FIND FILE: %s\n", input_name);
      return EXIT_FAILURE;
  }

  enum Mode mode = getMode(program_name);
  settings.isFile = 1; // true
  settings.input = fptIN;
  settings.output = fptOUT;

  switch (mode) {
    case HEX_2_ASCII:
        hex_2_ascii();
      break;
    case ASCII_2_HEX:
        ascii_2_hex();
      break;
    case rot13_2_ASCII:
        rot13_2_ascii();
      break;
    case ASCII_2_rot13:
        ascii_2_rot13();
      break;
    case ASCII_2_BASE64:
        ascii_2_base64();
    case BASE64_2_ASCII:
        base64_2_ascii();
    default:
      break; // Just to make the code compile
  }

  if(fptIN != NULL) fclose(fptIN); // Closing input file
  if(fptOUT != NULL) fclose(fptOUT); // Closing output file
  return EXIT_SUCCESS;
}
