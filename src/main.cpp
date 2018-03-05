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

using namespace std;
int main(int argv, char** args) {
    
    /*********** Added by Han Zhang on 3/2/18 ***********/
    
    char filenamePrefix[1000], configFilename[1000];
    
    strcpy(configFilename, args[1]);  //args is the address of the config file
    //char configFilename[]="./configfile.cfg";
    printf("configFilename = %s \n",configFilename);
    // load the entire config file into memory
    parseConfigFile(configFilename); //in config.c  analyze config file, check if status is good
    if (FILE *file = fopen(configFilename, "r")){
        fclose(file);}
    else
    { return 1;}
    
    testconfig m;
    
    m.timelength = getParamFromConfigFileWDefault_int("parameters.timelength",0);
    m.dimX = getParamFromConfigFileWDefault_int("parameters.dimensionX",0);
    m.dimY = getParamFromConfigFileWDefault_int("parameters.dimensionY",0);
    m.dimZ = getParamFromConfigFileWDefault_int("parameters.dimensionZ",0);
    m.srcLocX = getParamFromConfigFileWDefault_int("parameters.sourceLocationX",0);
    m.srcLocY = getParamFromConfigFileWDefault_int("parameters.sourceLocationY", 0);
    m.PECScattFlag = getParamFromConfigFileWDefault_int("parameters.PECScattFlag", 0);
    m.PECScattLocX = getParamFromConfigFileWDefault_int("parameters.PECScattLocationX", 0);
    m.PECScattLocY = getParamFromConfigFileWDefault_int("parameters.PECScattLocationY", 0);
    m.PECScattDimX = getParamFromConfigFileWDefault_int("parameters.PECScattDimensionX", 0);
    m.PECScattDimY = getParamFromConfigFileWDefault_int("parameters.PECScattDimensionY", 0);
    m.Wavelength = getParamFromConfigFileWDefault_double("parameters.Wacelength", 0);
    m.PMLthickness = getParamFromConfigFileWDefault_int("parameters.PMLthickness", 0);
    m.dx = getParamFromConfigFileWDefault_double("parameters.dx", 0);
    m.dt = getParamFromConfigFileWDefault_double("parameters.dt", 0);
    m.k_x_max = getParamFromConfigFileWDefault_double("parameters.k_x_max", 0);
    m.k_y_max = getParamFromConfigFileWDefault_double("parameters.k_y_max", 0);
    m.a_x_max = getParamFromConfigFileWDefault_double("parameters.a_x_max", 0);
    m.a_y_max = getParamFromConfigFileWDefault_double("parameters.a_y_max", 0);
    m.m_a = getParamFromConfigFileWDefault_double("parameters.m_a", 0);
    m.m_chi = getParamFromConfigFileWDefault_double("parameters.m_chi", 0);
    
    printf("dimX = %d \n", m.dimX);
    printf("dimY = %d \n", m.dimY);
    printf("srcLocX = %d \n", m.srcLocX);
    printf("srcLocY = %d \n", m.srcLocY);
    printf("PECScattFlag = %d \n", m.PECScattFlag);
    printf("PECScattLocX = %d \n", m.PECScattLocX);
    printf("PECScattLocY = %d \n", m.PECScattLocY);
    printf("PECScattDimX = %d \n", m.PECScattDimX);
    printf("PECScattDimY = %d \n", m.PECScattDimY);
    printf("PMLthickness = %f \n", m.Wavelength);
    printf("PMLthickness = %d \n", m.PMLthickness);
    printf("dx = %f \n", m.dx);
    printf("dt = %f \n", m.dt);
    printf("k_x_max = %f \n", m.k_x_max);
    printf("k_y_max = %f \n", m.k_y_max);
    printf("a_x_max = %f \n", m.a_x_max);
    printf("a_y_max = %f \n", m.a_y_max);
    printf("m_a = %f \n", m.m_a);
    printf("m_chi = %f \n", m.m_chi);
    
    /*************   End of adding *************/
    
    
    
    
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
