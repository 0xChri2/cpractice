# Aufgabe 07: Widerstandsreihen

Aus fertigungstechnischen Gründen stellt man Widerstände unterschiedlicher Nennwerte nicht gleichmäßig verteilt her, sondern nach einer geometrischen Reihe. Diese Reihen heißen [E-Reihen](https://de.wikipedia.org/wiki/E-Reihe) und werden mit E6, E12, E24, E48, E96, E192 bezeichnet. E6 bedeutet, dass in einer Dekade (also z.B. von 100 Ohm und 1000 Ohm) jeweils sechs Werte liegen. Dabei unterscheiden sich aufeinanderfolgende Werte immer jeweils durch einen konstanten Faktor.

Die Widerstandswerte sind immer mit Toleranzen verbunden, die  beispielsweise bei der Fertigung entstehen. Die verschiedenen E-Reihen haben dabei die folgenden Toleranzen:

- E6 bedeutet ± 20 %
- E12 bedeutet ± 10 %
- E24 bedeutet ± 5 %
- E48 bedeutet ± 2 %
- E96 bedeutet ± 1 %
- E192 bedeutet ± 0,5%

Der Hersteller garantiert, dass beispielsweise ein Widerstandswert aus der E12-Reihe eine maximale Abweichung von ± 10% vom Nennwert hat.

In dieser Aufgabe soll ein Programm entworfen werden, das zunächst für eine gegebene E-Reihe und Dekade die Widerstände wie in angehängter Tabelle angegeben, errechnet und ausgibt.

Vorbereitung:

1. Informationen zu den Toleranzen und die Berechnung der verschiedenen Nennwerte einer E-Reihe finden Sie in  [diesem Wikipedia-Artikel](https://de.wikipedia.org/wiki/E-Reihe). Lesen Sie sich die betreffenden Abschnitte durch, bevor Sie die beiden folgenden Teilaufgaben bearbeiten.

2. Arbeiten Sie sich in die gegebene Vorlage ein und klären Sie, welche Ein- und Ausgaben die verschiedenen Funktionen haben. Realisieren Sie anschließend die Berechnung der Toleranz in der Funktion `compute_tolerance()`.

3. Implementieren Sie die Funktion `compute_set_values()`, die für eine gegebene E-Reihe und eine Dekade die betreffenden Nennwerte berechnet. Hierbei werden Ihnen die Funktionen der [Mathe-Bibliothek](https://de.wikipedia.org/wiki/Math.h) hilfreich sein.

in der Übung:

4. Die Nennwerte von Widerständen werden durch [Farbringe auf dem Widerstandskörper](https://www.elektronik-kompendium.de/sites/bau/1109051.htm) gekennzeichnet. Erweitern Sie das Programm, so dass dessen Nennwert (im 5-Ring-Format) ausgegeben wird. Verwenden Sie in dieser Aufgabe für den letzten Ring der Beschriftung den Toleranzwert der E-Reihe (siehe Aufgabe 3).

Zusatz-Aufgabe für Fortgeschrittene:

5. Schreiben Sie ein zweites Programm, das zur Beschriftung von produzierten Widerständen eingesetzt werden kann. Nach Eingabe des jeweiligen Wertebereichs eines Widerstands (untere und obere Grenze), soll ihr Programm eine passende Farbcodierung vorschlagen. Dazu muss eine E-Reihe gewählt werden, die es ermöglicht, dass der Nennwert im gegebenen Bereich liegt und der Toleranzbereich der E-Reihe den gegebenen Bereich vollständig abdeckt. *Beispiel*: Bei Eingabe von unterer Grenze 610 Ohm und oberer Grenze 630 Ohm, soll die Beschriftung blau-braun-weiß-schwarz-rot vorgeschlagen werden (619 Ohm ± 2 % = 607-631 Ohm). 

```
E-Reihe: 12
Dekadenfaktor: 3
1000.00 braun-schwarz-schwarz-braun-silber (900.00 - 1100.00)
1211.53 braun-rot-braun-braun-silber (1090.37 - 1332.68)
1467.80 braun-gelb-blau-braun-silber (1321.02 - 1614.58)
1778.28 braun-violett-violett-braun-silber (1600.45 - 1956.11)
2154.43 rot-braun-gruen-braun-silber (1938.99 - 2369.88)
2610.16 rot-blau-braun-braun-silber (2349.14 - 2871.17)
3162.28 orange-braun-blau-braun-silber (2846.05 - 3478.51)
3831.19 orange-grau-orange-braun-silber (3448.07 - 4214.31)
4641.59 gelb-blau-gelb-braun-silber (4177.43 - 5105.75)
5623.41 gruen-blau-rot-braun-silber (5061.07 - 6185.75)
6812.92 blau-grau-braun-braun-silber (6131.63 - 7494.21)
8254.04 grau-rot-gruen-braun-silber (7428.64 - 9079.45)
```