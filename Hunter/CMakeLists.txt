include_directories(include)
add_definitions(-D_HUNTER_DLL_BUILD -D_MYDEBUG)

set(SOURCE_FILES src/HunterApp.cpp src/pch.cpp)
set(HEADER_FILES include/Hunter.h include/HunterApp.h include/HunterCentral.h include/pch.h)

add_library(Hunter SHARED ${SOURCE_FILES} ${HEADER_FILES})
