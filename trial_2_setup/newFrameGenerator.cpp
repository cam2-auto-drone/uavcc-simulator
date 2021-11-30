#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>
#include <cmath>


class newFrameGenerator{
  public:
    newFrameGenerator(){

    }

    void forwardFrameKeyframeGenerator(double* currentLocation, double distForward, gazebo::common::PoseAnimationPtr * anim, double frameTime){
      createForwardFrameYaw_Overwrite(currentLocation, distForward);
      gazebo::common::PoseKeyFrame *key = (*anim)->CreateKeyFrame(frameTime);
      key->Translation(ignition::math::Vector3d(currentLocation[0], currentLocation[1], currentLocation[2]));
      key->Rotation(ignition::math::Quaterniond(currentLocation[3], currentLocation[4], currentLocation[5]));
    }

    


    double * createForwardFrameX(double* currentLocation, double distForward){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }

      newLocation[0] =  newLocation[0] + distForward;

      return newLocation;
    }

    void createForwardFrameX_Overwrite(double* currentLocation, double distForward){
      currentLocation[0] =  currentLocation[0] + distForward;

    }

    double * createForwardFrameY(double* currentLocation, double distForward){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }

      newLocation[1] =  newLocation[1] + distForward;

      return newLocation;
    }

    void createForwardFrameY_Overwrite(double* currentLocation, double distForward){
      

      currentLocation[1] =  currentLocation[1] + distForward;
      
    }
    void printLocationArr(double* currentLocation){
      for(int i = 0; i < 6; i++){
        std::cout<<currentLocation[i]<<", ";
      }
      std::cout<<std::endl;
    }
    double * createForwardFrameYaw(double* currentLocation, double distForward){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }

      //double gammaShift = newLocation[5] + M_PI/2;
      newLocation[0] =  newLocation[0] + (distForward*cos(newLocation[5]));
      newLocation[1] =  newLocation[1] + (distForward*sin(newLocation[5]));


      return newLocation;
    }

    void createForwardFrameYaw_Overwrite(double* currentLocation, double distForward){
      currentLocation[0] =  currentLocation[0] + (distForward*cos(currentLocation[5]));
      currentLocation[1] =  currentLocation[1] + (distForward*sin(currentLocation[5]));
    }

    double * createNewOrientationFrame(double* currentLocation, double newOrientation){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }

      //double gammaShift = newLocation[5] + M_PI/2;
      newLocation[5] = newOrientation;


      return newLocation;
    }

    void createNewOrientationFrame_Overwrite(double* currentLocation, double newOrientation){
      //double gammaShift = newLocation[5] + M_PI/2;
      currentLocation[5] = newOrientation;
    }

    double ** rightRadiusTurn(double* currentLocation, double radius){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }
      
      //Get new point at center of turn
      newLocation[5] = newLocation[5] - M_PI/2;
      //double gammaShift = newLocation[5] + M_PI/2;
      double * radiusCenter = createForwardFrameYaw(newLocation, radius);
      radiusCenter[5] = radiusCenter[5] + M_PI/2;
      
      radiusCenter[5] = radiusCenter[5] + M_PI/4;
      double * frame0 = createForwardFrameYaw(radiusCenter, radius);
      frame0[5] = frame0[5] - M_PI/2;

      radiusCenter[5] = radiusCenter[5] - M_PI/4;
      double * frame1 = createForwardFrameYaw(radiusCenter, radius);
      frame1[5] = frame1[5] - M_PI/2;



      double ** turnFrames = new double*[6];
      turnFrames[0] = frame0;
      turnFrames[1] = frame1;
      return turnFrames;
    }

    double ** leftRadiusTurn(double* currentLocation, double radius){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }
      
      //Get new point at center of turn
      newLocation[5] = newLocation[5] + M_PI/2;
      //double gammaShift = newLocation[5] + M_PI/2;
      double * radiusCenter = createForwardFrameYaw(newLocation, radius);
      radiusCenter[5] = radiusCenter[5] - M_PI/2;
      
      radiusCenter[5] = radiusCenter[5] - M_PI/4;
      double * frame0 = createForwardFrameYaw(radiusCenter, radius);
      frame0[5] = frame0[5] + M_PI/2;


      radiusCenter[5] = radiusCenter[5] + M_PI/4;
      double * frame1 = createForwardFrameYaw(radiusCenter, radius);
      frame1[5] = frame1[5] + M_PI/2;



      double ** turnFrames = new double*[6];
      turnFrames[0] = frame0;
      turnFrames[1] = frame1;
      return turnFrames;
    }

    double * leftRadiusTurnOnePoint(double* currentLocation, double radius){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }
      
      //Get new point at center of turn
      double * newLocation0 = createForwardFrameYaw(currentLocation, radius);
      newLocation0[5] = newLocation0[5] + M_PI/2;
      return createForwardFrameYaw(newLocation0, radius);

    }

    double * rightRadiusTurnOnePoint(double* currentLocation, double radius){
      double * newLocation = new double[6];

      //Copy current location into new location
      for(int i = 0; i < 6; i++){
        newLocation[i] = currentLocation[i];
      }
      
      //Get new point at center of turn
      double * newLocation0 = createForwardFrameYaw(currentLocation, radius);
      newLocation0[5] = newLocation0[5] - M_PI/2;
      return createForwardFrameYaw(newLocation0, radius);

    }
};