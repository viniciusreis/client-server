# Set up the compile flags interface library
add_library(solution_compiler_flags INTERFACE)
target_compile_features(solution_compiler_flags INTERFACE cxx_std_20)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(solution_compiler_flags
  INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# Custom target to create a symbolic link to compile_commands.json
if(UNIX)
  add_custom_target(create_symlink ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_SOURCE_DIR}/compile_commands.json
    COMMENT "Creating symlink to compile_commands.json"
  )
elseif(WIN32)
  add_custom_target(create_symlink ALL
    COMMAND cmd.exe /c mklink
      ${CMAKE_SOURCE_DIR}\\compile_commands.json
      ${CMAKE_BINARY_DIR}\\compile_commands.json
    COMMENT "Creating symlink to compile_commands.json"
  )
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
