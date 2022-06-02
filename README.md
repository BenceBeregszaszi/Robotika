# Funkcionális specifikáció

------------------------------
## Fejlesztők:
- Pápai Kristóf Levente
- Beregszászi Bence
- Fejes Bence
- Erdélyi Roland
------------------------------

## Használt eszközök:

- Arduino Micro
- KY-015
- Eső szenzor FC-37
- lehúzó ellenálás 10KΩ
- Hangszóró
- RGB Led
- BMP180 Barometer
- 16x2 LCD I2C
- KY-040 Rotary Encoder

------------------------------
## Általános leírás

Időjárás figyelő eszköz. Hőmérsékletet, magasságot, légnyomást, páratartalmat, eső figyelés, fénymennyiséget figyel.

------------------------------

## Használati esetek

 - Rotary Encoder:
   - Gomb megnyomásával mérnek a szenzorok
   - gomb megnyomására az RGB LED pirosról Zöldre vált
   - a gomb megnyomására a hangszóró hangot ad ki, ki-be kapcsolás esetére.
   - Tekerésével különböző mérések kiírása a kijelzőre

 - Kijelző: Rotary Encoder tekerésének hatására => Mérési adatok megjelenítése
   - Az adott szenzorról olvasott értékek megjelítése

 - Barométer: Rotary Encoder tekerésének hatására => Mérési adatok megjelenítése
   - Légnyomás mérés

 - Tengerszint feletti magasság szenzor: Rotary Encoder tekerésének hatására => Mérési adatok megjelenítése
   - A szenzor megméri a tengerszint feletti magasságot 

 - Páratartalom szenzor és hőmérséklet szenzor: Rotary Encoder tekerésének hatására => Mérési adatok megjelenítése
   - Megméri a páratartalmat és a hőmérsékletet

 - Fény szenzor: Rotary Encoder tekerésének hatására => Mérési adatok megjelenítése
   - Megméri a fény mennyiségét

 - Led:
   - Zöld: Ha az eszköz bekapcsolt állapotban van
   - Piros: Ha az eszköz kikapcsolt állapotban van

## Állapot átmenet gráf

![allapotatmenet](https://imgur.com/jO8MS90.png)


## Terv

![terv](https://imgur.com/DgFtSfQ.png)


## Fogalomszótár

Rotary Encoder: Egy olyan eszköz amely hasonló a potméterhez, de a forgató kar egyben egy gomb is.

Barométer: Egy olyan eszköz amely légnyomás mérésére szolgál
