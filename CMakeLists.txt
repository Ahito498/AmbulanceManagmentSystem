cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/1-Stacks)
include_directories(${CMAKE_SOURCE_DIR}/3-Queues)
include_directories(${CMAKE_SOURCE_DIR}/5-PriorityQueue)
include_directories(${CMAKE_SOURCE_DIR}/Hospital)
include_directories(${CMAKE_SOURCE_DIR}/Patient)
include_directories(${CMAKE_SOURCE_DIR}/Ambulance)
include_directories(${CMAKE_SOURCE_DIR}/Organizer)
include_directories(${CMAKE_SOURCE_DIR}/UI)
include_directories(${CMAKE_SOURCE_DIR}/DerivedClasses)

# Source files
set(SOURCE_FILES
    main.cpp
    Hospital/hospital.cpp
    Hospital/hospital.h
    Patient/patient.cpp
    Patient/patient.h
    Patient/SP.cpp
    Patient/SP.h
    Patient/NP.cpp
    Patient/NP.h
    Patient/EP.cpp
    Patient/EP.h
    Ambulance/Car.cpp
    Ambulance/Car.h
    Ambulance/NC.cpp
    Ambulance/NC.h
    Ambulance/SC.cpp
    Ambulance/SC.h
    Organizer/Organizer.cpp
    Organizer/Organizer.h
    UI/UI.cpp
    UI/UI.h
    Organizer/globals.cpp
    Organizer/globals.h
)

# Header-only libraries
set(HEADERS
    1-Stacks/ArrayStack.h
    1-Stacks/StackADT.h
    5-PriorityQueue/LinkedQueue.h
    5-PriorityQueue/Node.h
    5-PriorityQueue/priNode.h
    5-PriorityQueue/priQueue.h
    5-PriorityQueue/QueueADT.h
    DerivedClasses/DerivedPriQueue.h
    DerivedClasses/CancellableQueue.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADERS})

# Copy data files to build directory
file(COPY 
    ${CMAKE_SOURCE_DIR}/Egypt.txt
    ${CMAKE_SOURCE_DIR}/moderate_failure.txt
    ${CMAKE_SOURCE_DIR}/high_failure.txt
    ${CMAKE_SOURCE_DIR}/large_distance.txt
    ${CMAKE_SOURCE_DIR}/all_ep_scenario.txt
    ${CMAKE_SOURCE_DIR}/stress.txt
    DESTINATION ${CMAKE_BINARY_DIR}
)
