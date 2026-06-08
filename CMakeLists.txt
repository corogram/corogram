cmake_minimum_required(VERSION 3.20)
project(corogram VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Options ───────────────────────────────────────────────────────────────────
option(COROGRAM_BUILD_EXAMPLES "Build example binaries" OFF)
option(COROGRAM_ED25519 "Enable Ed25519 Mini App auth (OpenSSL)" OFF)

# ── Required dependencies ─────────────────────────────────────────────────────
find_package(Drogon REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(nlohmann_json REQUIRED)

# ── Optional dependencies ─────────────────────────────────────────────────────
# hiredis is only needed when RedisStorage is used.
# Set COROGRAM_HAS_HIREDIS=ON to opt in explicitly; otherwise auto-detected.
if(NOT DEFINED COROGRAM_HAS_HIREDIS)
    find_package(hiredis CONFIG QUIET)

    if(hiredis_FOUND)
        set(COROGRAM_HAS_HIREDIS ON)
    else()
        set(COROGRAM_HAS_HIREDIS OFF)
    endif()
endif()

if(COROGRAM_HAS_HIREDIS)
    find_package(hiredis CONFIG REQUIRED)
    message(STATUS "corogram: hiredis found — RedisStorage enabled")
else()
    message(STATUS "corogram: hiredis not found — RedisStorage disabled")
endif()

# ── INTERFACE library (header-only) ──────────────────────────────────────────
add_library(corogram INTERFACE)
add_library(corogram::corogram ALIAS corogram)

target_compile_features(corogram INTERFACE cxx_std_20)

target_include_directories(corogram INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(corogram INTERFACE
    Drogon::Drogon
    nlohmann_json::nlohmann_json
    OpenSSL::SSL
    OpenSSL::Crypto
)

# Compiler-specific flags
target_compile_options(corogram INTERFACE

    # GCC / Clang: enable C++20 coroutines explicitly
    $<$<CXX_COMPILER_ID:GNU,Clang>:-fcoroutines>

    # MSVC: allow oversized object files, suppress C4251/C4275 dll-interface warnings
    $<$<CXX_COMPILER_ID:MSVC>:/bigobj /wd4251 /wd4275>
)

# MSVC: suppress min/max macro conflicts from <windows.h>
if(WIN32)
    target_compile_definitions(corogram INTERFACE NOMINMAX WIN32_LEAN_AND_MEAN)
endif()

# Optional feature flags
if(COROGRAM_HAS_HIREDIS)
    target_link_libraries(corogram INTERFACE hiredis::hiredis)
    target_compile_definitions(corogram INTERFACE COROGRAM_HAS_HIREDIS)
endif()

if(COROGRAM_ED25519)
    target_compile_definitions(corogram INTERFACE COROGRAM_ED25519)
    message(STATUS "corogram: Ed25519 Mini App auth enabled")
endif()

# ── Install & export ──────────────────────────────────────────────────────────
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS corogram
    EXPORT corogramTargets
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT corogramTargets
    FILE corogramTargets.cmake
    NAMESPACE corogram::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/corogram
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/corogramConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/corogramConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/corogram
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/corogramConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/corogramConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/corogramConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/corogram
)

# ── Examples ──────────────────────────────────────────────────────────────────
if(COROGRAM_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()