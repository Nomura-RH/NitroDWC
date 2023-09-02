subdir('src')

libdwcaccount = library('dwcaccount',
    dependencies: [nitrosdk_dep, nitrosystem_dep, nitrowifi_dep],
    include_directories: nitrodwc_includes,
    pic: false,
    sources: libdwcaccount_srcs
)

nitrodwc_libs += libdwcaccount
