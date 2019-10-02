#include <stdio.h>

void main()
{
    char aa = 0b00000001;
    char bb = 0b00000010;
    char cc = 0b00000100;
    char dd = 0b00001000;

    printf("aa=%d, bb=%d, cc=%d, dd=%d\n", aa, bb, cc, dd);

    char ee = aa & bb ;
    //       0000 0001
    // AND   0000 0010
    // ----------------
    //ee=    0000 0000
    //ee=... 0*2^3 + 0*2^2 + 0*2^1 + 0*2^0

    char ff = aa | bb ;
    //       0000 0001
    //  OR   0000 0010
    // ----------------
    //ff=    0000 0011
    //ff=... 0*2^3 + 0*2^2 + 1*2^1 + 1*2^0

    char gg = ff ^ aa ;
    //       0000 0011
    // XOR   0000 0001
    // ----------------
    //gg=    0000 0010
    //gg=... 0*2^3 + 0*2^2 + 1*2^1 + 0*2^0

    printf("ee=%d, ff=%d, gg=%d\n", ee, ff, gg);

    char hh = aa << 1 ;
    char ii = hh << 1 ;
    char jj = ii << 1 ;
    char ll = jj << 1 ;
    printf("hh=%d, ii=%d, jj=%d, ll=%d\n", hh, ii, jj, ll);

    printf("hh>>1 : %d, ii>>1 : %d, jj>>1 : %d, ll>>1 : %d\n", hh>>1, ii>>1, jj>>1, ll>>1);

    char mm = 0;
    mm = (aa) | (aa << 2) | (aa << 5);
    printf("mm=%d\n", mm);

    //mm=37
    //mm=        32+     4 +     1
    //mm=... 1*2^4 + 1*2^2 + 1*2^0
    //1*2^5= aa << 5 = 0b10000
    //1*2^2= aa << 2 = 0b00100
    //1*2^0= aa << 5 = 0b00101
    //mm =  0b10000 OR 0b00100 OR 0b00101
    //mm =  37

}
