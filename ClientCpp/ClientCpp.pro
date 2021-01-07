QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DEFINES += "_GLIBCXX_USE_CXX11_ABI=1"

# Casablanca

LIBS += -lcpprest
INCLUDEPATH += /usr/local/include

## Azure Blob Storage Client

LIBS += -lazurestorage
INCLUDEPATH += /usr/local/include

LIBS += -lboost_system \
-lssl \
-lcrypto \
-luuid \
-lxml2 \
-lhsm_security_client \
-luhttp \
-lparson \
-lserializer \
-luamqp \
-lumock_c \
