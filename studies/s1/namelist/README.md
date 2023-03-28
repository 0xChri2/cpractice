# Aufgabe 09 - Namensliste

In dieser Übung soll der Umgang mit Strings und dynamischer Speicherreservierung geübt werden.

Datengrundlage dieser Aufgabe ist eine Datei mit einer Liste von Nachmamen, die nach einer Volkszählung 2010 in den USA erstellt wurde. In dieser stehen die häufigsten Namen - jeweils einer pro Zeile - geordnet nach der Häufigkeit in der Bevölkerung. (Um die Entwicklung zu vereinfachen, gibt es auch eine verkürzte Version mit den 20 häufigsten Nachnamen (siehe unten), die für erste Tests genutzt werden kann.)

Die gegebene Vorlage gibt bereits die Grundstruktur des Programms vor. Zunächst werden über die Standardeingabe Namen für die Namensliste gelesen. Garcia ist z.B. der 6-häufigste Name, der 1,1 Mio mal gezählt wurde (siehe unten). In der Datei sind immer alle Nachnamen in Großbuchstaben und ohne Leerzeichen. Die Namenseingabe wird durch einen speziellen End-Eintrag abgeschlossen.

Danach werden die ersten zehn eingelesenen Einträge ausgeben, anschließend die Häufigkeit verschiedener Namen, die Liste anschließend entsprechend der Häufigkeit sortiert und nochmals die ersten zehn Einträge ausgegeben.

Im Programm wird jeder Eintrag der Liste in eine Struktur des Typs ``entry_t`` abgespeichert. Die gesamte Liste ist ein Array von solchen Einträgen ``name_list``. Dabei gibt ``list_capacity`` an, für wieviel Einträge momentan Speicher reserviert wurde und ``list_length``, wie viele Einträge sie momentan enthält (sollte kleiner oder gleich ``list_capacity`` sein).

Vorbereitung:

1. Implementieren Sie zunächst die Funktion ``append_entry``, die einen Eintrag mit gegebenen Daten der Liste hinzufügt. Wenn die Funktion korrekt implementiert ist, funktioniert das Einlesen der Liste mit ``read_entries`` und die Ausgabe mit ``print_list``.

2. Implementieren Sie die funktion ``find_entry``, so dass der entsprechende Eintrag für einen gegebenen Namen gefunden wird. Wenn diese Funktion realisiert ist, sollten Sie die richtige Ausgabe für die Namen ``GARCIA``und ``XILOL`` aus dem Programmbeispiel erhalten.

in der Übung:

3. Erweitern Sie die Funktion ``find_entry`` derart, dass Namen gefunden werden, auch wenn sie nicht komplett in Großbuchstaben geschrieben sind (z.B. ``Thomas`` und ``Snyder`` im Programmbeispiel).

4. Sortieren Sie die Liste nach dem Einlesen (nach der Häufigkeit des Nachnamens), indem Sie die Funktion ``compare_occ`` implementieren.

5. Erweitern Sie Ihr Programm, so dass nun auch die große Version der Namensliste eingelesen werden kann. Stellen Sie dazu das Array mit fester Länge auf eines mit variabler Länge um (auf dem Heap). Sollte die Kapazität der Liste zur Aufnahme des neuen Elements nicht ausreichen, soll diese um die Hälfte verlängert werden (mit Aktualisierung der Speicheranforderung). Prüfen Sie, ob Sie immer nur auf wirklich reservierten Speicher zugreifen (kein Pufferüberlauf beim Array-Zugriff) und ob Sie den reservierten Speicher auch wieder freigeben.

Zusatz-Aufgabe für Fortgeschrittene:

6. Implementieren Sie die Funktion ``find_entry`` mit Hilfe der [binären Suche](https://de.wikipedia.org/wiki/Binäre_Suche).

Ausgabe für die *lange* Namensliste:

```
     1 AABERG                 469
     2 AABY                   220
     3 AADLAND                374
     4 AAFEDT                 138
     5 AAGAARD                300
     6 AAGARD                 347
     7 AAGESEN                177
     8 AAKER                  358
     9 AAKHUS                 134
    10 AAKRE                  371
Der Name GARCIA existiert insgesamt 1166120 mal.
Der Name Thomas existiert insgesamt 756142 mal.
Der Name Snyder existiert insgesamt 160262 mal.
Der Name XILOL steht nicht in der Liste.
     1 SMITH              2442977
     2 JOHNSON            1932812
     3 WILLIAMS           1625252
     4 BROWN              1437026
     5 JONES              1425470
     6 GARCIA             1166120
     7 MILLER             1161437
     8 DAVIS              1116357
     9 RODRIGUEZ          1094924
    10 MARTINEZ           1060159

```