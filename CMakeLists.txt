# CMakeList.txt: проект CMake для 06.homework; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("06.homework")

add_library(libmylib STATIC 
							06_00_homework.cpp 06_00_homework.h
							06_01_homework.cpp 06_01_homework.h)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (06.homework "06.homework.cpp" "06.homework.h" "06_01_homework.cpp" "06_01_homework.h" "06_00_homework.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 06.homework PROPERTY CXX_STANDARD 17)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
