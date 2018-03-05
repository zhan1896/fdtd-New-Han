//
//  tmz.hpp
//  fdtd
//
//  Created by 曾舟 on 2/24/18.
//

#ifndef grid_h
#define grid_h

//#include <armadillo>
#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include "utils.hpp"

class grid;
class chunk;

struct testconfig {
    int timelength;
    int dimX, dimY, dimZ;
    int srcLocX, srcLocY; //index 1
    int PECScattFlag;
    int PECScattLocX, PECScattLocY;
    int PECScattDimX, PECScattDimY;

    double Wavelength;
    
    int PMLthickness;
    double dx;
    double dt;
    double k_x_max;
    double k_y_max;
    double a_x_max;
    double a_y_max;
    double m_a;
    double m_chi;

};

struct configuration {
    //dimension
    int x;
    int y;
    int z;
    int PML;
    double dx;
    double dt;
    //PML parameters
    double k_x_max;
    double k_y_max;
    double a_x_max;
    double a_y_max;
    double m_a;
    double m_chi;
    //costumize parameters

};

class chunk {
private:
    double e_inf, u_inf;

public:
    rvec start, end;
    grid *theGrid;
    utils :: component *itr;
    chunk(std :: vector<int>, std :: vector<int>, grid *);
    void updateCurl(curl_type);
    void updateE();
    void updateH();
};

class grid {
private:
    // dimensions
    int n, m, p;
    double delta, dt, courant;
    utils :: component *itr;

    //general fields
    utils :: Cube<double> EH;
    utils :: Cube<double> Curl;

    //PML parameters
    utils :: Col<double> k_x;
    utils :: Col<double> k_y;
    utils :: Col<double> k_z;

    utils :: Col<double> b_x;
    utils :: Col<double> b_y;
    utils :: Col<double> b_z;

    utils :: Col<double> c_x;
    utils :: Col<double> c_y;
    utils :: Col<double> c_z;

    //PML auxilliary fields
    utils :: Cube<double> Psi_pos;
    utils :: Cube<double> Psi_neg;

    friend class chunk;
    //IO members;
    std :: fstream fin, fo;
    std :: fstream fdebug;

    testconfig *config;

public:
    grid(configuration&);

    std :: vector<chunk> chunks;
    void update(double);
    void snapshotInit(int);
    void snapshot();

    void Jsource(double);
    void PMLupdate(curl_type);
    void hardE(double);
};



#endif /* grid_h */
