# Chess Game using Qt in Visual Studio

## Overview
This is a chess game application developed using Qt in Visual Studio. The project utilizes the Model-View-Controller (MVC) design pattern to separate the internal representations of information from the ways that information is presented and accepted.

## Features
- Implementation of all standard chess rules.
- Graphical User Interface (GUI) for an interactive chess experience.
- Object-Oriented Design with separate classes for different chess pieces.
- Error handling for illegal moves and game state validation.

## File Structure
Below is a brief description of the main files and their roles in the project:

- **main.cpp**: The entry point of the application. It initializes the application and the main window.
- **constants.hpp**: Contains constant values used across the application.
- **cmake_cours.cmake**: CMake configuration file for building the project.
- **Queen.cpp / Queen.hpp**: Implementation of the Queen piece.
- **Rook.cpp / Rook.hpp**: Implementation of the Rook piece.
- **Square.cpp / Square.hpp**: Represents a square on the chessboard.
- **TestChess.cpp**: Contains test cases for the chess game logic.
- **Game.cpp / Game.hpp**: Manages the overall game state and game logic.
- **King.cpp / King.hpp**: Implementation of the King piece.
- **Knight.cpp / Knight.hpp**: Implementation of the Knight piece.
- **Pawn.cpp / Pawn.hpp**: Implementation of the Pawn piece.
- **Piece.cpp / Piece.hpp**: Base class for all chess pieces.
- **Bishop.cpp / Bishop.hpp**: Implementation of the Bishop piece.
- **Board.cpp / Board.hpp**: Manages the chessboard and its state.
- **ChessController.cpp / ChessController.hpp**: Controller class that handles user inputs and updates the model and view.
- **ChessGUI.cpp / ChessGUI.hpp**: View class that manages the graphical representation of the chessboard and pieces.
- **DoubleInstanceOfKingError.hpp**: Custom error handling for illegal game states.

## Setup and Installation
1. **Clone the Repository**: Clone the project repository from GitHub.
   ```sh
   git clone <repository_url>
   ```
2. **Open in Visual Studio**: Open the `.sln` file in Visual Studio.
3. **Install Qt**: Make sure you have Qt installed and configured in Visual Studio.
4. **Build the Project**: Build the project using the CMake configuration.
5. **Run the Application**: Run the project from Visual Studio to launch the chess game.

## How to Play
- Start the application to open the main window with the chessboard.
- Use the mouse to select and move pieces according to standard chess rules.
- The application will handle all game logic, including turn management and move validation.

## Contributing
1. **Fork the Repository**: Fork the repository on GitHub.
2. **Create a Branch**: Create a new branch for your feature or bugfix.
   ```sh
   git checkout -b feature/new-feature
   ```
3. **Commit Your Changes**: Commit your changes with a descriptive message.
   ```sh
   git commit -m "Add new feature"
   ```
4. **Push to Branch**: Push your changes to your branch.
   ```sh
   git push origin feature/new-feature
   ```
5. **Create a Pull Request**: Open a pull request on GitHub.

## License
This project is licensed under the MIT License. See the `LICENSE.txt` file for more details.

## Contact
For any inquiries or issues, please contact Bouka Christ Bony Karl at christbouka14@yahoo.fr.
