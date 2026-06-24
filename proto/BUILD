load("@protobuf//bazel:proto_library.bzl", "proto_library")
load("@protobuf//bazel:cc_proto_library.bzl", "cc_proto_library")

proto_library(
    name = "drone_state_proto",
    srcs = ["drone_state.proto"],
)

cc_proto_library(
    name = "drone_state_cc_proto",
    deps = [":drone_state_proto"],
    visibility = ["//visibility:public"],
)