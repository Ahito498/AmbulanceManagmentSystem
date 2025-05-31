# Ambulance Management System

## Overview
This project implements an advanced Ambulance Management System designed to efficiently handle emergency medical services in Egypt. The system manages hospitals, ambulances, and patient cases through an intelligent dispatching system using various data structures and algorithms.

## Project Structure
```
├── Ambulance/          # Ambulance-related implementations
├── Hospital/           # Hospital management components
├── Organizer/          # Core organization and simulation logic
├── Patient/            # Patient-related classes and handling
├── UI/                 # User Interface components
├── DerivedClasses/     # Extended class implementations
├── 1-Stacks/          # Stack data structure implementations
├── 3-Queues/          # Queue data structure implementations
├── 5-PriorityQueue/   # Priority Queue implementations
└── Data Files
    ├── Egypt.txt              # Main simulation data for Egypt regions
    ├── moderate_failure.txt   # Moderate failure scenario test data
    ├── high_failure.txt       # High failure scenario test data
    ├── large_distance.txt     # Large distance scenario test data
    ├── all_ep_scenario.txt    # All emergency protocols test data
    └── stress.txt            # System stress test data
```

## Features
- Real-time ambulance dispatch management
- Hospital capacity and resource tracking
- Patient priority queuing system
- Multiple emergency scenario handling
- Efficient routing and assignment algorithms
- Comprehensive failure management systems
- Real-time status monitoring and updates

## Technical Implementation
The system is implemented in C++ and utilizes various data structures:
- Priority Queues for emergency case management and patient prioritization
- Queues for handling patient waiting lists and ambulance dispatch
- Stacks for managing historical data and operation logs
- Custom classes for Hospitals, Ambulances, and Patients with inheritance hierarchy

## Getting Started

### Prerequisites
- C++ Compiler (C++11 or later)
- CMake (version 3.x or later)
- IDE supporting CMake projects (recommended: CLion, Visual Studio, or VS Code)
- Git (for version control)

### Building the Project
1. Clone the repository:
```bash
git clone https://github.com/yourusername/AmbulanceManagementSystem.git
cd AmbulanceManagementSystem
```

2. Build using CMake:
```bash
mkdir build
cd build
cmake ..
make
```

### Running the Simulation
Execute the compiled binary:
```bash
./AmbulanceManagementSystem
```

## Input File Format
The system accepts text files with the following format:

### Hospital Data Section:
```
[Hospital Data]
ID Location Capacity Status
H1 30,40    50      Active
H2 60,70    30      Active
```

### Ambulance Data Section:
```
[Ambulance Data]
ID Status    Location
A1 Available 35,45
A2 Busy      55,65
```

### Patient Data Section:
```
[Patient Data]
ID Priority Location Condition
P1 High     25,35    Critical
P2 Medium   45,55    Stable
```

## Testing Scenarios
The project includes multiple test scenarios:
- `moderate_failure.txt`: Tests system response to moderate failures (50% load)
- `high_failure.txt`: Stress tests under high failure conditions (80% load)
- `large_distance.txt`: Tests routing with significant distances (>50km)
- `all_ep_scenario.txt`: Tests all emergency protocols simultaneously
- `stress.txt`: System performance under heavy load (100% capacity)

## Error Handling
The system implements robust error handling for:
- File I/O operations and invalid file formats
- Invalid data formats and corrupted input
- Resource allocation failures and memory management
- Runtime exceptions and system failures
- Network and communication errors
- Invalid user input and boundary conditions

## Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Authors
- Hassan Rashwan - *Initial work and maintenance*

## Acknowledgments
- Thanks to all contributors and testers
- Special thanks to the project supervisors and mentors
- Inspired by real-world emergency response systems 