# Balda Game - OOP C++ Project

## Overview
**Balda** is a classic word-building game implemented in C++ as a demonstration of **Object-Oriented Programming (OOP)** principles and the **Model-View-Controller (MVC)** architectural pattern. The project focuses on clean code separation, encapsulation, and polymorphism.

## Game Rules
* **Players:** 2 players.
* **Grid:** A 5x5 game board.
* **Setup:** The game starts with a 5-letter English word placed horizontally in the center row.
* **Turn Sequence:**
  1. A player adds exactly **one letter** to an empty cell adjacent (horizontally or vertically) to an occupied cell.
  2. The player must form a **new word** using the newly placed letter and existing letters on the board.
  3. Movement between letters in a word is restricted to horizontal and vertical steps (no diagonals).
* **Scoring:** Players receive points equal to the number of letters in the formed word.
* **Win Condition:** The game ends when the board is full. The player with the most points wins.
* **House Rule:** If a word is not found in the pre-loaded dictionary, the program prompts both players. If both agree the word is valid, it is added to the dictionary and points are awarded.

## Program Architecture (MVC)
The application follows the **MVC** pattern to ensure a strict separation of concerns:

- **Model:**
  - `Engine`: Manages game logic, scoring, and turn transitions.
  - `Board`: Represents the 5x5 grid and manages character placement.
  - `Dictionary`: Handles word validation using an optimized `std::unordered_set` for O(1) lookup.
- **View:**
  - `IView`: An abstract interface defining the UI contract.
  - `TerminalView`: A concrete implementation for the command-line interface, featuring cross-platform screen clearing.
- **Controller:**
  - `GameController`: The orchestrator that handles the main game loop, synchronizing user input with the game engine.

## Technologies Used
- **Language:** C++17
- **Standard Library:** STL containers (`unordered_set`), File I/O (`fstream`), Strings.
- **Build System:** CMake
- **IDE:** CLion

## Terminal Preview
Below are screenshots demonstrating the game interface and interaction:

### Game Start & Board View
<img width="504" height="337" alt="Screenshot 2026-05-12 at 17 07 01" src="https://github.com/user-attachments/assets/0c7d557f-e232-42e4-b2df-ea1f6e1d3517" />

*Initial board state with the starting word "APPLE".*

### Making a Move
<img width="575" height="308" alt="Screenshot 2026-05-12 at 17 08 11" src="https://github.com/user-attachments/assets/8685e234-2d06-4c59-8240-913c7e33a35a" />

*Player entering coordinates and a new word.*

### House Rule Voting
<img width="575" height="109" alt="Screenshot 2026-05-12 at 17 09 41" src="https://github.com/user-attachments/assets/5c9e82b1-ba37-4992-a516-afc200ceebfd" />

*The voting prompt when a word is missing from the dictionary.*

---
*Developed by Mikhail Ramaniuk as part of IT & Computer Science studies.*
