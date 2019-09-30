cmake_minimum_required(VERSION 3.14)
project(lem-in C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
add_executable(lem-in main.c validation/read_and_save.c validation/validation.c
        validation/find.c validation/define.c validation/check_parts.c
        validation/free.c validation/make_map.c validation/make_links.c
        solution/solution.c solution/ways.c solution/auxiliary.c solution/shortest_way.c
        solution/find_new_paths.c solution/use_shortest.c solution/sets.c solution/line_breaker.c
        solution/sets_basic.c solution/delete_deadlocks.c solution/calculate_turns.c
        solution/print_solution.c)
target_link_libraries(lem-in ${CMAKE_SOURCE_DIR}/libft/libft.a)