cmake_minimum_required(VERSION 3.0)
project(ee205_lab_08d_animal_farm_1_to_clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_08d_animal_farm_1_to_clion main.cpp addCats.cpp addCats.h programName.h catDatabase.cpp catDatabase.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h updateCats.cpp updateCats.h Cat.cpp Cat.h Gender.h Color.h Weight.cpp Weight.h Animal.cpp Animal.h List.cpp List.h Mammal.cpp Mammal.h Node.h SinglyLinkedList.cpp SinglyLinkedList.h)
