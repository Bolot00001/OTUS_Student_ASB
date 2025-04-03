cmake_minimum_required(VERSION 3.10)
project(FinanceDataProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads REQUIRED)

set(nlohmann_json_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz GIT_TAG release-1.12.1
DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
FetchContent_MakeAvailable(json)


add_executable(finance_app main.cpp data_container.cpp indicator_calculator.cpp json_writer.cpp)
target_link_libraries(finance_app PRIVATE Threads::Threads nlohmann_json::nlohmann_json)
