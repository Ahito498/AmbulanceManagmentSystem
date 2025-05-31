# Hi there, I'm Hassan Ahmed Rashwan 👋

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hassan-ahmed-rashwan)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Ahito498)
[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:hassan63ahmed12@gmail.com)

## 🚀 Communication and Information Engineering Student | Software Developer

### 👨‍💻 Professional Summary
Motivated and fast-learning Communication and Information Engineering student at Zewail City of Science, Technology, and Innovation, with strong problem-solving skills and a passion for software development. Proficient in both individual and team-based environments, with hands-on experience in full-stack development using ASP.NET and back-end development using Django. Currently expanding knowledge in Machine Learning and Artificial Intelligence alongside software engineering.

### 🎓 Education
- **B.Sc. in Communication and Information Engineering** (Expected 2027)
  - Zewail City of Science, Technology, and Innovation
  - Giza, Egypt

### 💻 Technical Skills

#### Programming Languages
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C#](https://img.shields.io/badge/C%23-239120?style=for-the-badge&logo=c-sharp&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)

#### Tools & Technologies
- **Development Tools:**
  - SystemVerilog
  - ASP.NET
  - Django
  - MSSQL
  - Docker
  - Git & GitHub

#### Core Competencies
- 💡 Data Structures & Algorithms
- 🗄️ Database Design & SQL
- ⚡ Circuits & Electronics
- 🔧 System Design
- 🧮 Object-Oriented Programming

### 🛠️ Projects

#### 🚑 Ambulance Management System Simulation — C++, OOP
- Simulated real-life ambulance dispatch operations
- Implemented efficient resource allocation algorithms
- Utilized advanced data structures for optimal performance
- Demonstrated strong problem-solving and system design skills

#### 🏢 Room Booking System — Full Stack-ASP.NET
- Designed and implemented a comprehensive booking management system
- Built with ASP.NET framework for robust performance
- Implemented full-stack functionality with clean architecture
- Managed room booking and cleaning request workflows

#### 💻 Shape Studio Project — C++, OOP
- Developed a GUI-based application for shape manipulation
- Implemented core Object-Oriented Programming principles
- Created an intuitive and interactive user interface
- Demonstrated strong software design patterns

#### 🗄️ Database Platform — SQL
- Created a comprehensive database management system
- Implemented efficient request handling mechanisms
- Designed optimized data structures and relationships
- Utilized SQL for complex data operations

#### 🔌 Hardware Projects
- **IR Proximity Sensor** — Circuits Project
  - Designed and built a proximity sensor for object detection
  - Implemented sensor calibration and testing
  - Applied electronic design principles

- **Audio Amplifier** — Electronics Project
  - Created an audio amplification circuit
  - Applied electronic design principles
  - Implemented signal processing techniques

### 🏆 Competitions & Achievements
- **NASA Space Apps Cairo** (2024)
  - Participated in global space technology challenge
  - Worked on innovative space-related solutions

- **PACE Competition - EUROAVIA** (2024)
  - Engaged in international engineering competition
  - Developed technical and teamwork skills

### 📊 GitHub Stats

<a href="https://github.com/Ahito498">
  <img align="center" src="https://github-readme-stats.vercel.app/api?username=Ahito498&show_icons=true&theme=dark" />
</a>
<a href="https://github.com/Ahito498">
  <img align="center" src="https://github-readme-stats.vercel.app/api/top-langs/?username=Ahito498&layout=compact&theme=dark" />
</a>

### 🌱 Current Focus
- Machine Learning & AI Development
- Full-stack Web Development
- Hardware Design & Implementation
- System Architecture & Design Patterns
- Advanced Algorithm Implementation

### 🗣️ Languages
- English: B2-C1 Level (Professional Working Proficiency)
- Arabic: Native

### 📫 Contact Information
- 📱 Phone: 01557502557 / 01014437440
- 📧 Email: hassan63ahmed12@gmail.com
- 💼 LinkedIn: [Hassan Ahmed Rashwan](https://www.linkedin.com/in/hassan-ahmed-rashwan)
- 🌍 Location: Cairo, Egypt

---

<p align="center">
  <img src="https://komarev.com/ghpvc/?username=Ahito498&color=blue&style=flat-square&label=Profile+Views" alt="Profile views" />
</p>

⭐️ From [Ahito498](https://github.com/Ahito498)

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