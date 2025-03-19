#include "StatsMethod.h"

CP::StatsMethod::StatsMethod(const RData &data) {
    if (data.empty()) {
        std::cout << "Error, data is empty" << std::endl;
        return;
    }
    auto numFeatures = static_cast<Eigen::Index>(data[0].features.size() + 1);
    auto numSamples = static_cast<Eigen::Index>(data.size());
    featuresMatrix_.resize(numSamples, numFeatures);
    targetMatrix_.resize(numSamples);
    for (Eigen::Index i = 0; i < numSamples; ++i) {
        for (Eigen::Index j = 0; j < numFeatures; ++j) {
            if (!j) {
                featuresMatrix_(i, j) = 1;
            } else {
                featuresMatrix_(i, j) = data[i].features[j-1];
            }
        }
        targetMatrix_[i] = data[i].target;
    }
}