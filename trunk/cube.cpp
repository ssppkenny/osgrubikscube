#include "mykeyboardhandler.hpp"

using namespace std;

osg::ref_ptr<osg::MatrixTransform> setTransform(osg::ref_ptr<osg::Geometry> geom , osg::ref_ptr<osg::Geode> geode, float a,  float x, float y, float z)
{
    geode->addDrawable(geom.get());
    osg::ref_ptr<osg::MatrixTransform> transform = new osg::MatrixTransform();
    transform->setMatrix(osg::Matrix::rotate(a, x, y ,z));
    transform->addChild(geode.get());
    return transform;
}


osg::ref_ptr<osg::MatrixTransform> createCube(osg::ref_ptr<osg::Geode> geode, float a, float x, float y, float z) {

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


}
void rotateCWY(osg::ref_ptr<osg::MatrixTransform> transform)
{

    osg::Matrix rotationMatrix;
    float c = 1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(0.0f, 0.1f, 0.0f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
}
void rotateCWZ(osg::ref_ptr<osg::MatrixTransform> transform)
{

    osg::Matrix rotationMatrix;
    float c = 1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(0.0f, 0.0f, 0.1f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
}
void rotateCWX(osg::ref_ptr<osg::MatrixTransform> transform)
{

    osg::Matrix rotationMatrix;
    float c = 1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(1.0f, 0.0f, 0.0f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
}

void rotateCCWY(osg::ref_ptr<osg::MatrixTransform> transform)
{

    osg::Matrix rotationMatrix;
    float c = -1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(0.0f, 0.1f, 0.0f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
}
void rotateCCWZ(osg::ref_ptr<osg::MatrixTransform> transform)
{

    osg::Matrix rotationMatrix;
    float c = -1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(0.0f, 0.0f, 0.1f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
}
void rotateCCWX(osg::ref_ptr<osg::MatrixTransform> transform)
{

    osg::Matrix rotationMatrix;
    float c = -1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(1.0f, 0.0f, 0.0f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
}

void rotateBottomZ(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
{
  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
      rotateCWZ(transforms[i][j][0]);
    }
  }
      
       osg::ref_ptr<osg::MatrixTransform> temp1 = transforms[0][0][0] ;
       transforms[0][0][0] = transforms[0][2][0];
       transforms[0][2][0] = transforms[2][2][0];
       transforms[2][2][0] = transforms[2][0][0];
       transforms[2][0][0] = temp1;

       temp1 = transforms[1][0][0];
       transforms[1][0][0] = transforms[0][1][0];
       transforms[0][1][0] = transforms[1][2][0];
       transforms[1][2][0] = transforms[2][1][0];
       transforms[2][1][0] = temp1;
}

void rotateLeftX(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
{
  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
      rotateCWX(transforms[2][i][j]);
    }
  }

       osg::ref_ptr<osg::MatrixTransform> temp1 = transforms[2][0][0] ;
       transforms[2][0][0] = transforms[2][0][2];
       transforms[2][0][2] = transforms[2][2][2];
       transforms[2][2][2] = transforms[2][2][0];
       transforms[2][2][0] = temp1;

       temp1 = transforms[2][1][0];
       transforms[2][1][0] = transforms[2][0][1];
       transforms[2][0][1] = transforms[2][1][2];
       transforms[2][1][2] = transforms[2][2][1];
       transforms[2][2][1] = temp1;

}

void rotateRightX(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
{
  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
      rotateCWX(transforms[0][i][j]);
    }
  }

       osg::ref_ptr<osg::MatrixTransform> temp1 = transforms[0][0][0] ;
       transforms[0][0][0] = transforms[0][0][2];
       transforms[0][0][2] = transforms[0][2][2];
       transforms[0][2][2] = transforms[0][2][0];
       transforms[0][2][0] = temp1;

       temp1 = transforms[0][1][0];
       transforms[0][1][0] = transforms[0][0][1];
       transforms[0][0][1] = transforms[0][1][2];
       transforms[0][1][2] = transforms[0][2][1];
       transforms[0][2][1] = temp1;

}


void rotateRoofZ(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
{
  for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
      rotateCWZ(transforms[i][j][2]);
    }
  }
       osg::ref_ptr<osg::MatrixTransform> temp1 = transforms[0][0][2] ;
       transforms[0][0][2] = transforms[0][2][2];
       transforms[0][2][2] = transforms[2][2][2];
       transforms[2][2][2] = transforms[2][0][2];
       transforms[2][0][2] = temp1;

       temp1 = transforms[1][0][2];
       transforms[1][0][2] = transforms[0][1][2];
       transforms[0][1][2] = transforms[1][2][2];
       transforms[1][2][2] = transforms[2][1][2];
       transforms[2][1][2] = temp1;
}

void rotateBackY(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
{
 
 for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
     rotateCCWY(transforms[i][0][j]);
    }
  }
       osg::ref_ptr<osg::MatrixTransform> temp1 = transforms[0][0][0] ;
       transforms[0][0][0] = transforms[0][0][2];
       transforms[0][0][2] = transforms[2][0][2];
       transforms[2][0][2] = transforms[2][0][0];
       transforms[2][0][0] = temp1;

       temp1 = transforms[1][0][0];
       transforms[1][0][0] = transforms[0][0][1];
       transforms[0][0][1] = transforms[1][0][2];
       transforms[1][0][2] = transforms[2][0][1];
       transforms[2][0][1] = temp1;
 }


void rotateFrontY(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
{
 
 for (int i = 0; i < 3; i++) 
  {
    for (int j = 0; j < 3; j++) 
    {
     rotateCCWY(transforms[i][2][j]);
    }
  }
       osg::ref_ptr<osg::MatrixTransform> temp1 = transforms[0][2][0] ;
       transforms[0][2][0] = transforms[0][2][2];
       transforms[0][2][2] = transforms[2][2][2];
       transforms[2][2][2] = transforms[2][2][0];
       transforms[2][2][0] = temp1;

       temp1 = transforms[1][2][0];
       transforms[1][2][0] = transforms[0][2][1];
       transforms[0][2][1] = transforms[1][2][2];
       transforms[1][2][2] = transforms[2][2][1];
       transforms[2][2][1] = temp1;
 }



int main(int argc, char** argv)

{

    osg::ref_ptr<osg::Group> root = new osg::Group();
    
    osg::ref_ptr<osg::Geode> geode[3][3][3];
    for (int i = 0; i<3; i++)
    {
      for (int j = 0; j<3; j++)
      {
         for (int k = 0; k<3; k++)
     {
       geode[i][j][k] = new osg::Geode();
     }
      }
    }

    float a = 0.0f;

    osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3];


    for (int i = 0; i<3; i++)
    {
      for (int j = 0; j<3; j++)
      {
         for (int k = 0; k<3; k++)
     {
       transforms[i][j][k] = createCube(geode[i][j][k], a, i,j,k);
     }
      }
    }

 
    for (int i = 0; i<3; i++)
    {
      for (int j = 0; j<3; j++)
      {
         for (int k = 0; k<3; k++)
     {
       root->addChild( transforms[i][j][k].get());
     }
      }
    }

    osg::ref_ptr<osg::LightSource> ls = new osg::LightSource();
    ls->getLight()->setPosition(osg::Vec4(5.0f,5.0f,5.0f,0.0f));
    ls->getLight()->setAmbient(osg::Vec4(1.2,1.2,1.2,1.2));
    ls->getLight()->setSpecular(osg::Vec4(1.2,1.2,1.2,1.2));
    ls->getLight()->setLinearAttenuation(1.0f);
    root->addChild(ls.get());

    osg::ref_ptr<myKeyboardEventHandler> handler = new myKeyboardEventHandler(transforms); 
   

    osgViewer::Viewer viewer;
    viewer.setUpViewInWindow(0,0,800,600);
    viewer.addEventHandler(handler);
    viewer.setSceneData(root.get());
    return viewer.run();

}
