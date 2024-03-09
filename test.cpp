#include<iostream>
#include "utils.h"
#include "NSGP2.cpp"
#include "NSGP3.cpp"
#include<fstream>
using namespace std;
int main(){
    //gcd
    cout<<gcd(3,15)<<endl;
    cout<<gcd(15,6)<<endl;
    cout<<gcd(100,73)<<endl;

    NSGP2 S1 = NSGP2(23,37);
    cout<<S1<<endl;
    S1.print_gap();
    cout<<endl;
    ofstream fout=ofstream();
    string f = "test1.txt";
    fout.open(f,ios_base::ate);
    fout<<S1.a<<endl;
    S1.print_gap(fout);
    fout.close();
    system("cd");
    // system(("python plot_gap.py "+f).c_str());

    
    NSGP3 S2 = NSGP3(S1,114);
    cout<<S2<<endl;
    f = "test2.txt";
    fout.open(f,ios_base::ate);
    fout<<S2.a<<endl;
    S1.print_gap(fout);
    fout<<S2.c<<endl;
    S2.print_gap(fout);
    fout<<S2.s<<endl;
    fout.close();
    system("cd");
    system(("python plot_delta.py "+f).c_str());
    
    return 0;
}