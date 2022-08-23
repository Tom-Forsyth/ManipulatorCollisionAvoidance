#pragma once

#include <Eigen/Dense>

// Robotics kinematics functions.
namespace Kinematics
{
    // Compute skew-symmetrix form of an axis.
    Eigen::Matrix3d skew(const Eigen::Vector3d& w);

    // Compute the rotation matrix from axis-angle representation.
    Eigen::Matrix3d AxisAngletoRot(const Eigen::Vector3d& axis, double angle);

    // Compute the adjoint matrix of a transformation matrix.
    Eigen::Matrix<double, 6, 6> adjoint(const Eigen::Matrix4d& G);

    // Compute an efficient inverse of a transformation inverse.
    Eigen::Matrix4d transformInverse(const Eigen::Matrix4d& transform);

    // Convert spatial jacobian to analytic jacobian at a point in the space frame.
    Eigen::MatrixXd spatialToAnalyticJacobian(const Eigen::MatrixXd& spatialJacobian, const Eigen::Vector3d& point);

    /*FILL THIS IN LATER*/
    Eigen::MatrixXd BMatrix(const Eigen::MatrixXd& J, const Eigen::Matrix4d& pose);

    // Override Eigen's implementation of Quaternion -> AxisAngle.
    // Need to do this to fix degenerate 0 angle case (representation singularity) with axis [0, 0, 1], not [1, 0, 0].
    Eigen::Matrix3d skew(const Eigen::Vector3d& w);
    Eigen::Matrix3d AxisAngletoRot(const Eigen::Vector3d& axis, double angle);
    Eigen::Matrix<double, 6, 6> adjoint(const Eigen::Matrix4d& G);
}
