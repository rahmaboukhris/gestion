# defines the sources to be build in the project lib
set(MAIN Main.cpp)
set(SOURCES Date.cpp Adresse.cpp
Personne.cpp Salarie.cpp Commercial.cpp Directeur.cpp)

# Build a library with all project sources
add_library(Personne-lib  ${SOURCES})
## Create an executable with the main function
add_executable(Main ${MAIN})

# link the whole project sources lib to the main function
target_link_libraries(Main
Personne-lib)

include_directories(${PROJECT_SOURCE_DIR}/include)