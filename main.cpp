#include "systemc.h"
#include "stim.h"
#include "mon.h"
#include "adder1.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> ASig, BSig, SSig, COSig;
    sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
    stim Stim1("Stimulus");
    Stim1.A(ASig);
    Stim1.B(BSig);
    Stim1.Clk(TestClk);
    adder1 DUT("adder1");
    DUT.A(ASig);
    DUT.B(BSig);
    DUT.S(SSig);
    DUT.CO(COSig);
    mon Monitor1("Monitor");
    Monitor1.A(ASig);
    Monitor1.B(BSig);
    Monitor1.S(SSig);
    Monitor1.CO(COSig);
    Monitor1.Clk(TestClk);

    sc_start();

    return 0;
}
