#include "systemc.h"
#include <iomanip>

using namespace std;

SC_MODULE(mon) {
    sc_in<bool> A,B,CO,S,Clk;

    void monitor() {
        cout << setw(10) << "Time";
        cout << setw(2) << "A";
        cout << setw(2) << "B";
        cout << setw(3) << "CO";
        cout << setw(2) << "S" << endl;
        while(true) {
            cout << setw(10) << sc_time_stamp();
            cout << setw(2) << A.read();
            cout << setw(2) << B.read();
            cout << setw(3) << CO.read();
            cout << setw(2) << S.read() << endl;
            wait();
        }
    }

    SC_CTOR(mon) {
        SC_THREAD(monitor);
        sensitive << Clk.pos();
    }
};
