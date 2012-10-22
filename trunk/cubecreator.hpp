#ifndef CUBECREATOR_H
#define CUBECREATOR_H
#include <windows.h>
#include <osg/MatrixTransform>
#include <osg/ref_ptr>
#include <osg/Referenced>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>


class CubeCreator : public osg::Referenced
{  
   public:
     osg::ref_ptr<osg::MatrixTransform> setTransform(osg::ref_ptr<osg::Geometry> geom , osg::ref_ptr<osg::Geode> geode, float a,  float x, float y, float z);
     osg::ref_ptr<osg::MatrixTransform> createCube(osg::ref_ptr<osg::Geode> geode, float a, float x, float y, float z);
	  osg::ref_ptr<osg::MatrixTransform> createBigCube(osg::ref_ptr<osg::Geode> geode, float a, float x, float y, float z);
  
};
#endif






