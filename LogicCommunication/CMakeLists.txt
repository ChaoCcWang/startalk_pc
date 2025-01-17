project(LogicCommunication)

if (APPLE)
    ADD_DEFINITIONS(-D_MACOS)
elseif (UNIX)
    ADD_DEFINITIONS(-D_LINUX)
else ()
    ADD_DEFINITIONS(-D_WINDOWS)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
    link_libraries(Ws2_32.lib)
    link_libraries(Wldap32.lib)
    link_libraries(Crypt32.lib)
endif ()

#
set(SOURCE_FILES
        Communication.cpp
        Communication.h
        communication_global.h
        dllMain.cpp
        FileHelper.cpp
        FileHelper.h
        GroupManager.cpp
        GroupManager.h
        MessageManager.cpp
        MessageManager.h
        OfflineMessageManager.cpp
        OfflineMessageManager.h
        OnLineManager.cpp
        OnLineManager.h
        UserManager.cpp
        UserManager.h
        SearchManager.cpp
        SearchManager.h
        UserConfig.cpp
        UserConfig.h
        http/HttpRequest.h
        http/QtHttpRequest.cpp
        http/QtHttpRequest.h
        )

set(LIBRARY_OUTPUT_PATH ../bin)
set(CMAKE_DEBUG_POSTFIX "d")

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#添加链接库
target_link_libraries(${PROJECT_NAME}
        EventBus
        Util
        LogicManager
        DataCenter)

if (WIN32)
    target_link_libraries(${PROJECT_NAME}
            libssl
            libcrypto
            libprotobuf)
else ()
    target_link_libraries(${PROJECT_NAME}
            ssl
            crypto
            protobuf)
endif ()
