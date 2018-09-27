# cmake_minimum_required(VERSION <specify CMake version here>)
project(TP2_Heritage)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP2_Heritage main.cpp Catalogue.cpp Catalogue.h Trajet.cpp Trajet.h TrajetSimple.cpp TrajetSimple.h TrajetCompose.cpp TrajetCompose.h)