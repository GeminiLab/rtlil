#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "cmake-build-debug/rtl.h"

sim s;

int main() {
    memset(&s, 0, sizeof(sim));

    int a[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, };
    int b[] = { 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

    puts("   a   b   t ^:2 ^:0 b:2 ^:t   g");
    puts("================================");
    for (int i = 0; i < 16; ++i) {
        s.a = a[i];
        s.b = b[i];
        s.a2 = ((i & 3) >= 2);

        do_sim(&s);
        printf("   %d   %d   %d   %d   %d   %d   %d   %d\n", s.a, s.b, s.a2, s.c, s.d, s.e, s.f, s.g);
    }

    return 0;
}

/*
printf("## o: %d n: %d k: %d\n",
       s.dg_5.o, s.dg_5.n, s.dg_5.k);
printf("## o: %d n: %d k: %d\n",
       s.dg_6.o, s.dg_6.n, s.dg_7.k);
printf("## o: %d n: %d k: %d\n",
       s.dg_7.o, s.dg_7.n, s.dg_7.k);
       */