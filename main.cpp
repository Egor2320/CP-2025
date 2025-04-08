#include <iostream>
#include <unordered_map>
#include "FileParser.h"
#include "LeastSquares.h"
#include "QualityMetrics.h"
#include "Huber.h"
#include "Tukey.h"
#include "json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;
using stats = std::unordered_map<std::string, Eigen::VectorXd>;

stats runOnMethods(const CP::RegressionData& data, const std::vector<std::string>& methods) {
    std::ofstream weights;
    weights.open("result.txt");
    stats res;
    for (auto& el : methods) {
        if (el == "LSM") {
            res["LSM"] = CP::LeastSquaresMethod(data).compute();
            weights << "LSM: " << res["LSM"] << std::endl;
        } else if (el == "HUB") {
            // need to parametrize here
            res["HUB"] = CP::Huber(data, 1.345, 1000, 0.01).compute();
            weights << "HUB: " << res["HUB"] << std::endl;
        }
        else if (el == "TUK") {
            // need to parametrize here
            res["TUK"] = CP::Tukey(data, 4.685, 1000).compute();
            weights << "TUK: " << res["TUK"] << std::endl;
        }
    }
    weights.close();
    return res;
}

int main() {
    std::string path = "D:\\CP-2025\\source.csv";
    uint32_t numFeatures = 3;
    CP::FileParser parser;
    CP::RegressionData data = parser.parseCSV(path, numFeatures);
    Eigen::VectorXd target(4);
    target << 0, 1, 1, 1;

    stats computed = runOnMethods(data, {"LSM", "HUB", "TUK"});
    for (auto &[name, v] : computed) {
        std::cout << "Error on " << name << ": " << CP::QualityMetrics::evaluate(target, v) << std::endl;
    }

    return 0;
}
