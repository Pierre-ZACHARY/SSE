cmake_minimum_required(VERSION 3.24)
project(SSE_TP1 C)

add_compile_options(-Wall -msse4.1 -O2)
set(CMAKE_C_STANDARD 11)

add_executable(COPYSSE
        TP1-files/src/copy-sse.c TP1-files/src/lib.h)

add_executable(COPYNOSSE
        TP1-files/src/copy_nosse.c TP1-files/src/lib.h)

add_executable(MAXNOSSE
        TP1-files/src/maxnosse.c TP1-files/src/lib.h)

add_executable(MAXSSE
        TP1-files/src/maxsse.c TP1-files/src/lib.h)

add_executable(SUMSSE
        TP1-files/src/sumsse.c TP1-files/src/lib.h)

add_executable(SUMNOSSE
        TP1-files/src/sumnosse.c TP1-files/src/lib.h)


add_executable(SCALAIRE
        TP1-files/src/scalaire.c TP1-files/src/lib.h)

add_executable(SCALAIRE_SSE
        TP1-files/src/scalairesse.c TP1-files/src/lib.h)

add_executable(UINT16SUM
        TP1-files/src/uint16Sum.c TP1-files/src/lib.h TP1-files/src/uint16lib.h)

add_executable(UINT16SUMSSE
        TP1-files/src/uint16SumSSE.c TP1-files/src/lib.h TP1-files/src/uint16lib.h)


add_executable(MAJUSCULE TP1-files/src/majuscule.c TP1-files/src/majusculeLib.h)
add_executable(MAJUSCULESSE TP1-files/src/majusculesse.c TP1-files/src/majusculeLib.h)

enable_testing()
add_executable(TEST_SCALAIRE TP1-files/test/test_scalaire.c TP1-files/src/lib.h TP1-files/src/scalairelib.h)
add_executable(TEST_ADDITION TP1-files/test/test_adduint16.c TP1-files/src/lib.h TP1-files/src/uint16lib.h)
add_executable(TEST_MAJUSCULE TP1-files/test/test_majuscule.c TP1-files/src/majusculeLib.h)
add_test(NAME test_scalar_sse COMMAND TEST_SCALAIRE)
add_test(NAME test_addition_sse COMMAND TEST_ADDITION)
add_test(NAME test_majuscule COMMAND TEST_MAJUSCULE)