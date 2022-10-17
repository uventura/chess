load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

IMPORT_CONTENT = """
cc_import(
    name = "{lib_name}_2_5",
    hdrs = glob([
        "include/**/*"
    ]),
    shared_library = "lib/{lib}.so.2.5",
)

cc_import(
    name = "{lib_name}",
    hdrs = glob([
        "include/**/*"
    ]),
    shared_library = "lib/{lib}.so",
)
"""

BUILD_CONTENT = """
cc_library(
    name = "sfml_linux",
    hdrs = glob([
        "include/**/*"
    ]),
    deps = {deps},
    strip_include_prefix = "include",
)
"""

def sfml_build_content():
    deps = []
    content = """package(default_visibility = ["//visibility:public"])"""

    libs = [
        "libsfml-audio",
        "libsfml-graphics",
        "libsfml-network",
        "libsfml-system",
        "libsfml-window",
    ]

    for lib in libs:
        lib_name = lib.replace("-", "_")
        deps.append(":{}".format(lib_name))
        deps.append(":{}_2_5".format(lib_name))

        content += IMPORT_CONTENT.format(
            lib_name = lib_name,
            lib = lib
        )

    content += BUILD_CONTENT.format(deps = str(deps))

    return content


def sfml():
    http_archive(
        name = "sfml_linux",
        build_file_content = sfml_build_content(),
        url = "https://github.com/SFML/SFML/releases/download/2.5.1/SFML-2.5.1-linux-gcc-64-bit.tar.gz",
        type = "tar.gz",
        strip_prefix = "SFML-2.5.1"
    )
