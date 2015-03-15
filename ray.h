#ifndef RAY_H
#define RAY_H

#include "linalg.h"
#include <cstddef>

class Ray {
 public:
    Ray(Point* p, Vector* d);
    Point* p0;
    Vector* dir;
    float t_min; float t_max;
    Point* findPoint(float t);
};

class EyeRay : public Ray {
 public:
    EyeRay(Point* p, Vector* d);
};
/*
class ShadowRay: public Ray {
 public:
    ShadowRay(Point* p, Vector* d);
}
*/
#endif
