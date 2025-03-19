#ifndef CP_2025_STATSMETHOD_H
#define CP_2025_STATSMETHOD_H

#include "FileParser.h"
#include "Eigen/Dense"

namespace CP {
    using RData = RegressionData;
    class StatsMethod {
    public:
        explicit StatsMethod(const RData& data);
        virtual Eigen::VectorXd compute() = 0;

    protected:
        Eigen::MatrixXd featuresMatrix_;
        Eigen::VectorXd targetMatrix_;
    };
}


#endif //CP_2025_STATSMETHOD_H
