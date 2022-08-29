#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <cstdlib>

// using
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// 定数
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//  ユーティリティ関数
inline double degrees_to_radius(double degrees) {
    return degrees * pi / 180;
}
inline double random_double() {
    // [0,1)の実数乱数を生成
    return rand() / (RAND_MAX + 1.0);
}
inline double random_double(double min, double max) {
    // [min, max)の実数乱数を生成
    return min + (max-min)*random_double();
}
inline int random_int(int min, int max) {
    // (min, min+1, ..., max)から整数をランダムに返す
    return min+rand() % (max-min+1);
}
inline double clamp(double x, double min, double max) {
    if (x<min) {return min;}
    if (x>max) {return max;}
    return x;
}

// 共通ヘッダー
#include "ray.h"
#include "vec3.h"

#endif