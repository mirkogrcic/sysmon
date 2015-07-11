#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "helpers.hpp"
#include "cpu.hpp"

using namespace std;

int main()
{
    CPU_TIME* last = get_cpu_time();
    while(1){
        sleep(1000);
        CPU_TIME* nw = get_cpu_time();
        cout << get_cpu_percent(last, nw) << endl;
        delete last;
        last = nw;
    }
    return 0;
}
