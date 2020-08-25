# PG3400 Exam 2019 (Programming in C for Linux)
This project builds a tool to be used for converting between different 
kinds of "encodings".

The purpose of this project is to make a single **tool** binary that can
behave as different kinds of converters based on the name it was invoked
with.


You can convert these encodings with this tool
* *src/ascii_2_hex.c*
* *src/hex_2_ascii.c*
* *src/ascii_2_rot13.c*
* *src/rot13_2_ascii.c*

## Comments

I've used some resources as inspiration and for mathematic help. When i used a resource, then i will mark it in the code.

### Settings.h & global variable

I choose to extract my settings into a header file where i have a global variable. I choose this approach because i didn't know if we could change any of the tests made by the teacher. By this i mean adding for example function parameters.

### Future dev

If we had more time i would have extracted code into functions and made my code more "DRY" (Do Not Repeat Yourself). I would also have added more tests and fixed imports so i either import into my .h files or .c, not mixing them.



## How to test

### ascii to hex
~~~~
./ascii2hex data/ascii_test_1.txt data/hex_output.txt
diff data/hex_output.txt data/hex_test_1.txt
~~~~
### hex to ascii
~~~~
./hex2ascii data/hex_test_1.txt data/ascii_output.txt
diff data/ascii_output.txt data/ascii_test_1.txt
~~~~
### ascii to rot13
~~~~
./ascii2rot13 data/ascii_test_1.txt data/rot13_output.txt
diff data/rot13_output.txt data/rot13_test_1.txt
~~~~
### rot13 to ascii
~~~~
./rot132ascii data/rot13_test_1.txt data/ascii_output.txt
diff data/ascii_output.txt data/ascii_test_1.txt
~~~~
### ascii to base64 -
~~~~
./ascii2base64 data/ascii_test_1.txt data/base64_output.txt
diff data/base64_output.txt data/base64_test_1.txt
~~~~
- My tests are passing, but i get an error that's saying that "data/base64_test_1.txt" is having "EOF" on "data/base64_output.txt" after byte 1180, in line 1. I didn't have time to completely solve this issue.

### base64 to ascii

~~~~
./base642ascii data/base64_test_1.txt data/ascii_output.txt
diff data/ascii_output.txt data/ascii_test_1.txt
~~~~
