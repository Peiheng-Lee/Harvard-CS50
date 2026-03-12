#include <stdio.h>
#include <stdint.h>

// unsigned 8-bit integer
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // rb: read binary
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

        fclose(dst);
        fclose(src);
}
