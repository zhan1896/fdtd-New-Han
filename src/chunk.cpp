

#include "grid.hpp"

using namespace std;

chunk :: chunk(rvec _start, rvec _end, grid *_theGrid):start(_start), end(_end), theGrid(_theGrid){
    u_inf = e_inf = 1;
    itr = new utils :: component(start, end, rvec({theGrid->n * 2 + 1, theGrid->m * 2 + 1, theGrid->p * 2 + 1}));
    cout << "Starting point " << start[0] << " " << start[1] << " " << start[2] << endl;
    cout << "Ending Point " << end[0] << " " << end[1] << " " << end[2] << endl;
}

void chunk :: updateCurl(curl_type type) {
    CREATE_FIELD_TYPE(type, Fx, Fy, Fz);
    for (itr->loop_component(Fx); !itr->end(); itr->increment()) {
        theGrid->Curl(itr->idx) = theGrid->EH.diffY(itr->idx) / theGrid->delta / theGrid->k_y(itr->y)
        -theGrid->EH.diffZ(itr->idx) / theGrid->delta / theGrid->k_z(itr->z);
    }
    
    for (itr->loop_component(Fy); !itr->end(); itr->increment()) {
        theGrid->Curl(itr->idx) = theGrid->EH.diffZ(itr->idx) / theGrid->delta / theGrid->k_z(itr->z)
        -theGrid->EH.diffX(itr->idx) / theGrid->delta / theGrid->k_x(itr->x);
    }
    
    for (itr->loop_component(Fz); !itr->end(); itr->increment()) {
        theGrid->Curl(itr->idx) = theGrid->EH.diffX(itr->idx) / theGrid->delta / theGrid->k_x(itr->x)
        -theGrid->EH.diffY(itr->idx) / theGrid->delta / theGrid->k_y(itr->y);
    }
}

void chunk :: updateE() {
    for (itr->loop_component(Ex); !itr->end(); itr->increment()) {
        theGrid->EH(itr->idx) += theGrid->dt * theGrid->Curl(itr->idx) / (e0 * e_inf);
    }
    
    for (itr->loop_component(Ey); !itr->end(); itr->increment()) {
        theGrid->EH(itr->idx) += theGrid->dt * theGrid->Curl(itr->idx) / (e0 * e_inf);
    }
    
    for (itr->loop_component(Ez); !itr->end(); itr->increment()) {
        theGrid->EH(itr->idx) += theGrid->dt * theGrid->Curl(itr->idx) / (e0 * e_inf);
    }
}

void chunk :: updateH() {
    for (itr->loop_component(Hx); !itr->end(); itr->increment()) {
        theGrid->EH(itr->idx) -= theGrid->dt * theGrid->Curl(itr->idx) / (u0 * u_inf);
    }
    
    for (itr->loop_component(Hy); !itr->end(); itr->increment()) {
        theGrid->EH(itr->idx) -= theGrid->dt * theGrid->Curl(itr->idx) / (u0 * u_inf);
    }
    
    for (itr->loop_component(Hz); !itr->end(); itr->increment()) {
        theGrid->EH(itr->idx) -= theGrid->dt * theGrid->Curl(itr->idx) / (u0 * u_inf);
    }
}
