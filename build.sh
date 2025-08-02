#!/bin/bash

echo "Начало сборки проекта"

if [ -f .env ]; then
  echo "Загрузка переменных из .env"
  export $(grep -v '^#' .env | xargs)
else
  echo ".env файл не найден, пропуск"
fi

if [ -z "$PATH_VCPKG" ]; then
  echo "Ошибка: переменная PATH_VCPKG не установлена"
  exit 1
fi

# Сборка
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
