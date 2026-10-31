# STM32 Dryer Temperature Controller

STM32F103RB를 활용한 온도 측정 및 자동 제어 시스템입니다.

DS18B20 센서로 온도를 측정하고, 설정된 목표 온도를 기준으로 릴레이를 제어하여 히터의 ON/OFF 동작을 수행합니다.

OLED와 FND를 통해 온도 및 동작 상태를 표시하고, UART DMA를 활용하여 PC에서 실시간으로 온도 데이터를 모니터링할 수 있도록 구현하였습니다.

## 1. Development Environment

- **MCU:** STM32F103RB (NUCLEO-F103RB)
- **IDE:** STM32CubeIDE
- **Language:** C
- **Framework:** STM32 HAL

## 2. Hardware Components

| Component | Description |
|---|---|
| DS18B20 | 온도 측정 |
| SSD1306 OLED | 목표 온도 및 동작 상태 표시 |
| 4-Digit FND | 현재 온도 표시 |
| Relay Module | 히터 ON/OFF 제어 |
| Push Buttons | 온도 설정 및 동작 제어 |

## 3. Communication Interfaces

| Interface | Application |
|---|---|
| 1-Wire | DS18B20 온도 측정 |
| I2C | SSD1306 OLED 제어 |
| SPI | 74HC595 기반 FND 구동 |
| UART + DMA | PC 온도 데이터 전송 |
| GPIO EXTI | 버튼 인터럽트 처리 |
| TIM | 센서 통신 타이밍 및 FND 제어 |

## 4. Main Features

### Temperature Measurement
- DS18B20을 이용한 온도 측정
- 1초 주기의 비차단 온도 측정 및 제어

### Heater Control
- 버튼을 통한 목표 온도 설정
- 히스테리시스 기반 릴레이 ON/OFF 제어

### Display Control
- I2C 기반 OLED 표시
- SPI 및 타이머 인터럽트를 이용한 FND 제어

### Button Control
- GPIO 외부 인터럽트 활용
- HAL_GetTick 기반 소프트웨어 디바운싱

### PC Monitoring
- UART DMA 기반 온도 데이터 전송
- Serial Studio를 통한 실시간 그래프 출력

## 5. Source Code

| File / Directory | Description |
|---|---|
| `Core/Src/` | 주요 기능 소스코드 |
| `Core/Inc/` | 헤더 파일 |
| `Heater_Project.ioc` | STM32CubeMX 주변장치 설정 |
| `STM32F103RBTX_FLASH.ld` | Flash 메모리 링커 스크립트 |

본 저장소는 주요 소스코드 열람을 목적으로 구성하였습니다.

## 6. Project Documentation

상세한 하드웨어 구성, 소프트웨어 구현 과정, 디버깅 및 검증 결과는 별도의 프로젝트 보고서에 정리하였습니다.

- Demonstration Video, Project Report: https://drive.google.com/drive/u/1/folders/1tGXdcP-ICqV1TjwLv2NqzWs-zy-YrHV5
