#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){
    FILE *p;
    FILE *q;
    char a[4];
    char b[4];
    uint32_t x , y;
    p = fopen(argv[1], "r");
    q = fopen(argv[2], "r");
    if ( (p == NULL) || (q == NULL)){printf("syntax : add-nbo <file1> <file2>\nsample : add-nbo a.bin c.bin\n");return 0;}
    fscanf(p, "%s", &x);
    fscanf(q, "%s", &y);
    //printf("x : %x, y : %x", x, y);
    x = htonl(x);
    y = htonl(y);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", x, x, y, y, (x+y), (x+y));
    return 0;
}