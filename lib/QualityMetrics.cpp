#include "QualityMetrics.h"

double CP::QualityMetrics::evaluate(const Eigen::VectorXd &target, const Eigen::VectorXd &actual) {
    assert(target.size() == actual.size());
    double res = 0;
    auto len = target.size();
    for (Eigen::Index i = 0; i < len; ++i) {
        res += (target[i] - actual[i]) * (target[i] - actual[i]);
    }
    return sqrt(res)/static_cast<double>(len);
}
