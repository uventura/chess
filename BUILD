cc_library(
    name = "hdrs",
    srcs = [
        "stb_perlin.h"
    ]
)

cc_binary(
    name = "main",
    srcs = [
        "main.cpp"
    ],
    data = [
        "resources"
    ],
    deps = [
        "//third_party/sfml:sfml_linux",
        ":hdrs"
    ],
)
