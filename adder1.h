#include "systemc.h"
#include "myand.h"
#include "myxor.h"

SC_MODULE(adder1) {
    sc_in<bool> A,B;
    sc_out<bool> S,CO;
    myand n1;
    myxor x2;
    sc_signal<bool> S1, S2;

    SC_CTOR(adder1): n1("N1"), x2("X2") {
        n1.A(A);
        n1.B(B);
        n1.CO(CO);

        x2.A(A);
        x2.B(B);
        x2.S(S);
    }
};
