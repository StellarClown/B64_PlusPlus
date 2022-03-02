cmake_minimum_required (VERSION 3.8)

project ("B64++")
include_directories(lib)

add_executable (B64++ "B64++.cpp"  "lib/Base64.h" "lib/Base64.cpp")
