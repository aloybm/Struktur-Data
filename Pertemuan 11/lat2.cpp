#include <iostream>
using namespace std;

class MHS {
    private: 
        string MHSname;
    public:
        MHS(string mhs){
            MHSname = mhs;
        }
        void getName() {
            cout << MHSname << endl;
        }
};

int main(){
    MHS mhs2("Aloy");
    mhs2.getName();
    return 0;
}
