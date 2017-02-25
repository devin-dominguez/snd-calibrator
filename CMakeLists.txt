project(ofApp)
set(APP ofApp)

cmake_minimum_required(VERSION 2.8)

set(OF_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../of/" CACHE PATH "The root directory of ofnode/of project.")
include(${OF_ROOT}/openFrameworks.cmake)

#ofxaddon()
ofxAddon(ofxXmlSettings)
ofxAddon(ofxKinect)
ofxAddon(ofxOpenCv)
ofxaddon(addons/ofxHTTP)
ofxaddon(addons/ofxIO)
ofxaddon(addons/ofxMediaType)
ofxaddon(addons/ofxNetworkUtils)
ofxaddon(addons/ofxSSLManager)
ofxaddon(addons/ofxTaskQueue)
ofxaddon(addons/ofxJSON)
ofxaddon(addons/ofxV4L2Settings)
ofxaddon(addons/ofxJSONRPC)

option(COTIRE "Use cotire" ON)

set(SOURCES
    src/main.cpp
    src/ofApp.cpp
    src/gc_depth.cpp
    src/gc_rgb.cpp
    src/color_tracker.cpp
    src/calibration_server.cpp
    src/projector.cpp
)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated" )

add_executable(
    ${APP}
    MACOSX_BUNDLE
    ${SOURCES}
    ${OFXADDONS_SOURCES}
)

target_link_libraries(
    ${APP}
    ${OPENFRAMEWORKS_LIBRARIES}
    v4l2
)

set_target_properties(
    ${APP} PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST
    "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist"
)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set_target_properties( ${APP} PROPERTIES OUTPUT_NAME "${APP}-Debug")
endif()

if (CMAKE_CROSSCOMPILING)
    set_target_properties( ${APP} PROPERTIES OUTPUT_NAME
      "${APP}-${OF_PLATFORM}-${CMAKE_BUILD_TYPE}")
endif()

if (COTIRE)
    cotire(${APP})
endif()
