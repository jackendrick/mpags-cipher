# message("Message in file")

add_library(MPAGSCipher STATIC
  IO.cpp
  IO.hpp
  commandLine.hpp
  commandLine.cpp
  CaesarCipher.hpp
  CaesarCipher.cpp
  PlayfairCipher.cpp
  PlayfairCipher.hpp
  CipherFactory.cpp
  CipherFactory.hpp
  
  )
target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
  )
  
target_compile_features(MPAGSCipher
  PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization cxx_binary_literals
  )