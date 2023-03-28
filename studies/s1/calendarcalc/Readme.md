# Aufgabe 05: Kalender-Berechnungen

In dieser Aufgabe soll ein Programm vervollständigt werden, das einige Kalender-Berechnungen durchführt. Ausgangspunkt ist ein vom Benutzer eingegebenes Datum. Die Funktionalität soll schrittweise realisiert werden, wobei jede einzelne Teilaufgabe einer Funktion in der Vorlage entspricht, die Sie vervollständigen sollen.

Vorbereitung:

1. Berechnen Sie, ob das Jahr des vom Benutzer eingegebenen Datums ein [Schaltjahr](https://de.wikipedia.org/wiki/Schaltjahr) ist (Funktion `isLeapYear`).

2. Prüfen Sie, ob ein korrektes Datum eingegeben wurde. Beachten Sie dabei auch die im ersten Teil ermittelte Information (Funktion `isValidDate`).

3. Geben Sie den Namen eines berechneten Wochentags aus (Funtion `printWeekday`).

in der Übung:

4. Geben Sie für den gegebenen Tag aus, der wievielte Tag des Jahres er ist (Funktion `determineDayInYear`).

5. Die bereits implementierte Funktion `determineWeekdayOfJan01` bestimmt den Wochentag des 1. Januars des gegebenen Jahres. (Zur Vereinfachung wurde davon ausgegangen, dass wir Jahre des 20. oder 21. Jahrhunderts haben, also zwischen 1901 und 2100.) Nutzen Sie die Rückgabe dieser Funktion, um den Wochentag des gegebenen Tags (Funktion `determineWeekday`) zu ermitteln.

6. Berechnen Sie in der Funktion `determineCalendarWeek`, in welcher [Kalenderwoche](https://de.wikipedia.org/wiki/Kalenderwoche) der gegebene Tag ist (nach ISO 8601).

Zusatz-Aufgabe für Fortgeschrittene:

7. Ermitteln Sie den Wochentag des gegebenen Tags, indem Sie die [allgemeingültige Formel](https://de.wikipedia.org/wiki/Wochentagsberechnung) implementieren. (Damit funktioniert die Berechnung auch für Jahre außerhalb der 20. oder 21. Jahrhunderts.) Passen Sie die Funktion `determineWeekday` bzw. `determineWeekdayOfJan01` entsprechend an.
