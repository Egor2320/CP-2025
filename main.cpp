#include <iostream>
#include "FileParser.h"
#include "LeastSquares.h"
#include "json-develop/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
    std::string path = "D:\\cp_back\\source.csv";
    uint32_t numFeatures = 3;
    CP::FileParser parser;
    CP::RegressionData data = parser.parseCSV(path, numFeatures);
    CP::LeastSquaresMethod sq(data);
    std::cout << sq.compute() << std::endl;


    //    This is for 2-dimensional case, need to think of how to draw all the other cases
    //    auto objs = json::array();
    //    auto points = json::array();
    //    objs.push_back({{"type", "line"}, {"k", b}, {"b", a}, {"color", "green"}});
    //
    //    for (int i = 0; i < n; ++i) {
    //        points.push_back({{"x", data.source[i]}, {"y", data.target[i]}});
    //    }
    //
    //    objs.push_back({{"type", "points"}, {"points", points}, {"color", "red"}});
    //    json j;
    //    j["objects"] = objs;
    //
    //    std::ofstream o("config.json");
    //    o << std::setw(4) << j << std::endl;

    return 0;
}
