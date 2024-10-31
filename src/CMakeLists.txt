file(GLOB HEADER_LIST
  CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/**/*.hpp")
file(GLOB SOURCE_LIST
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
)

add_library(${FORGE_LIBRARY_NAME} ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries (${FORGE_LIBRARY_NAME} leaf)

target_include_directories(${FORGE_LIBRARY_NAME} PUBLIC ../include)
target_compile_features(${FORGE_LIBRARY_NAME} PRIVATE cxx_std_20)
