cmake_minimum_required(VERSION 3.16)
project(SSE_TP1 C)

set(CMAKE_C_STANDARD 11)

add_executable(COPYSSE
        src/copy-sse.c src/lib.h)

add_executable(COPYNOSSE
        src/copy_nosse.c src/lib.h)

add_executable(MAXNOSSE
        src/maxnosse.c src/lib.h)

add_executable(MAXSSE
        src/maxsse.c src/lib.h)

add_executable(SUMSSE
        src/sumsse.c src/lib.h)

add_executable(SUMNOSSE
        src/sumnosse.c src/lib.h)


add_executable(SCALAIRE
        src/scalaire.c src/lib.h)

add_executable(SCALAIRE_SSE
        src/scalairesse.c src/lib.h)

add_executable(UINT16SUM
        src/uint16Sum.c src/lib.h src/uint16lib.h)

add_executable(UINT16SUMSSE
        src/uint16SumSSE.c src/lib.h src/uint16lib.h)


add_executable(MAJUSCULE src/majuscule.c src/majusculeLib.h)
add_executable(MAJUSCULESSE src/majusculesse.c src/majusculeLib.h)

enable_testing()
add_executable(TEST_SCALAIRE tests/test_scalaire.c src/lib.h src/scalairelib.h)
add_executable(TEST_ADDITION tests/test_adduint16.c src/lib.h src/uint16lib.h)
add_executable(TEST_MAJUSCULE tests/test_majuscule.c src/majusculeLib.h)
add_test(NAME test_scalar_sse COMMAND TEST_SCALAIRE)
add_test(NAME test_addition_sse COMMAND TEST_ADDITION)
add_test(NAME test_majuscule COMMAND TEST_MAJUSCULE)