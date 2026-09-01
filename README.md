# Movie Management System (C++)

A modular, multi-file C++ console application designed for managing movie catalogs, user authentication, and persistent file-based data storage. Built as a collaborative team project using professional structural standards and Visual Studio build configurations.

---

## 📌 Features

* **Movie Management:** Dynamic operations to add, update, search, and list movie records.
* **User Accounts:** Role-based access and user authentication handling.
* **Persistent File Storage:** Reads and writes records dynamically across dedicated data files (`data.txt`, `moviedata.txt`, `userdata.txt`).
* **Modular Codebase:** Clean separation between header interfaces (`include/`), implementation logic (`src/`), and storage datasets (`data/`).

---

## 🛠️ Built With

* **Language:** C++
* **IDE / Tooling:** Visual Studio (MSVC Compiler)
* **Storage Engine:** Standard C++ File I/O (`<fstream>`)

---

## 👥 Team & Project Contributions

This project was developed under the leadership of **Peter Ehab**.

* **Peter Ehab** *(Team Leader)* — Project Architecture & Data Storage Systems (`DATA_STORAGE.cpp`, `DATA_STORAGE.h`).
* **Rojeh Tamer** — Movie Management Module & Core Logic (`MOVIE_FUNCS.cpp`, `MOVIE.h`).
* **Youstina Nabil** — Movie Management Module & Core Logic (`MOVIE_FUNCS.cpp`, `MOVIE.h`).
* **Bishoy Shohdy** — Movie Management Module & Core Logic (`MOVIE_FUNCS.cpp`, `MOVIE.h`).
* **Keroles Ashraf** — User Authentication & Account Operations (`USER_FUNCS.cpp`, `USER.h`).
* **Yasse Karam** — User Authentication & Account Operations (`USER_FUNCS.cpp`, `USER.h`).

---

## 📂 Project Repository Structure

```text
movie-management-system-cpp/
├── src/                            # Implementation files (.cpp)
│   ├── DATA_STORAGE.cpp
│   ├── MAIN_FUNC.cpp
│   ├── MAINMENU.cpp
│   ├── MOVIE_FUNCS.cpp
│   ├── USER_FUNCS.cpp
│   └── pleasecompiler.cpp
├── include/                        # Declaration header files (.h)
│   ├── DATA_STORAGE.h
│   ├── MOVIE.h
│   └── USER.h
├── data/                           # Storage datasets & persistent text files
│   ├── data.txt
│   ├── moviedata.txt
│   └── userdata.txt
├── pleasecompiler.sln              # Visual Studio Solution File
├── pleasecompiler.vcxproj          # Visual Studio C++ Project File
├── pleasecompiler.vcxproj.filters  # Visual Studio Project Filters
└── README.md                       # Project Documentation
🚀 How to Run the Project
Option 1: Visual Studio (Windows - Recommended)
Clone the Repository:

Bash
git clone [https://github.com/Rojeh-Tamer/movie-management-system-cpp.git](https://github.com/Rojeh-Tamer/movie-management-system-cpp.git)
cd movie-management-system-cpp
Open the Solution:
Double-click pleasecompiler.sln to load the complete project configuration in Visual Studio.

Build & Execute:
Press Ctrl + F5 to compile and execute the application without debugging.

Option 2: Command Line Compilation (GCC / g++)
Clone the Repository:

Bash
git clone [https://github.com/Rojeh-Tamer/movie-management-system-cpp.git](https://github.com/Rojeh-Tamer/movie-management-system-cpp.git)
cd movie-management-system-cpp
Compile with Included Headers:

Bash
g++ -Iinclude src/*.cpp -o MovieSystem
Run the Executable:

Windows: MovieSystem.exe

Linux / macOS: ./MovieSystem

👨‍💻 License & Acknowledgments
Created as an academic team project demonstrating modular C++ software architecture, file streaming, and multi-developer version control practices.
