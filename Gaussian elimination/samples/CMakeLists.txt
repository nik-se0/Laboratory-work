# Set target name
set(target ${02_LAB_POLYNOMSTABLE_SAMPLE})

# Get list of header and source files
FILE(GLOB hdrs "*.h")
#FILE(GLOB srcs "*.c")
FILE(GLOB srcs "*.cpp")

# Add an executable to be built from the source
# files listed in the command invocation
ADD_EXECUTABLE(${target} ${srcs} ${hdrs})

# Add a dependency between top-level targets
ADD_DEPENDENCIES(${target} ${02_LAB_POLYNOMSTABLE_LIBRARY})

# Link a target to given libraries
TARGET_LINK_LIBRARIES(${target} ${02_LAB_POLYNOMSTABLE_LIBRARY})

# Specify include directories to use when compiling a target
TARGET_INCLUDE_DIRECTORIES(${target} PRIVATE ${02_LAB_POLYNOMSTABLE_INCLUDE})