#pragma once

#include <Eigen/Dense>
#include "drake/drakeIKoptions_export.h"

class RigidBodyTree;

class DRAKEIKOPTIONS_EXPORT IKoptions {
 private:
  RigidBodyTree *robot_;
  int nq_;
  Eigen::MatrixXd Q_;
  Eigen::MatrixXd Qa_;
  Eigen::MatrixXd Qv_;
  bool debug_mode_;
  bool sequentialSeedFlag_;
  double SNOPT_MajorFeasibilityTolerance_;
  int SNOPT_MajorIterationsLimit_;
  int SNOPT_IterationsLimit_;
  int SNOPT_SuperbasicsLimit_;
  double SNOPT_MajorOptimalityTolerance_;
  Eigen::RowVectorXd additional_tSamples_;
  bool fixInitialState_;
  Eigen::VectorXd q0_lb_;
  Eigen::VectorXd q0_ub_;
  Eigen::VectorXd qd0_lb_;
  Eigen::VectorXd qd0_ub_;
  Eigen::VectorXd qdf_lb_;
  Eigen::VectorXd qdf_ub_;

 protected:
  void setDefaultParams(RigidBodyTree *robot);

 public:
  explicit IKoptions(RigidBodyTree *robot);
  IKoptions(const IKoptions &rhs);
  ~IKoptions(void);
  RigidBodyTree *getRobotPtr() const;
  void setQ(const Eigen::MatrixXd &Q);
  void setQa(const Eigen::MatrixXd &Qa);
  void setQv(const Eigen::MatrixXd &Qv);
  void setDebug(bool flag);
  void setSequentialSeedFlag(bool flag);
  void setMajorOptimalityTolerance(double tol);
  void setMajorFeasibilityTolerance(double tol);
  void setSuperbasicsLimit(int limit);
  void setMajorIterationsLimit(int limit);
  void setIterationsLimit(int limit);
  void setFixInitialState(bool flag);
  void setq0(const Eigen::VectorXd &lb, const Eigen::VectorXd &ub);
  void setqd0(const Eigen::VectorXd &lb, const Eigen::VectorXd &ub);
  void setqdf(const Eigen::VectorXd &lb, const Eigen::VectorXd &ub);
  void setAdditionaltSamples(const Eigen::RowVectorXd &t_samples);
  void updateRobot(RigidBodyTree *new_robot);
  void getQ(Eigen::MatrixXd &Q) const;
  void getQa(Eigen::MatrixXd &Qa) const;
  void getQv(Eigen::MatrixXd &Qv) const;
  bool getDebug() const;
  bool getSequentialSeedFlag() const;
  double getMajorOptimalityTolerance() const;
  double getMajorFeasibilityTolerance() const;
  int getSuperbasicsLimit() const;
  int getMajorIterationsLimit() const;
  int getIterationsLimit() const;
  void getAdditionaltSamples(Eigen::RowVectorXd &additional_tSamples) const;
  bool getFixInitialState() const;
  void getq0(Eigen::VectorXd &lb, Eigen::VectorXd &ub) const;
  void getqd0(Eigen::VectorXd &lb, Eigen::VectorXd &ub) const;
  void getqdf(Eigen::VectorXd &lb, Eigen::VectorXd &ub) const;
};
