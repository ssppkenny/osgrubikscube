#ifndef MYKEYBOARDHANDLER_H
#define MYKEYBOARDHANDLER_H
#include <osg/MatrixTransform>
#include <osg/ref_ptr>
#include <iostream>
#include <osg/Referenced>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgUtil/SmoothingVisitor>
#include <osg/LightSource>
#include <vector>


class myKeyboardEventHandler : public osgGA::GUIEventHandler
{
  public:
   osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3];
   myKeyboardEventHandler(osg::ref_ptr<osg::MatrixTransform> t[3][3][3]); 
   virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);
   virtual void accept(osgGA::GUIEventHandlerVisitor& v);
   void rotateLeftX(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]); 
   void rotateRightX(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]); 
   void rotateCWX(osg::ref_ptr<osg::MatrixTransform> transform);
   void rotateFrontY(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]);
   void rotateRoofZ(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]);
   void rotateBottomZ(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]);
   void rotateCWZ(osg::ref_ptr<osg::MatrixTransform> transform);
   void rotateCCWY(osg::ref_ptr<osg::MatrixTransform> transform);
   void rotateBackY(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]);
};
#endif

