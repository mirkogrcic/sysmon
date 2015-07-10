#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#include "helpers.hpp"
#include "cpu.hpp"

using namespace std;

int main()
{
    CPU_TIME last = *get_cpu_time();

    printf("%u %u %u %u\n",
        (unsigned int)last.user,
        (unsigned int)last.userLow,
        (unsigned int)last.sys,
        (unsigned int)last.idle);
    sleep(1000);
    main();

    return 0;
}
