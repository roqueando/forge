file(GLOB HEADER_LIST
  CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**/*.hpp")
file(GLOB SOURCE_LIST
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_library(${RAWR_LIBRARY_NAME} ${SOURCE_LIST} ${HEADER_LIST})


target_link_libraries (${RAWR_LIBRARY_NAME} argparse::argparse)
target_include_directories(${RAWR_LIBRARY_NAME} PUBLIC ../include)

target_compile_features(${RAWR_LIBRARY_NAME} PRIVATE cxx_std_20)
