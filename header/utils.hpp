//
//  mat.hpp
//  fdtd
//
//  Created by 曾舟 on 3/2/18.
//

#ifndef utils_h
#define utils_h

#include <vector>
#include <algorithm>

#define right_odd(x) ((x) / 2 * 2 + 1)
#define right_even(x) ((x + 1) / 2 * 2)

#define eta 376.73
#define e0 8.85418782e-12
#define u0 1.25663706e-6

typedef std::vector<int> rvec;

enum field_type {Ex, Ey, Ez, Hx, Hy, Hz};
enum curl_type {curlH, curlE};
enum E_and_H {E, H};

#define CREATE_FIELD_TYPE(type, Fx, Fy, Fz) \
    field_type Fx, Fy, Fz;          \
    if (type == curlE) {            \
        Fx = Hx; Fy = Hy; Fz = Hz; \
    }                               \
    else {                          \
        Fx = Ex; Fy = Ey; Fz = Ez; \
    }                               \


namespace utils {
    struct component {
        int multx, multy, multz;
        int x, y, z;
        int sx, sy, sz;
        int ex, ey, ez;
        int tx, ty, tz;
        int idx;
        
        component(rvec start, rvec end, rvec dim) {
            multx = dim[1] * dim[2];
            multy = dim[2];
            multz = 1;
            
            sx = start[0];
            sy = start[1];
            sz = start[2];
            
            ex = end[0];
            ey = end[1];
            ez = end[2];
        }
        
        void update() {
            idx = x * multx + y * multy + z * multz;
        }
        
        void loop_component(field_type type) {
            if (type == Ex || type == Ey || type == Ez) {
                tx = right_even(sx);
                ty = right_even(sy);
                tz = right_even(sz);
            } else {
                tx = right_odd(sx);
                ty = right_odd(sy);
                tz = right_odd(sz);
            }
            
            switch(type) {
                case Ex: tx = right_odd(sx);break;
                case Ey: ty = right_odd(sy);break;
                case Ez: tz = right_odd(sz);break;
                case Hx: tx = right_even(sx);break;
                case Hy: ty = right_even(sy);break;
                case Hz: tz = right_even(sz);break;
            }
            
            x = tx;
            y = ty;
            z = tz;
            update();
        }
        
        void increment() {
            x += 2;
            if (x > ex) {
                x = tx;
                y += 2;
                if (y > ey) {
                    y = ty;
                    z += 2;
                }
            }
            update();
        }
        
        bool end() {
            return z > ez;
        }
    };
    
    
    
    template<typename T>
    class Cube {
    private:
        int dimx, dimy, dimz;
        int multx, multy, multz;
        std :: vector<T> data;

    public:
        void zeros(int x, int y, int z) {
            resize(x, y, z);
            std :: fill(data.begin(), data.end(), 0);
        }

        void ones(int x, int y, int z) {
            resize(x, y, z);
            std :: fill(data.begin(), data.end(), 1);
        }

        void resize(int x, int y,int z) {
            dimx = x;
            dimy = y;
            dimz = z;
            data.resize(x * y * z);
            multx = y * z;
            multy = z;
            multz = 1;
        }

        T& operator()(int x, int y, int z) {
            return data[x * multx + y * multy + z];
        }
        
        T& operator()(int x) {
            return data[x];
        }

        T diffX(int x) {
            return data[x + multx] - data[x - multx];
        }

        T diffY(int x) {
            return data[x + multy] - data[x - multy];
        }

        T diffZ(int x) {
            return data[x + 1] - data[x - 1];
        }
    };

    template<typename T>
    class Col {
    private:
        int dimx;
        std :: vector<T> data;

    public:
        void zeros(int x) {
            dimx = x;
            data.resize(x);
            std :: fill(data.begin(), data.end(), 0);
        }

        void ones(int x) {
            dimx = x;
            data.resize(x);
            std :: fill(data.begin(), data.end(), 1);
        }

        T& operator()(int x) {
            return data[x];
        }
    };
}


#endif /* utils_h */
