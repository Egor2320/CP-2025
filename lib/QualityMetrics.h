#ifndef CP_2025_QUALITYMETRICS_H
#define CP_2025_QUALITYMETRICS_H
#include "Eigen/Dense"
#include <cassert>
#include <algorithm>

namespace CP {
    class QualityMetrics {
    public:
        static double evaluate(const Eigen::VectorXd& target, const Eigen::VectorXd& actual);
    };
}


#endif
