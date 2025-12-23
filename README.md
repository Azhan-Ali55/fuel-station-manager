# Fuel Management System

## Overview
The **Fuel Management System** is a console-based C++ application developed to manage the basic operations of a fuel station.  
It uses a **role-based login system** where each user has a specific role and responsibilities.

The system is designed to make fuel station management more organized, secure, and efficient by separating access for the **Owner**, **Manager**, and **Fueler (Employee)**.

---

## Why This Program Was Developed
Fuel stations often face problems due to manual handling and lack of proper system control, such as:

- No role-based access system  
- Manual record keeping that causes errors  
- Difficulty in managing staff duties  
- Unclear workflow of daily operations  

This program was created to solve these issues by:

- Automating fuel station operations  
- Providing secure login for different roles  
- Defining a clear program flow  
- Improving efficiency and accountability  

---

## Instructions For Running The Program 

- ### Prerequisites

  1. *CMake*; Should be available in CLI
  2. *C++ compiler linked with CMake*; Should be availabe in CLI
  3. *Visual Studio*; For windows

- ### MacOS

1. Run ./setup.sh
2. Follow instructions given in script
3. Run ./run.sh in terminal
   - The script will generate CMake files, and run the file by itself automatically.

- ### Windows

1. Open the src folder in Visual Studio and run main.cpp

---

## Program Flow

### Login Roles
The system supports the following roles:

- Owner
- Manager
- Fueler (Employee)

---

### Login Credentials

#### Owner
- **Username:** andrew123  
- **Password:** own1  

#### Fueler (Employee)
- **Username:** alex123  
**Password:** emp1  

- **Username:** umer123  
**Password:** emp2  

#### Manager
- **Username:** ali123  
- **Password:** man1  

---

## Future Improvements
- GUI
- Physical Integration with Pumps
- Use SQL for Greater Database 
- Can Update for Digital Salary System

## Additional Documentation
The complete program flow and detailed working of the system are explained in the **Word Document** provided with this project.

Please refer to that document for a deeper understanding of the logic and implementation.
