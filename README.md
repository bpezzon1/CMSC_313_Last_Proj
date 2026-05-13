# CMSC_313_Last_Proj
Binary reader


How to use: compile BinaryReader.c, then provide a command line argument for the application to read. Example: gcc BinaryReader.c -o test; test binary.out; (binary.out in this example would be the binary file to read)

# Analysis of the different optimization levels of the assembly:

1. The first level of optimization results in an ASM file that is 154 lines long. Interestingly, this file contains calls to both printf and putchar, even though I used printf for each ascii character being printed. This seems to indicate that there was some optimization even though this file was created using the -O0 flag for no optimization.

2. The second level of optimization, created with the flag -O1, created a slightly smaller file that was 145 lines long. This file contains some small optimizations for the main and "is_Printable" functions. This level of optimixation also allocates less space on the stack at 56 bytes instead of the -O0 level allocating 80 bytes.

3. The final level of optimization, created with the -O3 flag, created a larger file at 206 lines. This level of optimization basically took the loop for printing all of the 2-didgit hex values and hard coded what was actually happening in the loop 16 times, instead of looping the defined MIDDLEBYTE times. Interestingly, it was not able to perfmorm this optimization for the other loops given they did not technically loop a set amount of times. This version of the assembly also allocated only 56 bytes on the stack instead of the -O0 flags 80 bytes.

4. The default optimization level is -O0, or no optimization. 
