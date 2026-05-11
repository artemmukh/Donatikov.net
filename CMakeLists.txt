cmake_minimum_required(VERSION 3.16)
project(Donatikov VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.11.0/msvc2022_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME}
        src/ui/main.cpp

        src/ui/mainwindow.cpp
        src/ui/mainwindow.h
        src/ui/mainwindow.ui

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

        src/ui/topupscreen.cpp
        src/ui/topupscreen.h
        src/ui/topupscreen.ui

        src/ui/notificationscreen.cpp
        src/ui/notificationscreen.h
        src/ui/notificationscreen.ui

        src/ui/sendmoneyscreen.cpp
        src/ui/sendmoneyscreen.h
        src/ui/sendmoneyscreen.ui

        src/ui/newnamewindow.cpp
        src/ui/newnamewindow.h
        src/ui/newnamewindow.ui

        src/ui/newpasswordwindow.cpp
        src/ui/newpasswordwindow.h
        src/ui/newpasswordwindow.ui

        src/ui/servicewindow.cpp
        src/ui/servicewindow.h
        src/ui/servicewindow.ui

        src/ui/subscriptionwindow.cpp
        src/ui/subscriptionwindow.h
        src/ui/subscriptionwindow.ui

        src/core/auth/User.cpp
        src/core/auth/User.h
        src/core/auth/AuthManager.cpp
        src/core/auth/AuthManager.h

        src/core/wallet/Transaction.cpp
        src/core/wallet/Transaction.h

        src/data/UserRepository.cpp
        src/data/UserRepository.h

        src/core/services/IService.h
        src/core/services/IService.cpp
        src/core/services/MobileTopUpService.cpp
        src/core/services/MobileTopUpService.h
        src/core/services/SubscriptionService.h
        src/core/services/SubscriptionService.cpp
        src/core/services/MoneySend.cpp
        src/core/services/MoneySend.h
        src/core/services/GameService.h
        src/core/services/GameService.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
       
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Widgets
)