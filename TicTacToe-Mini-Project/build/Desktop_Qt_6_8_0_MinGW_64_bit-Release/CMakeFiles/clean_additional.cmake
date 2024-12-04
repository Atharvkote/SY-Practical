# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\TicTacToe-Multiplayer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TicTacToe-Multiplayer_autogen.dir\\ParseCache.txt"
  "TicTacToe-Multiplayer_autogen"
  )
endif()
