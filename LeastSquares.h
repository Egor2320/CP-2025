#ifndef CP_BACK_LEASTSQUARES_H
#define CP_BACK_LEASTSQUARES_H

#include "eigen/Eigen/Dense"
#include "FileParser.h"

namespace CP {
    using RData = RegressionData;

    class StatMethod {
    public:
        explicit StatMethod(const RData& data);
        virtual Eigen::VectorXd compute() = 0;

    protected:
        Eigen::MatrixXd featuresMatrix_;
        Eigen::VectorXd targetMatrix_;
    };

    class LeastSquaresMethod : public StatMethod {
    public:
        explicit LeastSquaresMethod(const RData& data): StatMethod(data){}
        Eigen::VectorXd compute() override;
    };
} // namespace CP

#endif
