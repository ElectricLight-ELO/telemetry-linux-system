# telemetry-linux-system

Пет-проект системы мониторинга и контроля процессов под Linux (C++20).

Состоит из двух основных сервисов:
- `exporter` — собирает системные метрики и отдает их в формате Prometheus (HTTP `/metrics`).
- `watchdog` — простой супервизор для контроля состояния процессов (health-check).

Общая логика (парсер конфига, логгер) вынесена в библиотеку `core`.

## Модули проекта

* `libs/core` — статическая библиотека с общим функционалом (`config`, `logger`).
* `apps/exporter` — сервис экспорта метрик Prometheus.
* `apps/watchdog` — сервис мониторинга процессов.
* `tests/` — юнит-тесты компонентов.

Основные исходники расположены по стандартной схеме: `include/` для публичных заголовков и `src/` для реализации (`config.cpp`, `logger.cpp`, `main.cpp`). Сборка всех целей управляется через корневой `CMakeLists.txt`.

## Сборка и запуск

Проект разрабатывается и тестируется в WSL2 (Ubuntu 22.04 / 24.04).

### Зависимости
* C++20 (GCC 11+ / Clang 13+)
* CMake 3.20+
* Boost (Boost.Test для интеграции с CTest)

```bash
# Установка базового окружения (Debian/Ubuntu)
sudo apt update
sudo apt install -y build-essential cmake libboost-test-dev

# Сборка
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Запуск приложений
./build/apps/exporter/exporter
./build/apps/watchdog/watchdog

# Запуск тестов
ctest --test-dir build --output-on-failure
```

## Статус разработки

- [x] Каркас проекта и CMake-скрипты (target-based)
- [x] Базовый модуль `core` (логгер, чтение ENV)
- [ ] Интеграция `prometheus-cpp` в exporter
- [ ] Реализация мониторинга процессов в watchdog
- [ ] Покрытие `core` тестами (Boost.Test)
- [ ] Dockerfile / docker-compose (Prometheus + Grafana)
- [ ] CI/CD (GitHub Actions)
