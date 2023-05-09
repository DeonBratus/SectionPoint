cmake_minimum_required(VERSION 3.5)

# Установить имя проекта и язык программирования
project(SerialWriter CXX)

# Добавить исполняемый файл main.cpp и файлы SectionPoint.cpp и SectionPoint.h в проект
add_executable(SerialWriter serialMain.cpp ../readcoord/SectionPoint.cpp ../readcoord/SectionPoint.h ../readcoord/PointIO.cpp serialWriter.cpp serialWriter.h)