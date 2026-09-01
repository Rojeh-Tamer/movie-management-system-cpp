# 🎬 MOVIE MANAGEMENT SYSTEM (C++)

### A modular, multi-file C++ console application designed for managing movie catalogs, user authentication, and persistent file-based data storage. Built as a collaborative team project using professional structural standards and Visual Studio build configurations.

---

# 📌 FEATURES

### • Movie Management: Dynamic operations to add, update, search, and list movie records.
### • User Accounts: Role-based access and user authentication handling.
### • Persistent File Storage: Reads and writes records dynamically across data files (`data.txt`, `moviedata.txt`, `userdata.txt`).
### • Modular Codebase: Clean separation between header interfaces (`include/`), implementation logic (`src/`), and storage datasets (`data/`).

---

# 🛠️ BUILT WITH

### • Language: C++
### • IDE / Tooling: Visual Studio (MSVC Compiler)
### • Storage Engine: Standard C++ File I/O (`<fstream>`)

---

# 👥 TEAM & PROJECT CONTRIBUTIONS

### This project was developed under the leadership of **Peter Ehab**.

#### • Peter Ehab *(Team Leader)* — Project Architecture & Data Storage Systems (`DATA_STORAGE.cpp`, `DATA_STORAGE.h`).
#### • Rojeh Tamer — Movie Management Module & Core Logic (`MOVIE_FUNCS.cpp`, `MOVIE.h`).
#### • Youstina Nabil — Movie Management Module & Core Logic (`MOVIE_FUNCS.cpp`, `MOVIE.h`).
#### • Bishoy Shohdy — Movie Management Module & Core Logic (`MOVIE_FUNCS.cpp`, `MOVIE.h`).
#### • Keroles Ashraf — User Authentication & Account Operations (`USER_FUNCS.cpp`, `USER.h`).
#### • Yasse Karam — User Authentication & Account Operations (`USER_FUNCS.cpp`, `USER.h`).

---

# 📂 PROJECT REPOSITORY STRUCTURE

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

```
🚀 HOW TO RUN THE PROJECT
[!NOTE]

🔗 Repository Link: https://github.com/Rojeh-Tamer/movie-management-system-cpp.git

1️⃣ OPTION 1: VISUAL STUDIO (WINDOWS - RECOMMENDED)
1. Clone the Repository:
Bash
git clone [https://github.com/Rojeh-Tamer/movie-management-system-cpp.git](https://github.com/Rojeh-Tamer/movie-management-system-cpp.git)
cd movie-management-system-cpp
2. Open the Solution:
Double-click pleasecompiler.sln directly in the root directory to load the project in Visual Studio.
3. Build & Execute:
Press Ctrl + F5 to compile and run the application.
2️⃣ OPTION 2: COMMAND LINE COMPILATION (GCC / G++)
1. Clone the Repository:
Bash
git clone [https://github.com/Rojeh-Tamer/movie-management-system-cpp.git](https://github.com/Rojeh-Tamer/movie-management-system-cpp.git)
cd movie-management-system-cpp
2. Compile with Included Headers:
Bash
g++ -Iinclude src/*.cpp -o MovieSystem
3. Run the Executable:
• Windows: MovieSystem.exe
• Linux / macOS: ./MovieSystem
👨‍💻 LICENSE & ACKNOWLEDGMENTS
Created as an academic team project demonstrating modular C++ software architecture, file streaming, and multi-developer version control practices.
