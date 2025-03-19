#ifndef CP_BACK_LEASTSQUARES_H
#define CP_BACK_LEASTSQUARES_H

#include "Eigen/Dense"
#include "FileParser.h"
#include "StatsMethod.h"

namespace CP {
    using RData = RegressionData;

    class LeastSquaresMethod : public StatsMethod {
    public:
        explicit LeastSquaresMethod(const RData& data): StatsMethod(data){}
        Eigen::VectorXd compute() override;
    };
} // namespace CP

#endif
