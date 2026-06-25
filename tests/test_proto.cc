#include "proto/drone_state.pb.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(DroneStateTest, SettersAndGetters) {
    swarm::DroneState drone_state;
    drone_state.set_id(1);
    drone_state.set_x(0);
    drone_state.set_y(4);
    EXPECT_EQ(drone_state.id(), 1);
    EXPECT_EQ(drone_state.x(), 0);
    EXPECT_EQ(drone_state.y(), 4);
}

TEST(DroneStateTest, Constructor) {
    swarm::DroneState drone_state;
    EXPECT_EQ(drone_state.id(), 0);
    EXPECT_EQ(drone_state.x(), 0);
    EXPECT_EQ(drone_state.y(), 0);
}

TEST(DroneStateTest, SerializeAndDeserialize) {
    swarm::DroneState drone_state;
    drone_state.set_id(1);
    drone_state.set_x(0);
    drone_state.set_y(4);
    std::string serialized;
    EXPECT_TRUE(drone_state.SerializeToString(&serialized));
    swarm::DroneState deserialized;
    EXPECT_TRUE(deserialized.ParseFromString(serialized));
    EXPECT_EQ(deserialized.id(), 1);
    EXPECT_EQ(deserialized.x(), 0);
    EXPECT_EQ(deserialized.y(), 4);   
}