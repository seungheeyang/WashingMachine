# Washing Machine Project

### 프로젝트 개요
---------------
14/09/2022 - washingMachine 2.1.1 project is updated. Detail here.

1. 승인 카드 입력 -> 세탁기 Mode 선택

2. Mode 선택
    - 자동모드 : 세탁, 헹굼, 탈수 각각 1회씩 동작 후 종료
    - 수동모드 : 기능 선택 후 동작 -> 동작 후 종료
    - Reset
  
3. 기능
    - 세탁 : 세제 투입 (Servo Motor 작동) -> 정회전, 역회전 (DC Motor 작동)
    - 헹굼 : 물 투입 (LED 대체 표시) -> 정회전, 역회전 (DC Motor 작동) -> 물 빠짐
    - 탈수 : 정회전, 역회전 (DC Motor 작동)
  
4. 추가기능
    - 문 열림 감지 -> 일시정지
    
### Setup
---------
1. Order parts from the bill of materials
    - ATmega128A
    - LED: PA2 ~ PA6
    - Button : PF0 ~ PF5
    - I2C LCD : PD0, PD1
    - DC Motor(L298N) : PA0, PA1, PE3
    - Servo Motor : PE4
    - Buzzer : PB5
    - RFID: PB0 ~ PB3

2. Follow the hardware setup
3. Follow the software setup
4. Run through the examples
