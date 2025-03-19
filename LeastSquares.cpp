#include "LeastSquares.h"
namespace CP {
    CP::StatMethod::StatMethod(const RData &data) {
        if (data.empty()) {
            std::cout << "Error, data is empty" << std::endl;
            return;
        }
        auto numFeatures = data[0].features.size() + 1, numSamples = data.size();
        featuresMatrix_.resize(numSamples, numFeatures);
        targetMatrix_.resize(numSamples);
        for (int i = 0; i < numSamples; ++i) {
            for (int j = 0; j < numFeatures; ++j) {
                if (!j) {
                    featuresMatrix_(i, j) = 1;
                } else {
                    featuresMatrix_(i, j) = data[i].features[j-1];
                }
            }
            targetMatrix_[i] = data[i].target;
        }
    }

    Eigen::VectorXd LeastSquaresMethod::compute() {
        return (featuresMatrix_.transpose() * featuresMatrix_).inverse() * featuresMatrix_.transpose() * targetMatrix_;
    }
} // namespace CP
