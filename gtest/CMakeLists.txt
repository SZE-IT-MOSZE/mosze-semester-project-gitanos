cmake_minimum_required(VERSION 3.14)

set(This game_test)

project(${This})

include(FetchContent)

FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(game_test unit_tests.cpp)
target_link_libraries(game_test gtest_main)
include(GoogleTest)
gtest_discover_tests(game_test)