#include <stdio.h>

#define MIDDLEBYTE 16

// Is this char ascii?
int is_printable(unsigned char c)
{
    return (c >= 32 && c <= 126);
}

int main(int argc, char *argv[])
{
    FILE *fileptr;
    unsigned char buffer[MIDDLEBYTE];
    size_t bytesRead;
    int offset = 0;
    int i;

    // Open file in read binary mode
    fileptr = fopen(argv[1], "rb");
    // Make sure file opened
    if (fileptr == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Read in bytes
    while ((bytesRead = fread(buffer, 1, MIDDLEBYTE, fileptr)) > 0) {

        // Print 8-digit hex
        printf("%08lX ", offset);

        // Print hex
        for (i = 0; i < MIDDLEBYTE; i++) {
            if (i < (int)bytesRead) {
                // Prints as 2 didgit hex
                printf("%02X ", buffer[i]);
            }
        }

        // Print as ascii (if possible)
        printf("|");
        for (i = 0; i < (int)bytesRead; i++) {
            if (is_printable(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf("%c", '.');
            }
        }
        printf("|\n");

        // goto next byte to read
        offset += bytesRead;
    }

    // Close file and rtn
    fclose(fileptr);
    return 0;
}