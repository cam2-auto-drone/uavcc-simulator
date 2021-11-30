/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>
#include "newFrameGenerator.cpp"
namespace gazebo
{
  class AnimatedBox : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 10 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("test", 10, true));

        gazebo::common::PoseKeyFrame *key;
        
        newFrameGenerator* nfg1 = new newFrameGenerator();
        // set starting location of the box
        double currentLocation[6] = {0, 0, 0.05, 0, 0, 0};
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(currentLocation[0], currentLocation[1], currentLocation[2]));
        key->Rotation(ignition::math::Quaterniond(currentLocation[3], currentLocation[4], currentLocation[5]));

        nfg1->createForwardFrameYaw_Overwrite(currentLocation, 5);
        key = anim->CreateKeyFrame(5);
        key->Translation(ignition::math::Vector3d(currentLocation[0], currentLocation[1], currentLocation[2]));
        key->Rotation(ignition::math::Quaterniond(currentLocation[3], currentLocation[4], currentLocation[5]));

        double ** rightTurnFrames_0 = nfg1->rightRadiusTurn(currentLocation, 5);

        key = anim->CreateKeyFrame(7.5);
        key->Translation(ignition::math::Vector3d(rightTurnFrames_0[0][0], rightTurnFrames_0[0][1], rightTurnFrames_0[0][2]));
        key->Rotation(ignition::math::Quaterniond(rightTurnFrames_0[0][3], rightTurnFrames_0[0][4], rightTurnFrames_0[0][5]));

        key = anim->CreateKeyFrame(10);
        key->Translation(ignition::math::Vector3d(rightTurnFrames_0[1][0], rightTurnFrames_0[1][1], rightTurnFrames_0[1][2]));
        key->Rotation(ignition::math::Quaterniond(rightTurnFrames_0[1][3], rightTurnFrames_0[1][4], rightTurnFrames_0[1][5]));

  //       



        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedBox)
}
