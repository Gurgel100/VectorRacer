cmake_minimum_required(VERSION 2.6)
project(VectorGame)

set(CPP_SRC main.cpp Game.cpp Map.cpp MapEntity.cpp Player.cpp TrackReader.cpp Checkpoint.cpp)

add_executable(VectorGame ${CPP_SRC})