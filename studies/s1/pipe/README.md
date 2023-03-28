# Aufgabe 11 - Durch die Pipe

In dieser Übung sollen einfache Varianten mehrerer praktischer Kommandozeilen-Tools entwickelt werden, die standardmäßig auf jedem UNIX-System vorhanden sind. Die Programme ([kurze Beschreibung](https://www.linux-praxis.de/unix-texttools)) lesen jeweils Text von der Standardeingabe oder aus Dateien.

Während jedes einzelne Tool keinen großen Funktionsumfang besitzt, sind sie doch im Zusammenspiel sehr mächtig. Dazu kann man diese mit Hilfe einer sogenannten [Pipe](https://de.wikipedia.org/wiki/Pipeline_(Unix)) ``tool1 | tool2`` kombinieren. Alles, was der erste Tool über die Standardausgabe ausgibt, liest das zweite Tool über die Standardeingabe ein. Damit können viele Bausteine zu einer langen Kette verknüpft werden.

In der Vorlage bereits ist das Tool **cat** vorhanen. Es gibt einfach die übergebenen Dateien auf der Standardausgabe aus. Sie können dieses Beispiel als Ausgangspunkt für die weiteren Tools verwenden. Ihre Tools müssen nicht mit Kommandozeilen-Parametern umgehen, außer **cut**, das eine auszuschneidende Spalte (eine Zahl) und einen String mit Trennzeichen als Parameter unterstützen soll (Ansonsten wäre es unbrauchbar).

Testen Sie Ihre Programme mit der gegebenen Beispieldatei (Liste der Einwohner der deutschen Landkreise). Wenn Sie alle Tools implementiert haben, können Sie z.B: die folgenden Befehlsketten ausführen.

```
cat population.csv | grep "kreisfreie Stadt" | cut -d ";" -f 2 | wc -l
head population.csv | sort | nl
```

*Tipp*: Wenn Sie innerhalb CLion entwickeln, können Sie zwischen den Tools in der Symbolleiste umschalten (zwischen dem Hammer und dem Pfeil) oder alle mit **Build** -> **Build All** erstellen.

Vorbereitung:

1. Implementieren Sie das Tool [**head**](https://de.wikipedia.org/wiki/Head_(Unix)), das die ersten 10 Zeilen einer Datei ausgibt.

2. Implementierung Sie das Tool [**nl**](https://en.wikipedia.org/wiki/Nl_(Unix)), das die Zeilen der Datei mit vorangestellen Zeilennummern versieht.

in der Übung:

3. Implementieren Sie das Tool [**wc**](https://de.wikipedia.org/wiki/Wc_(Unix)), das die Zeichen, Wörter und Zeilen einer Datei zählt.

4. Implementieren Sie das Tool [**grep**](https://de.wikipedia.org/wiki/Grep), das nur die Zeilen ausgibt, die das gegebene Wort enthalten.

5. Implementieren Sie das Tool [**cut**](https://de.wikipedia.org/wiki/Cut_(Unix)), das eine gegebene Spalte in jeder Zeile extrahiert.

6. Implementieren Sie das Tool [**sort**](https://de.wikipedia.org/wiki/Sort_(Unix)), das die Zeilen einer Datei sortiert.

Zusatz-Aufgaben für Fortgeschrittene:

7. Implementieren Sie das Tool [**tail**](https://de.wikipedia.org/wiki/Tail_(Unix)), das die letzten 10 Zeilen einer Datei ausgibt.

8. Implementieren Sie das Tool [**join**](https://de.wikipedia.org/wiki/Join_(Unix)), das Tabellen in verschiedenen Dateien verbindet.
