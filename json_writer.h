#ifndef JSON_WRITER_H
#define JSON_WRITER_H

#include "data_container.h"
#include <nlohmann/json.hpp>
#include <fstream>

class JSONWriter {
public:
    static void saveToJson(DataContainer& container, const std::string& filename);
};

#endif
