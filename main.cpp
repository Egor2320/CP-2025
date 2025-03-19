#include <iostream>
#include <unordered_map>
#include "FileParser.h"
#include "LeastSquares.h"
#include "QualityMetrics.h"
#include "json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
using stats = std::unordered_map<std::string, Eigen::VectorXd>;

stats runOnMethods(const CP::RegressionData& data, const std::vector<std::string>& methods) {
    stats res;
    for (auto& el : methods) {
        if (el == "LSM") {
            res["LSM"] = CP::LeastSquaresMethod(data).compute();
        } else if (el == "AVG") {
            // ... other methods;
        }
    }
    return res;
}

int main() {
    std::string path = "D:\\CP-2025\\source.csv";
    uint32_t numFeatures = 3;
    CP::FileParser parser;
    CP::RegressionData data = parser.parseCSV(path, numFeatures);
    Eigen::VectorXd target(4);
    target << 0, 1, 1, 1;

    stats computed = runOnMethods(data, {"LSM"});
    for (auto &[name, v] : computed) {
        std::cout << "Error on " << name << ": " << CP::QualityMetrics::evaluate(target, v) << std::endl;
    }

    return 0;
}
