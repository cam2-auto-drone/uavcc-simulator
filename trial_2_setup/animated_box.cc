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
              new gazebo::common::PoseAnimation("test", 50, true));

        gazebo::common::PoseKeyFrame *key;

        // set starting location of the box
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(0, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set waypoint location after 2 seconds
        key = anim->CreateKeyFrame(2.0);
        key->Translation(ignition::math::Vector3d(1, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));


        key = anim->CreateKeyFrame(4.0);
        key->Translation(ignition::math::Vector3d(1.5, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));


        key = anim->CreateKeyFrame(6.0);
        key->Translation(ignition::math::Vector3d(2, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));


        key = anim->CreateKeyFrame(8.0);
        key->Translation(ignition::math::Vector3d(2.33, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));
	
	key = anim->CreateKeyFrame(10.0);
        key->Translation(ignition::math::Vector3d(3, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

	key = anim->CreateKeyFrame(12.0);
        key->Translation(ignition::math::Vector3d(3.5, 0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(14.0);
        key->Translation(ignition::math::Vector3d(3.7, 0.5, 0.05));
        key->Rotation(ignition::math::Quaterniond(0.0, 0, 1.57));

	 key = anim->CreateKeyFrame(18.0);
        key->Translation(ignition::math::Vector3d(4, 4, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

	 key = anim->CreateKeyFrame(21.0);
        key->Translation(ignition::math::Vector3d(4, 8.5, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

	 key = anim->CreateKeyFrame(24.0);
        key->Translation(ignition::math::Vector3d(4, 9.0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));


	 key = anim->CreateKeyFrame(26.0);
        key->Translation(ignition::math::Vector3d(4, 10.4, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.57));

	 key = anim->CreateKeyFrame(28.0);
        key->Translation(ignition::math::Vector3d(3.6, 10.4, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

	 key = anim->CreateKeyFrame(30.0);
        key->Translation(ignition::math::Vector3d(2.0, 10.4, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

	 key = anim->CreateKeyFrame(36.0);
        key->Translation(ignition::math::Vector3d(-2.0, 10.4, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14));

	 key = anim->CreateKeyFrame(38.0);
        key->Translation(ignition::math::Vector3d(-3.7, 9.0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 4.71));

	 key = anim->CreateKeyFrame(40.0);
        key->Translation(ignition::math::Vector3d(-3.7, 5.0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 4.71));

	 key = anim->CreateKeyFrame(44.0);
        key->Translation(ignition::math::Vector3d(-3.7, 1.0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 4.71));

	 key = anim->CreateKeyFrame(48.0);
        key->Translation(ignition::math::Vector3d(-2.7,0.5 , 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 5.49));

	 key = anim->CreateKeyFrame(50.0);
        key->Translation(ignition::math::Vector3d(0, 0.0, 0.05));
        key->Rotation(ignition::math::Quaterniond(0, 0, 6.28));




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
