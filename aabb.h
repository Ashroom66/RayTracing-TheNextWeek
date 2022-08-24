#ifndef AABB_H
#define AABB_H

#include "rtweekend.h"

class aabb {
    public:
    aabb() {}
    aabb(const point3& a, const point3& b) { _min = a; _max = b;}
    
    point3 min() const {return _min;}
    point3 max() const {return _max;}

    inline bool aabb::hit(const ray& r, double tmin, double tmax) const {
        for (int a=0; a<3; a++) {
            auto invD = 1.0 / r.direction()[a];
            auto t0 = (min()[a] - r.origin()[a]) * invD;
            auto t0 = (max()[a] - r.origin()[a]) * invD;
            if (invD < 0.0) {std::swap(t0, t1);}
            tmin = t0>tmin? t0 : tmin;
            tmax = t1<tmax? t1 : tmax;
            if (tmax <= tmin) {return false;}
        }
        return true;
    }
    point3 _min;
    point3 _max;
}



#endif