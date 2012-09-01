cmake_minimum_required(VERSION 2.8.8)

project(c-workbook)

add_definitions(-std=c99)

add_executable(test_linked_list test_linked_list.c linked_list.c)
