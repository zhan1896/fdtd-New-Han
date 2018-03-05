//
//  params.cpp
//  fdtd
//
//  Created by Han Zhang on 3/4/18.
//

#include <stdio.h>
#include <cmath>
#include "params.hpp"
#include "lcfg_static.h"
#include "config.h"
#include "grid.hpp"

using namespace std;
testconfig readParameters(char* filename){
    
    char filenamePrefix[1000], configFilename[1000];
    
    strcpy(configFilename, filename);  //args is the address of the config file
    //char configFilename[]="./configfile.cfg";
    printf("configFilename = %s \n",configFilename);
    // load the entire config file into memory
    parseConfigFile(configFilename); //in config.c  analyze config file, check if status is good
    if (FILE *file = fopen(configFilename, "r")){ // check if the config file exists
        fclose(file);}
    else
    { printf("config file not exist");}
    
    testconfig m;
    /*get parameters from the config file*/
    m.timelength = getParamFromConfigFileWDefault_int("parameters.timelength",0); // simulation time length, int
    m.dimX = getParamFromConfigFileWDefault_int("parameters.dimensionX",0); // domain dimension X, int
    m.dimY = getParamFromConfigFileWDefault_int("parameters.dimensionY",0);// domain dimension Y, int
    m.dimZ = getParamFromConfigFileWDefault_int("parameters.dimensionZ",0);// domain dimension Z, int, not used
    m.srcLocX = getParamFromConfigFileWDefault_int("parameters.sourceLocationX",0);//source location X, int
    m.srcLocY = getParamFromConfigFileWDefault_int("parameters.sourceLocationY", 0);//source location Y, int
    m.PECScattFlag = getParamFromConfigFileWDefault_int("parameters.PECScattFlag", 0);//PEC Scattering Flag; 0: without PEC cylinder; 1: with PEC cylinder, int
    m.PECScattLocX = getParamFromConfigFileWDefault_int("parameters.PECScattLocationX", 0);//PEC cylinder location X, int
    m.PECScattLocY = getParamFromConfigFileWDefault_int("parameters.PECScattLocationY", 0);//PEC cylinder location Y, int
    m.PECScattDimX = getParamFromConfigFileWDefault_int("parameters.PECScattDimensionX", 0);//PEC cylinder dimension X, int
    m.PECScattDimY = getParamFromConfigFileWDefault_int("parameters.PECScattDimensionY", 0);//PEC cylinder dimension Y, int
    m.Wavelength = getParamFromConfigFileWDefault_double("parameters.Wacelength", 0);//EM wavelength, double
    m.PMLthickness = getParamFromConfigFileWDefault_int("parameters.PMLthickness", 0);//PML thickness, double
    m.dx = getParamFromConfigFileWDefault_double("parameters.dx", 0);//step size in length, double
    m.dt = getParamFromConfigFileWDefault_double("parameters.dt", 0);//step size in time, double
    m.k_x_max = getParamFromConfigFileWDefault_double("parameters.k_x_max", 0);//double
    m.k_y_max = getParamFromConfigFileWDefault_double("parameters.k_y_max", 0);//double
    m.a_x_max = getParamFromConfigFileWDefault_double("parameters.a_x_max", 0);//double
    m.a_y_max = getParamFromConfigFileWDefault_double("parameters.a_y_max", 0);//double
    m.m_a = getParamFromConfigFileWDefault_double("parameters.m_a", 0);//double
    m.m_chi = getParamFromConfigFileWDefault_double("parameters.m_chi", 0);//double
    
    
    /*print the obtained parameters to check*/
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
    
    return m;
}
