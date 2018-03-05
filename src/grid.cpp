//
//  tmz.cpp
//  fdtd
//
//  Created by 曾舟 on 2/24/18.
//

#include <stdio.h>
#include "grid.hpp"
#include <cmath>
#include <algorithm>

using namespace std;
void grid :: PMLupdate(curl_type type) {
    //update Ex at 1 0 0
    CREATE_FIELD_TYPE(type, Fx, Fy, Fz);
    
    for (itr->loop_component(Fx); !itr->end(); itr->increment()) {
        if (c_x(itr->x) == 0 && c_y(itr->y) == 0 && c_z(itr->z) == 0) continue;
        //partial y
        if (c_y(itr->y) != 0)
            Psi_pos(itr->idx) = b_y(itr->y) * Psi_pos(itr->idx) + c_y(itr->y) * EH.diffY(itr->idx) / delta;

        //partial z
        if (c_z(itr->z) != 0)
            Psi_neg(itr->idx) = b_z(itr->z) * Psi_neg(itr->idx) + c_z(itr->z) * EH.diffZ(itr->idx) / delta;

        Curl(itr->idx) += Psi_pos(itr->idx) - Psi_neg(itr->idx);
    }
    
    for (itr->loop_component(Fy); !itr->end(); itr->increment()) {
        if (c_x(itr->x) == 0 && c_y(itr->y) == 0 && c_z(itr->z) == 0) continue;

        //partial z
        if (c_z(itr->z) != 0)
            Psi_pos(itr->idx) = b_z(itr->z) * Psi_pos(itr->idx) + c_z(itr->z) * EH.diffZ(itr->idx) / delta;
        
        //partial x
        if (c_x(itr->x) != 0)
            Psi_neg(itr->idx) = b_x(itr->x) * Psi_neg(itr->idx) + c_x(itr->x) * EH.diffX(itr->idx) / delta;
        
        Curl(itr->idx) += Psi_pos(itr->idx) - Psi_neg(itr->idx);
    }
    
    for (itr->loop_component(Fz); !itr->end(); itr->increment()) {
        if (c_x(itr->x) == 0 && c_y(itr->y) == 0 && c_z(itr->z) == 0) continue;

        //partial x
        if (c_x(itr->x) != 0)
            Psi_pos(itr->idx) = b_x(itr->x) * Psi_pos(itr->idx) + c_x(itr->x) * EH.diffX(itr->idx) / delta;
        
        //partial y
        if (c_y(itr->y) != 0)
            Psi_neg(itr->idx) = b_y(itr->y) * Psi_neg(itr->idx) + c_y(itr->y) * EH.diffY(itr->idx) / delta;
        
        Curl(itr->idx) += Psi_pos(itr->idx) - Psi_neg(itr->idx);
    }
}

//for now it is simulating a TMz wave, updates happens at z = 1
grid :: grid(configuration &config) {
    n = config.x + config.PML * 2;
    m = config.y + config.PML * 2;
    p = 2;
    delta = config.dx;
    dt = config.dt;
    courant = 3.0e8 * dt / delta;
    
    itr = new utils :: component(rvec({1, 1, 1}), rvec({2 * n - 1, 2 * m - 1, 1}), rvec({2 * n + 1, 2 * m + 1, 2 * p + 1}));
    
    cout << "Courant Number is " << courant << endl;
    
    EH.zeros(n * 2 + 1, m * 2 + 1, p * 2 + 1);
    Curl.zeros(n * 2 + 1, m * 2 + 1, p * 2 + 1);
    
    k_x.ones(n * 2 + 1);
    k_y.ones(m * 2 + 1);
    k_z.ones(p * 2 + 1);
    
    b_x.ones(n * 2 + 1);
    b_y.ones(m * 2 + 1);
    b_z.ones(p * 2 + 1);
    
    c_x.zeros(n * 2 + 1);
    c_y.zeros(m * 2 + 1);
    c_z.zeros(p * 2 + 1);
    
    Psi_neg.zeros(n * 2 + 1, m * 2 + 1, p * 2 + 1);
    Psi_pos.zeros(n * 2 + 1, m * 2 + 1, p * 2 + 1);
    
    double sigma_max = 0.8 * (config.m_chi + 1) / (eta * delta);
    
    for (int i = 0; i <= n * 2; ++i) {
        double ratio;
        //left and right bnd
        if (i < config.PML * 2)
            ratio = (config.PML * 2 - i) / (2.0 * config.PML);
        else if (n * 2 - i < config.PML * 2)
            ratio = 1 - (n * 2 - i) / (2.0 * config.PML);
        else {
            continue;
        }

        double PML_sig_x = pow(ratio, config.m_chi) * sigma_max;
        k_x(i) = 1 + pow(ratio, config.m_chi) * (config.k_x_max - 1);
        double a_x = pow(1 - ratio, config.m_a) * config.a_x_max;

        b_x(i) = exp(-(PML_sig_x / k_x(i)  + a_x) * dt / e0);
        c_x(i) = PML_sig_x / (PML_sig_x * k_x(i) + k_x(i) * k_x(i) * a_x) * (b_x(i) - 1);
    }

    for (int i = 0; i <= m * 2; ++i) {
        double ratio;
        //top and bottom bnd
        if (i < config.PML * 2)
            ratio = (config.PML * 2 - i) / (2.0 * config.PML);
        else if (m * 2 - i < config.PML * 2)
            ratio = 1 - (m * 2 - i) / (2.0 * config.PML);
        else {
            continue;
        }

        double PML_sig_y = pow(ratio, config.m_chi) * sigma_max;
        k_y(i) = 1 + pow(ratio, config.m_chi) * (config.k_y_max - 1);
        double a_y = pow(1 - ratio, config.m_a) * config.a_y_max;

        b_y(i) = exp(-(PML_sig_y / k_y(i)  + a_y) * dt / e0);
        c_y(i) = PML_sig_y / (PML_sig_y * k_y(i) + k_y(i) * k_y(i) * a_y) * (b_y(i) - 1);
    }
    
    // the perimeter is PEC and is not included
    chunks.push_back(chunk(rvec({1, 1, 1}), rvec({2 * n - 1, 2 * m - 1, 1}), this));
}

void grid :: snapshotInit(int times) {
    int x, y;
    x = n + 1;
    y = m + 1;
    //debugging info

    int tmp = 2 * n + 1;
    fdebug.open("debug.bin", ios :: out | ios :: binary);
    fdebug.write((char*)&tmp, sizeof(int));
    fdebug.write((char*)&b_x(0), sizeof(double) * tmp);

    fdebug.write((char*)&tmp, sizeof(int));
    fdebug.write((char*)&b_y(0), sizeof(double) * tmp);

    fdebug.write((char*)&tmp, sizeof(int));
    fdebug.write((char*)&c_x(0), sizeof(double) * tmp);

    fdebug.write((char*)&tmp, sizeof(int));
    fdebug.write((char*)&c_y(0), sizeof(double) * tmp);

    //output info
    fo.open("output.bin", ios :: out | ios :: binary);
    fo.write((char*)&x, sizeof(int));
    fo.write((char*)&y, sizeof(int));
    fo.write((char*)&times, sizeof(int));
}

void grid :: snapshot() {
    for(int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)    {
        fo.write((char*)&EH(i * 2, j * 2, 1), sizeof(double));
    }
}

void grid :: update(double time) {
//    cout << "Update at time " << time << endl;
    for (auto i : chunks) {
        i.updateCurl(curlE);
    }
    PMLupdate(curlE);
    
    for (auto i : chunks) {
        i.updateH();
    }
    
    for (auto i : chunks) {
        i.updateCurl(curlH);
    }
    PMLupdate(curlH);
    Jsource(time + 0.5);
    
    for (auto i : chunks) {
        i.updateE();
    }
    hardE(time);
}

double ezInc(double courant, double time) {
    static double ppw = 2;
//
//    double arg = M_PI * ((courant * time) / ppw - 1.0);
//    arg = arg * arg;
//
//    return (1.0 - 2.0 * arg) * exp(-arg);
    
    return cos(time / ppw);
}

void grid :: hardE(double time) {
    for (int i = 40; i <= 60; ++i)
        for (int j = 40; j <= 60; ++j)
            EH(i, j, 1) = 0;
    //hard code Ez source
//    EH(right_even(n), right_even(m), 1) = ezInc(courant, time);
}

void grid :: Jsource(double time) {
    Curl(right_even(n), right_even(m), 1) -= ezInc(courant, time);
}
