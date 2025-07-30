# Rubik’s Cube Solver

---

## Project Overview

This project is an exploration into the computer science behind solving one of the world's most famous puzzles. The goal was to implement and compare various search algorithms, from fundamental graph traversals to advanced heuristic-driven searches. The core of the project is the **IDA\* (Iterative Deepening A\*) solver**, which uses a pre-computed **corner pattern database (PDB)** as a heuristic to find optimal solutions to complex scrambles in seconds.

---

## Key Features

- **Multiple Cube Models**:

  - **3D Array**: An intuitive, face-based representation perfect for visualization.
  - **1D Array**: A linearized model optimized for memory efficiency.
  - **Bitboard**: An ultra-fast model using six 64-bit integers, designed for high-speed hashing and minimal memory footprint.

- **High-Performance Solvers**:

  - **BFS**: Guarantees the shortest solution path.
  - **DFS**: A memory-efficient approach for deep state-space exploration.
  - **IDDFS**: Combines the optimality of BFS with the low memory usage of DFS.
  - **IDA\***: The flagship solver, using a powerful heuristic to solve any scramble optimally and efficiently.

- **Pattern Database Heuristic**:

  - A pre-computed **corner pattern database** stores the shortest distance to solve the corners from over 88 million possible orientations.
  - The PDB is generated once using BFS and stored in a compact **nibble array** (4 bits per entry), providing an admissible heuristic for the IDA\* search.

- **Optimized State Hashing**:
  - Custom hash functions and comparison operators are implemented for each cube model.
  - Enables the use of `std::unordered_map` for O(1) average time complexity on state lookups, yielding a **10x speedup** in graph traversal compared to `std::map`.

---

## 🛠️ Technical Architecture

### Cube State Representations

The solver is templated to work with different cube models, each with distinct trade-offs:

- **`Rubiks_3D_Model`**: Easiest to understand, but slower due to memory layout.
- **`Rubiks_1D_Model`**: Better cache performance and memory efficiency than the 3D model.
- **`Rubiks_BitBoard_Model`**: The fastest and most compact representation. Ideal for the massive computations required by IDA\* and PDB generation.

### Search Algorithms

- **Uninformed Searches (BFS, DFS, IDDFS):** These algorithms systematically explore the cube's state space. While BFS and IDDFS can find optimal solutions, their performance degrades exponentially with scramble depth, making them suitable only for simple cases.
- **Informed Search (IDA\*):** This is where the magic happens. IDA\* performs a series of depth-first searches with an increasing depth limit. The key is its heuristic function, $h(n)$, which estimates the distance to the goal. A move is only explored if $f(n) = g(n) + h(n) \le \text{depth\_limit}$, where $g(n)$ is the current path cost. This dramatically prunes the search tree.

### Pattern Database

- **Corner Pattern Database:**
  - Precomputes the minimum moves to solve cube corners from any state.
  - Stored in a compact nibble array (4 bits per entry).
  - Generated using BFS and stored in `Database/cornerDepth.txt`.
  - Loaded at runtime for use in IDA\*.

### Project Structure

```
Rubiks-Cube-Solver/
│
├── main.cpp
├── Database/
│   └── cornerDepth.txt         # Precomputed pattern database (binary, large)
│
├── Models/
│   ├── GenericRubiksCube.h     # Abstract base class for cube models
│   ├── GenericRubiksCube.cpp   # Common cube logic
│   ├── Rubiks_3D_Model.cpp     # 3D array cube implementation
│   ├── Rubiks_1D_Model.cpp     # 1D array cube implementation
│   └── Rubiks_BitBoard_Model.cpp # Bitboard cube implementation
│
├── Solvers/
│   ├── BFS_Solver.h            # BFS solver (templated)
│   ├── DFS_Solver.h            # DFS solver
│   ├── IDDFS_Solver.h/.cpp     # IDDFS solver
│   └── IDAstar_Solver.h        # IDA* solver (templated)
│
├── Pattern_Database/
│   ├── Pattern_Database.h/.cpp # Abstract pattern DB logic
│   ├── Corner_Pattern_Database.h/.cpp # Corner-specific DB
│   ├── Corner_DB_Maker.h/.cpp  # Tool to generate pattern DB
│   ├── Nibble_Array.h/.cpp     # Compact array for DB storage
│   ├── math.h/.cpp             # Permutation/indexing helpers
│   └── PermutationIndexer.h    # Permutation ranking/unranking
│
└── CMakeLists.txt
```

---

## Performance

Performance metrics tested on a standard consumer-grade CPU.

| Solver                    | Scramble Depth | Time to Solve | Optimality |
| :------------------------ | :------------- | :------------ | :--------- |
| **BFS / IDDFS**           | 8 moves        | < 3 seconds   | Guaranteed |
| **IDA\* with Corner PDB** | 13 moves       | < 10 seconds  | Guaranteed |

---

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites

- A C++17 compliant compiler (e.g., GCC 7+, Clang 6+, MSVC 2017+)
- CMake 3.10 or later

### Installation & Execution

1.  **Clone the repository:**

    ```sh
    git clone [https://github.com/YOUR_USERNAME/YOUR_REPO.git](https://github.com/YOUR_USERNAME/YOUR_REPO.git)
    cd Rubiks-Cube-Solver
    ```

2.  **Download the Pattern Database:**
    Make sure the `Database/cornerDepth.txt` file is present. If not, download it from the project's releases page or generate it yourself (see below).

3.  **Build the project using CMake:**

    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

4.  **Run the solver:**
    ```sh
    ./RubiksCubeSolver
    ```

### Generate Pattern Database (Optional)

## You can regenerate the corner pattern database by building and running the `Corner_DB_Maker` utility.

## Usage Example

```cpp
#include "Models/Rubiks_BitBoard_Model.cpp"
#include "Solvers/IDAstar_Solver.h"

int main() {
    Rubiks_BitBoard_Model cube;
    auto shuffleMoves = cube.randomShuffleCube(10);
    cube.print();
    IDAstar_Solver<Rubiks_BitBoard_Model, HashBitBoard> idaStarSolver(cube, "..\\Database\\cornerDepth.txt");
    auto moves = idaStarSolver.solve();
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    return 0;
}
```

---

## References

- Korf, R. E. (1997). "Finding Optimal Solutions to Rubik’s Cube Using Pattern Databases." [Research Paper Link](https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korfrubik.pdf)
