# Drone Swarm Search Simulation

A 2D multi-agent exploration simulation in C++ where autonomous drone agents collectively map an unknown grid environment—like searching a building floor plan for a target. Built with production-style tooling: Bazel, Protocol Buffers, GoogleTest, and SFML.

## Overview

N drones explore a grid in parallel. Each drone runs a continuous **sense → report → plan → move** loop on its own thread:

1. **Sense** — Raycast from the drone's position to discover nearby cells.
2. **Report** — Write observations (Free / Occupied) to a shared occupancy grid.
3. **Plan** — Request the nearest unclaimed frontier cell from the planner.
4. **Move** — Navigate to the assigned frontier using BFS or A*.

Exploration terminates when no frontier cells remain (every known free cell is adjacent only to known cells).

## Architecture

The codebase is split into four isolated modules:

| Module | Path | Responsibility |
|--------|------|----------------|
| **Grid** | `src/grid/` | Thread-safe shared occupancy grid (`Unknown`, `Free`, `Occupied`) |
| **Drone** | `src/drone/` | Raycasting, grid updates, path following |
| **Planner** | `src/planner/` | Frontier detection and non-redundant task allocation |
| **Visualization** | `src/viz/` | Real-time SFML rendering of the grid and drones |
