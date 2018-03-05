//
//  main.cpp
//  fdtd
//
//  Created by 曾舟 on 2/22/18.
//

#include <stdio.h>
#include <cmath>
#include "grid.hpp"
#include "lcfg_static.h"
#include "config.h"
#include "params.hpp"

using namespace std;
int main(int argv, char** args) {
    
    testconfig m;
    m = readParameters(args[1]); // read parameters from the configuration file
        
    double dx = 0.01;
    double dt = 1.0 / sqrt(2.0) * dx / 3.0e8;

    configuration config{60, 60, 2, 10, dx, dt,
        1, 1, 0.2, 0.2, 1, 3};

   grid a(config);
   a.snapshotInit(31);

   for (int Time = 0; Time <= 300; ++Time) {
       a.update(Time);
       if (Time % 1 == 0)
           a.snapshot();
   }

    cout << "Program successuflly exited" << endl;
    return 0;
}
