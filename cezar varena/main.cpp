#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    FILE *iFile;
    iFile = fopen("cezark.in", "r");
    FILE *oFile;
    oFile = fopen("cezark.out", "w");
    rewind(iFile);
    char c;
    c = fgetc(iFile);
    while(c != 10)
    {
        c = (c - 96)%26 + 97;
        fputc(c, oFile);
        c = fgetc(iFile);
    }
    fclose(iFile);
    fclose(oFile);
    return 0;
}
