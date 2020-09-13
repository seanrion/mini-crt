#include "minicrt.h"

int main(int argc, char* argv[])
{
    int i;
    FILE* fp;
    fp = fopen("test.txt", "w");
    fputc('d', fp);
    fclose(fp);
   

}