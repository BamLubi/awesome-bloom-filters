# for each "test/x.cc", generate target "x"
file(GLOB_RECURSE all_tests *.cc)

# 并将名称保存到DIR_SRCS的变量中
aux_source_directory(. DIR_SRCS)

# 指定生成目标
foreach(v ${all_tests})
    string(REGEX MATCH "test/.*" relative_path ${v})
    string(REGEX REPLACE "test/" "" target_name ${relative_path})
    string(REGEX REPLACE ".cc" "" target_name ${target_name})

    add_executable(${target_name} ${v})
    # 添加链接库
    target_link_libraries(${target_name} bloom_filters)
endforeach()

