# Ambulance Management System

## Overview
This project implements an advanced Ambulance Management System designed to efficiently handle emergency medical services in Egypt. The system manages hospitals, ambulances, and patient cases through an intelligent dispatching system using various data structures and algorithms.

## Patient Types and Ambulance Matching
The system handles three types of patients with specific ambulance matching rules:

### Patient Categories
1. **Emergency Patients (EP)**
   - Highest priority cases
   - Can ONLY be assigned to Emergency Cars (SC - Special Cars)
   - Require immediate medical attention
   - Automatically matched to nearest available emergency vehicle

2. **Special Patients (SP)**
   - Medium priority cases
   - Flexible assignment - can be matched with either:
     * Special Cars (SC)
     * Normal Cars (NC)
   - Assignment based on availability and proximity

3. **Normal Patients (NP)**
   - Regular priority cases
   - Can ONLY be assigned to Normal Cars (NC)
   - Handled based on standard protocols

### Ambulance Types
1. **Special Cars (SC)**
   - Equipped for emergency situations
   - Primary assignment to Emergency Patients
   - Can handle Special Patients when available
   - Advanced medical equipment and trained staff

2. **Normal Cars (NC)**
   - Standard medical transport
   - Handles Normal Patients
   - Can transport Special Patients when needed
   - Basic medical equipment and standard staff

### Assignment Rules
- Emergency Patients ↔ Special Cars (Exclusive)
- Special Patients ↔ Both Car Types (Flexible)
- Normal Patients ↔ Normal Cars (Exclusive)

### Hospital Assignment
After patient-ambulance matching, the system:
1. Calculates distances to all available hospitals using latitude and longitude coordinates
2. Selects the nearest hospital with available capacity
3. Routes the ambulance to the selected hospital
4. Updates hospital capacity and ambulance status

## Project Structure
```
├── Ambulance/          # Ambulance-related implementations
│   ├── Car.h          # Base ambulance class
│   ├── NC.h           # Normal Car implementation
│   └── SC.h           # Special Car implementation
├── Hospital/           # Hospital management components
├── Patient/           # Patient-related classes
│   ├── Patient.h      # Base patient class
│   ├── EP.h           # Emergency Patient implementation
│   ├── SP.h           # Special Patient implementation
│   └── NP.h           # Normal Patient implementation
├── Organizer/         # Core organization and simulation logic
├── UI/                # User Interface components
└── Data Files
    └── Egypt.txt      # Main simulation data with coordinates
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
- Geographic coordinate system for location-based assignments

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
ID Location(lat,long) Capacity Status
H1 30.40,31.25       50      Active
H2 30.50,31.30       30      Active
```

### Ambulance Data Section:
```
[Ambulance Data]
ID Type Location(lat,long) Status
A1 SC   30.45,31.20      Available
A2 NC   30.55,31.15      Available
```

### Patient Data Section:
```
[Patient Data]
ID Type Priority Location(lat,long) Condition
P1 EP   High     30.35,31.22       Critical
P2 SP   Medium   30.45,31.18       Stable
P3 NP   Low      30.50,31.25       Stable
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
- Geographic coordinate validation
- Patient-Ambulance type mismatch prevention

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