#!/bin/bash

echo "Начало сборки проекта"

cmake --build --preset default
build_code=$?

if [ $build_code -ne 0 ]; then
    echo "Сборка проекта завершена с кодом $build_code"
    exit 1
fi

echo "Запуск проекта"
./build/Debug/test_qt.exe
run_code=$?
echo "Запуск проекта завершен с кодом $run_code"

echo "Сборка и запуск проекта завершены"