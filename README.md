# Ventilátorvezérlő rendszer PWM szabályozással

Arduino-alapú rendszer, amely a TMP36 hőmérséklet-érzékelő által mért hőmérséklet alapján PWM-vezérléssel automatikusan szabályozza a ventilátor fordulatszámát.

## Felhasznált alkatrészek

- Arduino Uno R3
- TMP36 hőmérséklet-érzékelő
- 16x2 LCD kijelző
- DC motor / ventilátor
- NPN tranzisztor
- Ellenállások
- Forrasztás nélküli prototípus panel
- Vezetékek

## Működés

Alacsony hőmérséklet esetén a ventilátor kikapcsolva marad. Közepes hőmérsékleti tartományban a PWM érték fokozatosan növekszik, így a ventilátor fordulatszáma is emelkedik. Magas hőmérséklet esetén a ventilátor maximális fordulatszámon működik.

## Fájlok

- `pwm_venti1.ino` – Arduino programkód
- `PWM Ventilator.png` – kapcsolási ábra
- `PWM Venti.brd` – kapcsolási fájl
- `digit-ihxd6u-dokumentacio.docx` – projekt dokumentáció
