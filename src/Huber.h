#ifndef CP_2025_HUBER_H
#define CP_2025_HUBER_H
#include "StatsMethod.h"

namespace CP {
    using RData = RegressionData;
    using Vec = Eigen::VectorXd;

    class Huber : public StatsMethod {
        public:
            Huber(const RData& data, double del, double eps, double lr): StatsMethod(data), delta_(del), epochs_(eps), learningRate_(lr){}
            Vec compute() override;

        private:
            double loss(double residual) const;
            double gradient(double residual) const;
            double delta_;
            double epochs_;
            double learningRate_;
    };
} // namespace CP


#endif
