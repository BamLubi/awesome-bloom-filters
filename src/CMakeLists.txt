# for each "src/x.cc", generate target "x"
file(GLOB_RECURSE all_srcs *.cc)

# 将当前目录下所有源文件保存到变量 DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# 生成动态链接库SHARED 静态库STATIC
add_library(bloom_filters SHARED ${DIR_LIB_SRCS})