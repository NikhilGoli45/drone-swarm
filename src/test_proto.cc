#include "proto/drone_state.pb.h";
#include <iostream>

int main() {
    swarm::DroneState drone_state;
    drone_state.set_id(1);
    drone_state.set_x(0);
    drone_state.set_y(0);
    std::cout << drone_state.DebugString() << std::endl;
    return 0;
}

