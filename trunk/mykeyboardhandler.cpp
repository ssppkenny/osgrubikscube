#include "mykeyboardhandler.hpp"

     myKeyboardEventHandler::myKeyboardEventHandler(osg::ref_ptr<osg::MatrixTransform> t[3][3][3])
{ 
     for (int i = 0; i<3; i++)
    {
      for (int j = 0; j<3; j++)
      {
         for (int k = 0; k<3; k++)
     {
       transforms[i][j][k] = t[i][j][k];
     }
      }
    }

};  
     bool myKeyboardEventHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
     { 
       switch (ea.getEventType())
       {
         case (osgGA::GUIEventAdapter::KEYDOWN):
         {

       switch(ea.getKey())
        {
         case 'b':
           rotateBackY(transforms);
           return false;
           break;
         case 'f':
           rotateFrontY(transforms);
           return false;
           break;
         case 't':
           rotateRoofZ(transforms);
           return false;
           break;
          case 'u':
           rotateBottomZ(transforms);
           return false;
           break;
         case 'l':
           rotateLeftX(transforms);
           return false;
           break;
          case 'r':
           rotateRightX(transforms);
           return false;
           break;

         default:
           return false;

       }
       default:
       return false;
     }
   }};
   void myKeyboardEventHandler::accept(osgGA::GUIEventHandlerVisitor& v)   { v.visit(*this); };

   void myKeyboardEventHandler::rotateLeftX(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
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
  };


  void myKeyboardEventHandler::rotateRightX(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
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
};

  void myKeyboardEventHandler::rotateCWX(osg::ref_ptr<osg::MatrixTransform> transform)
  {
    osg::Matrix rotationMatrix;
    float c = 1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(1.0f, 0.0f, 0.0f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);  
};

  void myKeyboardEventHandler::rotateFrontY(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
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
 };

  void myKeyboardEventHandler::rotateRoofZ(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
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
};

  void myKeyboardEventHandler::rotateBottomZ(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
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

};


  void myKeyboardEventHandler::rotateCWZ(osg::ref_ptr<osg::MatrixTransform> transform)
  {

    osg::Matrix rotationMatrix;
    float c = 1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(0.0f, 0.0f, 0.1f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);
};

  void myKeyboardEventHandler::rotateCCWY(osg::ref_ptr<osg::MatrixTransform> transform)
  {

    osg::Matrix rotationMatrix;
    float c = -1.5707963f;
    rotationMatrix.makeRotate(c, osg::Vec3f(0.0f, 0.1f, 0.0f) );
    osg::Matrix matrix1 = transform->getMatrix();
    matrix1 = matrix1 * rotationMatrix;
    transform->setMatrix(matrix1);

  
  };


  void myKeyboardEventHandler::rotateBackY(osg::ref_ptr<osg::MatrixTransform> transforms[3][3][3]) 
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
 };



