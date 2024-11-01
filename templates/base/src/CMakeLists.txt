file(GLOB HEADER_LIST
  CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**/*.hpp")
file(GLOB SOURCE_LIST
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_library(${<PROJECT_NAME>_LIBRARY_NAME} ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries (${<PROJECT_NAME>_LIBRARY_NAME} leaf)

target_include_directories(${<PROJECT_NAME>_LIBRARY_NAME} PUBLIC ../include)
target_compile_features(${<PROJECT_NAME>_LIBRARY_NAME} PRIVATE cxx_std_20)
