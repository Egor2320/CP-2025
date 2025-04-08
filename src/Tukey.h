#include "StatsMethod.h"
#ifndef CP_2025_TUKEY_H
#define CP_2025_TUKEY_H
namespace CP {
    using RData = RegressionData;
    using Vec = Eigen::VectorXd;
    using Mat = Eigen::MatrixXd;

    class Tukey : public StatsMethod {
    public:
        Tukey(const RData& data, double del, double eps): StatsMethod(data), delta_(del), epochs_(eps){}
        Vec compute() override;
    private:
        double gradient(double rem);
        double delta_;
        double epochs_;
    };
} // namespace CP;


#endif
