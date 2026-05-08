cmake_minimum_required(VERSION 3.16)
project(Donatikov VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_PREFIX_PATH "C:/Qt/6.11.0/msvc2022_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    src/ui/main.cpp

    src/ui/mainwindow.ui
    src/ui/mainwindow.h
    src/ui/mainwindow.cpp

    src/ui/loginwindow.cpp
    src/ui/loginwindow.h
    src/ui/loginwindow.ui

    src/ui/dashboardscreen.cpp
    src/ui/dashboardscreen.h
    src/ui/dashboardscreen.ui

    src/ui/profilewindow.cpp
    src/ui/profilewindow.h
    src/ui/profilewindow.ui

    src/ui/aboutuswindow.cpp
    src/ui/aboutuswindow.h
    src/ui/aboutuswindow.ui

    src/core/wallet/Transaction.cpp
    src/core/wallet/Transaction.h
    src/core/wallet/Wallet.cpp
    src/core/wallet/Wallet.h

    src/core/auth/User.cpp
    src/core/auth/User.h
    src/core/auth/AuthManager.cpp
    src/core/auth/AuthManager.h

    src/data/UserRepository.cpp
    src/data/UserRepository.h
)

add_executable(${PROJECT_NAME} ${SOURCES}  )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
)