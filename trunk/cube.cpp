#include "mykeyboardhandler.hpp"
#include "cubecreator.hpp"

using namespace std;


void initGeode(osg::ref_ptr<osg::Geode> geode[3][3][3])
{
  for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
      {
         for (int k=0; k<3; k++)
         {
           geode[i][j][k] = new osg::Geode();
         }
      }
    }

}

void initTransforms(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3], osg::ref_ptr<CubeCreator> cubeCreator, 
        osg::ref_ptr<osg::Group> root, osg::ref_ptr<osg::Geode> geode[3][3][3]) 
{
  
    float a = 0.0f;
    for (int i=0; i<3; i++)
    {
      for (int j=0; j<3; j++)
      {
         for (int k=0; k<3; k++)
         {
            transforms[i][j][k] = cubeCreator->createCube(geode[i][j][k], a, i,j,k);
         }
      }
    }
    for (int i=0; i<3; i++)
    {
      for (int j= 0; j<3; j++)
      {
         for (int k=0; k<3; k++)
         {
           root->addChild( transforms[i][j][k].get());
         }
      }
    }

}

void setLightSource(osg::ref_ptr<osg::Group> root)
{
    osg::ref_ptr<osg::LightSource> ls = new osg::LightSource();
    ls->getLight()->setPosition(osg::Vec4(5.0f,5.0f,5.0f,0.0f));
    ls->getLight()->setAmbient(osg::Vec4(1.2,1.2,1.2,1.2));
    ls->getLight()->setSpecular(osg::Vec4(1.2,1.2,1.2,1.2));
    ls->getLight()->setLinearAttenuation(1.0f);
    root->addChild(ls.get());

}

int main(int argc, char** argv)

{
    osg::ref_ptr<CubeCreator> cubeCreator = new CubeCreator();
    osg::ref_ptr<osg::Group> root = new osg::Group();
    
    osg::ref_ptr<osg::Geode> geode[3][3][3];
    initGeode(geode);
    osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3];
    initTransforms(transforms, cubeCreator, root, geode);
    setLightSource(root);

    osg::ref_ptr<myKeyboardEventHandler> handler = new myKeyboardEventHandler(transforms); 
   
    osgViewer::Viewer viewer;
    viewer.setUpViewInWindow(0,0,800,600);
    viewer.addEventHandler(handler);
    viewer.setSceneData(root.get());
    return viewer.run();

}
