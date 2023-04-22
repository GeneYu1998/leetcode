cmake_minimum_required(VERSION 3.16)
project(custom_logger_exercise)
get_filename_component(DOMAIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR} ABSOLUTE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__FILE_NAME__='\"$(notdir $(subst .o,,$(abspath $@)))\"'")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILE_NAME__='\"$(notdir $(subst .o,,$(abspath $@)))\"'")

include_directories(${CMAKE_INCLUDE_PATH} ${DOMAIN_ROOT}/include)

aux_source_directory(${DOMAIN_ROOT}/src SOURCE_FILES)

add_executable(output ${SOURCE_FILES})

# target_link_directories(output PRIVATE ${DOMAIN_ROOT}/include)

install(TARGETS output RUNTIME DESTINATION ${DOMAIN_ROOT})
