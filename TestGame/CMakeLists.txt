include_directories(include ../Hunter/include)

set(SOURCE_FILES src/main.cpp)
set(HEADER_FILES)

add_executable(TestGame ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(TestGame Hunter)

set(VS_STARTUP_PROJECT TestGame)
