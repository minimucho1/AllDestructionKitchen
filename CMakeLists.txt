cmake_minimum_required(VERSION 3.0.2)
project(lazy_foo)

include_directories(include)
include_directories(src)

# glob headers
file( GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/include/*.h )
set( SOURCES src/26.cpp ${HEADERS} )

# include cmake find
set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# find SDL library
find_package( SDL2 REQUIRED )
find_package( SDL2_IMAGE REQUIRED )

include_directories( ${SDL2_INCLUDE_DIR} )
include_directories( ${SDL2_IMAGE_INCLUDE_DIR} )

# find Boost library
find_package( Boost REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

# find openssl
find_package( OPENSSL REQUIRED )
include_directories( ${OPENSSL_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME} ${SOURCES})

target_link_libraries( ${PROJECT_NAME} ${SDL2_LIBRARY})
target_link_libraries( ${PROJECT_NAME} ${SDL2_IMAGE_LIBRARY})
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )
target_link_libraries( ${PROJECT_NAME} ${OPENSSL_LIBRARIES} )

target_link_libraries( ${PROJECT_NAME}
${PROJECT_SOURCE_DIR}/lib/libboost_date_time-mt.a
${PROJECT_SOURCE_DIR}/lib/libboost_random-mt.a
${PROJECT_SOURCE_DIR}/lib/libboost_system-mt.a
${PROJECT_SOURCE_DIR}/lib/libsioclient_tls.a
${PROJECT_SOURCE_DIR}/lib/libsioclient.a )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
