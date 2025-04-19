cmake_minimum_required(VERSION 3.29)
project(OctoVerso C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(conteneurs/liste)
include_directories(conteneurs/pile)
include_directories(conteneurs/vecteur)

add_executable(OctoVerso
    conteneurs/liste/itemliste.h
    conteneurs/liste/liste.c
    conteneurs/liste/liste.h
        conteneurs/pile/pile.c
    conteneurs/pile/pile.h
        conteneurs/vecteur/itemvecteur.h
        conteneurs/vecteur/vecteur.c
    conteneurs/vecteur/vecteur.h
    Chevalet.c
    Chevalet.h
    Dico.c
    Dico.h
    Jeu.c
    Jeu.h
    main.c
    Pioche.c
    Pioche.h
    Rail.c
    Rail.h)
