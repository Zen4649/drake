#include "drake/systems/plants/rigid_body_loop.h"

RigidBodyLoop::RigidBodyLoop(std::shared_ptr<RigidBodyFrame> frameA,
                             std::shared_ptr<RigidBodyFrame> frameB,
                             const Eigen::Vector3d& axis)
    : frameA_(frameA), frameB_(frameB), axis_(axis) {}

std::ostream& operator<<(std::ostream& os, const RigidBodyLoop& obj) {
  os << "loop connects pt "
     << obj.frameA_->transform_to_body.matrix().topRightCorner(3, 1).transpose()
     << " on " << obj.frameA_->body->get_name() << " to pt "
     << obj.frameB_->transform_to_body.matrix().topRightCorner(3, 1).transpose()
     << " on " << obj.frameB_->body->get_name() << std::endl;
  return os;
}
