#!/bin/bash

# Скрипт для запуска тестирования интерфейса с переключением вертолетов

echo "=== Запуск ECAMGCU9 ==="
cd build
rm -f Makefile
qmake ../ECAMGCU9.pro
make -j$(nproc)
# Запускаем приложение с перенаправлением вывода
./ECAMGCU9
