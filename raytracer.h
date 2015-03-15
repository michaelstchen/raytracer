#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "light.h"
#include <vector>
#include "geomobj.h"
#include "property.h"
#include "ray.h"

using namespace std;

class World {
 private:
    vector<Light*> lights;
    vector<Shape*> shapes;
 public:
    World() {}
    void addLight(Light* l);
    int numOfLights();
    vector<Light*>::iterator lightIter();
    vector<Light*>::iterator lightIterEnd();

    void addShape(Shape* s);
    int numOfShapes();
    vector<Shape*>::iterator shapeIter();
    vector<Shape*>::iterator shapeIterEnd();
};

class ImgPlane {
 private:
    Point* ll; Point* lr; Point* ul; Point* ur;
    /* in number of pixels */
    int height; int width;
    vector<Color*> pixels;
 public:
    ImgPlane(Point* p0, Point* p1, Point* p2, Point* p3, int h, int w);
    /* in number of pixels */
    int getHeight();
    int getWidth();
    /* converts pixel coordinates to world coordinates. (0,0) represents
       the lower left pixel. 0 <= i < w. 0 <= j < h. */
    Point* getPixelPos(int i, int j);
    Color* getPixelColor(int i, int j);
    void setPixelColor(int i, int j, Color* c);
};

class Scene {
 public:
    Scene(World* w, ImgPlane* v, Point* c);
    World* world;
    ImgPlane* view;
    Point* camera;
    Color* traceEye(EyeRay* e);
    //Color* traceShadow(ShadowRay* s);
    void render();
};

#endif
