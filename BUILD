load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["src/main.cc"],
)

cc_binary(
    name = "test_proto",
    srcs = ["src/test_proto.cc"],
    deps = ["//proto:drone_state_cc_proto"],
)