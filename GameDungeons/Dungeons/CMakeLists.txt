cmake_minimum_required(VERSION 3.20)
project(Dungeons)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Board)
include_directories(BoardCellObjects)
include_directories(CharacterObjects/EnemyFactory)

add_executable(Dungeons
        Board/board.cpp
        Board/board.h
        Board/boardcell.cpp
        Board/boardcell.h
        Board/boardroom.cpp
        Board/boardroom.h
        Board/EnumDifficulty.h
        CharacterObjects/EnemyFactory/enemyfactory.cpp
        CharacterObjects/EnemyFactory/enemyfactory.h
        CharacterObjects/EnemyFactory/enemyfactoryrobber.cpp
        CharacterObjects/EnemyFactory/enemyfactoryrobber.h
        CharacterObjects/EnemyFactory/enemyfactoryshaman.cpp
        CharacterObjects/EnemyFactory/enemyfactoryshaman.h
        CharacterObjects/EnemyFactory/enemyfactoryslime.cpp
        CharacterObjects/EnemyFactory/enemyfactoryslime.h
        CharacterObjects/Items/armor.cpp
        CharacterObjects/Items/armor.h
        CharacterObjects/enemy.cpp
        CharacterObjects/enemy.h
        CharacterObjects/hero.cpp
        CharacterObjects/hero.h
        BoardCellObjects/hideout.cpp
        BoardCellObjects/hideout.h
        Board/item.cpp
        Board/item.h
        CharacterObjects/Items/potion.cpp
        CharacterObjects/Items/potion.h
        BoardCellObjects/road.cpp
        BoardCellObjects/road.h
        CharacterObjects/Items/weapon.cpp
        CharacterObjects/Items/weapon.h
        game.cpp
        game.h
        loader.cpp
        loader.h
        main.cpp Board/character.cpp Board/character.h)
