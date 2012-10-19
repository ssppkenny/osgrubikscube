#include "cubecreator.hpp"

osg::ref_ptr<osg::MatrixTransform> CubeCreator::setTransform(osg::ref_ptr<osg::Geometry> geom , osg::ref_ptr<osg::Geode> geode, float a,  float x, float y, float z)
{
    geode->addDrawable(geom.get());
    osg::ref_ptr<osg::MatrixTransform> transform = new osg::MatrixTransform();
    transform->setMatrix(osg::Matrix::rotate(a, x, y ,z));
    transform->addChild(geode.get());
    return transform;
};


osg::ref_ptr<osg::MatrixTransform> CubeCreator::createCube(osg::ref_ptr<osg::Geode> geode, float a, float x, float y, float z) {

 osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

  x = x - 1.5f;
  y = y -1.5f;
  z = z - 1.5f;

     vertices->push_back( osg::Vec3(x + 0.0f, y + 0.0f, z + 0.0f) );
     vertices->push_back( osg::Vec3(x + 1.0f, y + 0.0f, z + 0.0f) );
     vertices->push_back( osg::Vec3(x + 1.0f, y + 0.0f, z + 1.0f) );
     vertices->push_back( osg::Vec3(x + 0.0f, y + 0.0f, z + 1.0f) );

    vertices->push_back(osg::Vec3(x + 0.0f, y + 1.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 1.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 1.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 0.0f, y + 1.0f, z + 1.0f));
     
    vertices->push_back(osg::Vec3(x + 0.0f, y + 0.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 0.0f, y + 1.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 1.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 0.0f, z + 0.0f));
    
    vertices->push_back(osg::Vec3(x + 0.0f, y + 0.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 0.0f, y + 1.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 1.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 0.0f, z + 1.0f));
    
    vertices->push_back(osg::Vec3(x + 0.0f, y + 0.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 0.0f, y + 0.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 0.0f, y + 1.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 0.0f, y + 1.0f, z + 0.0f));
    
    vertices->push_back(osg::Vec3(x + 1.0f, y + 0.0f, z + 0.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 0.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 1.0f, z + 1.0f));
    vertices->push_back(osg::Vec3(x + 1.0f, y + 1.0f, z + 0.0f));
    
     osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
     normals->push_back( osg::Vec3(0.0f,-1.0f, 0.0f) );

     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
     colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
     
     colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );

     colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );
     colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );
     colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );
     colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );

     colors->push_back( osg::Vec4(1.0f, 0.5f, 0.2f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 0.5f, 0.2f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 0.5f, 0.2f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 0.5f, 0.2f, 1.0f) );
     
     colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );
   
     colors->push_back( osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f) );
     colors->push_back( osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f) );
    
    osg::ref_ptr<osg::Geometry> quad = new osg::Geometry;
    quad->setVertexArray( vertices.get() );
    quad->setNormalArray( normals.get() );
    quad->setNormalBinding( osg::Geometry::BIND_OVERALL );
    quad->setColorArray( colors.get() );
    quad->setColorBinding( osg::Geometry::BIND_PER_VERTEX );

    quad->addPrimitiveSet( new osg::DrawArrays(GL_QUADS, 0, 24) );


    osg::ref_ptr<osg::MatrixTransform> transform = setTransform(quad, geode, a, 0.0f, 0.0f, 1.0f);

    return transform;



};




