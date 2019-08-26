cmake_minimum_required(VERSION 3.14)
project(lem_debag C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
add_executable(lem_debag main.c validation/read_and_save.c validation/validation.c
        validation/find.c validation/define.c validation/check_parts.c
        validation/free.c validation/make_map.c validation/make_links.c
        validation/solution.c)
target_link_libraries(lem_debag ${CMAKE_SOURCE_DIR}/libft/libft.a)