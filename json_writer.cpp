#include "json_writer.h"

void JSONWriter::saveToJson(DataContainer& container, const std::string& filename) {
    nlohmann::json json_data;
    for (const auto row : container.getData()) {
        json_data["data"].push_back({
            {"DateTime", row.DateTime},
            {"Close", row.Close},
            {"RSI", row.RSI},
            {"Bollindg_h_h", row.Bollindg_h_h},
            {"Bollindg_l_l", row.Bollindg_l_l},
            {"Bull", row.Bull},
            {"Bear", row.Bear}
        });
    }

    std::ofstream file(filename);
    file << json_data.dump(4);
}
