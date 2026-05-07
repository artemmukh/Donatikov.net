cmake_minimum_required(VERSION 3.16)
project(Donatikov VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME}
    src/ui/main.cpp

    src/ui/mainwindow.cpp
    src/ui/mainwindow.h
    src/ui/mainwindow.ui
    src/ui/login.ui

    src/core/auth/User.cpp
    src/core/auth/User.h
    src/core/auth/AuthManager.cpp
    src/core/auth/AuthManager.h

    src/core/wallet/Transaction.cpp
    src/core/wallet/Transaction.h
    src/core/wallet/Wallet.cpp
    src/core/wallet/Wallet.h

    src/data/UserRepository.cpp
    src/data/UserRepository.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
)
