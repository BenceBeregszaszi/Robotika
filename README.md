# Funkcionális specifikáció

------------------------------
## Fejlesztők:
- Pápai Kristóf Levente
- Beregszászi Bence
- Fejes Bence
- Erdélyi Roland
------------------------------

## Áttekintés

## Jelenlegi helyzet

A megrendelőn egy olyan multifunkcionális eszközt szeretne amivel egyszerűen tud mérni különböző adatokat az időjárásról.

## Követelménylista

## Jelenlegi üzleti folyamatok modellje

## Igényelt üzleti folyamatok modellje

## Használati esetek

 - Rotary Encoder:
   - Gomb megnyomásával mérnek a szenzorok
   - Tekerésévle különböző mérések kiírása a kijelzőre

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

 - Hangszóró: Rotary Encoder tekerésének hatására => Mérési adatok megjelenítése
   - Ha a mért értékek magasak akkor sípoló hangot ad ki

 - Led:
   - Zöld: Ha a mérések megfelelőek akkor Zöld fény villog
   - Sárga: Ha a mérési eredmények kicsivel rosszabbak mint a megfelelőek akkor sárgán villog
   - Piros: Ha a mérési eredmények rosszak akkor piros fény villog
 
## Terv

![terv](https://imgur.com/DgFtSfQ.png)


## Fogalomszótár

Rotary Encoder: Egy olyan eszköz amely hasonló a potméterhez, de a forgató kar egyben egy gomb is.

Barométer: Egy olyan eszköz amely légnyomás mérésére szolgál
