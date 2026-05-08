cmake_minimum_required(VERSION 4.1)
project(BaldaGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(BaldaGame main.cpp
        Model/MoveStatus.h
        Model/Board.cpp
        Model/Board.h
        Model/Dictionary.cpp
        Model/Dictionary.h
        Model/Engine.cpp
        Model/Engine.h
        View/IView.h
        View/TerminalView.cpp
        View/TerminalView.h
        Controller/GameController.cpp
        Controller/GameController.h
)
