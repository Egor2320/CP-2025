#include "LeastSquares.h"
namespace CP {
    Eigen::VectorXd LeastSquaresMethod::compute() {
        return (featuresMatrix_.transpose() * featuresMatrix_).inverse() * featuresMatrix_.transpose() * targetMatrix_;
    }
} // namespace CP
