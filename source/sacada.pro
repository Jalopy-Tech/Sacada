# Add QT modules
TEMPLATE = app

QT       += core gui widgets

QT       += core5compat

# Turn off console

CONFIG -= console

# Set compiler options

CONFIG += c++17
macx:CONFIG += app_bundle

# Set the platformm used by the build path

unix:PLATFORM = "Linux"
win32:PLATFORM = "Windows"
macx:PLATFORM = "macOS"


# Set path variables

ROOTDIR = ..
SOURCEDIR = .


# Set the build path

CONFIG(debug, debug|release) {
    DESTDIR = $$ROOTDIR/builds/$$PLATFORM/debug/sacada
}
CONFIG(release, debug|release) {
    DESTDIR = $$ROOTDIR/builds/$$PLATFORM/release/sacada
}

unix:TARGET = "sacada"
win32:TARGET = "Sacada"
macx:TARGET = "Sacada"

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui



# Set the application icon

linux:RC_ICONS = sacada.ico
win32:RC_ICONS = sacada.ico
macx:ICON = sacada.icns


# Resources

RESOURCES += $$SOURCEDIR/resources/sacada.qrc

# Main

SOURCES     +=  $$SOURCEDIR/main/main.cpp \


# Model

HEADERS     +=  $$SOURCEDIR/models/art.h \


SOURCES     +=  $$SOURCEDIR/models/art.cpp \

     

INCLUDEPATH +=  $$SOURCEDIR/models \


# View

HEADERS     +=  $$SOURCEDIR/views/view.h \
                $$SOURCEDIR/views/gui_view.h \
                $$SOURCEDIR/views/console_view.h \
                $$SOURCEDIR/views/windows_console_fix.h \
                $$SOURCEDIR/views/artwizard/artwizard.h \
                $$SOURCEDIR/views/artwizard/enterdetailswizardpage.h \
                $$SOURCEDIR/views/artwizard/findwizardpage.h \
                $$SOURCEDIR/views/artwizard/savewizardpage.h \
                $$SOURCEDIR/views/artwizard/showsummarywizardpage.h \


SOURCES     +=  $$SOURCEDIR/views/view.cpp \
                $$SOURCEDIR/views/gui_view.cpp \
                $$SOURCEDIR/views/console_view.cpp \
                $$SOURCEDIR/views/windows_console_fix.cpp \
                $$SOURCEDIR/views/artwizard/artwizard.cpp \
                $$SOURCEDIR/views/artwizard/enterdetailswizardpage.cpp \
                $$SOURCEDIR/views/artwizard/findwizardpage.cpp \
                $$SOURCEDIR/views/artwizard/savewizardpage.cpp \
                $$SOURCEDIR/views/artwizard/showsummarywizardpage.cpp \


FORMS       +=  $$SOURCEDIR/views/ui/artwizard.ui \
                $$SOURCEDIR/views/ui/enterdetailswizardpage.ui \
                $$SOURCEDIR/views/ui/findwizardpage.ui \
                $$SOURCEDIR/views/ui/savewizardpage.ui \
                $$SOURCEDIR/views/ui/showsummarywizardpage.ui \


INCLUDEPATH +=  $$SOURCEDIR/views \
INCLUDEPATH +=  $$SOURCEDIR/views/artwizard \


# Presenters

HEADERS     +=  $$SOURCEDIR/presenters/presenter.h \


SOURCES     +=  $$SOURCEDIR/presenters/presenter.cpp \


INCLUDEPATH +=  $$SOURCEDIR/presenters \


# Controllers

HEADERS     +=  $$SOURCEDIR/controllers/controller.h \


SOURCES     +=  $$SOURCEDIR/controllers/controller.cpp \


INCLUDEPATH +=  $$SOURCEDIR/controllers \




