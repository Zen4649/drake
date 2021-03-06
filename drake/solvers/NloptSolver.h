#pragma once

#include "drake/drakeOptimization_export.h"

#include "drake/solvers/MathematicalProgram.h"

namespace drake {
namespace solvers {

class DRAKEOPTIMIZATION_EXPORT NloptSolver :
      public MathematicalProgramSolverInterface  {
 public:
  // This solver is implemented in various pieces depending on if
  // NLOpt was available during compilation.
  bool available() const override;
  SolutionResult Solve(OptimizationProblem& prog) const override;
};

}  // namespace solvers
}  // namespace drake
