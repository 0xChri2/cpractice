# Aufgabe 12 - Sokoban

In dieser Übung sollen einfache Version des Spiele-Klassikers [Sokoban](https://de.wikipedia.org/wiki/Sokoban) realisiert werden. Das Computerspiel wurde von Hiroyuki Imabayashi entwickelt und 1982 erstmals für verschiedene Computersysteme veröffentlicht. Es hat ein einfaches Spielprinzip: Ziel ist es, mit einer Spielfigur alle Kisten auf die dafür vorgesehenen Zielfelder zu bewegen. Die Kisten können von der Spielfigur nur geschoben und nicht gezogen werden. Ein Verschieben mehrerer Kisten zugleich ist nicht möglich.

Die Vorlage enthält bereits eine Version, in der der größte Teil der Funktionalität realisiert ist. Nach dem Starten des Programm sollte es möglich sein, die Figur mit den Tasten `w`, `a`, `s` und `d` zu bewegen und mit `q` wird das Spiel beendet.

*Tipp*: Beim Ausführen innerhalb von CLion müssen Sie nach jedem Befehl die Eingabetaste drücken. Wenn Sie die ausführbare Datei *Sokoban* bzw. *Sokoban.exe* aus dem *cmake-build-debug* direkt in der Konsole ausführen, reicht ein einfacher Tastendruck aus.

Viele Sokoban-Implementierungen verwenden zur [Beschreibung der Levels](http://sokobano.de/wiki/index.php?title=Level_format) ein einfaches ASCII-Format, welches den Austausch zwischen den verschiedenen Implementierungen erleichtert. Zur Erstellung von eigenen Levels kann dabei jeder beliebige Texteditor verwendet werden. Ein Beispiellevel sieht folgendermaßen aus:

```
    #####
    #   #
    #   #
  ###   ##
  #      #
### # ## #   ######
#   # ## #####    #
# $  $           .#
#####$### #@##  ..#
    #     #########
    #######
; Title: Simple #1
```

Dabei haben die Symbole folgende Bedeutung:

- `#` Wand
- `@` Startposition der Spielfigur (Sokoban)
- `$` Kiste auf normalem Spielfeld
- `.` Leeres Zielfeld für Kisten
- `*` Kiste auf einem Zielfeld
- `+` Spielfigur auf einem Zielfeld


Vorbereitung:

1. Machen Sie sich mit dem Spielprinzip vertraut, indem Sie zum Beispiel ein Level dieser [Online-Variante](http://www.game-sokoban.com) durchspielen.  Machen Sie sich anschließend mit der Vorlage vertraut und testen Sie deren momentane Funktionalität. Es sollte möglich sein, die Figur innerhalb des Spielfelds zu bwegen, o

2. In der momentanen Version des Spiels kann sich die Spielfigur zwar bewegen, aber das Schieben der Kisten ist noch nicht möglich. Erweitern Sie die Funktionen `move_up`, `move_down`, `move_left` und `move_right` so, dass auch ein Schieben der Kisten möglich ist.

   
in der Übung:

3. Fassen Sie die Funktionen `move_up`, `move_down`, `move_left` und `move_right` zu einer einzigen Funktion `move` zusammen, die zwei zusätzliche `int`-Parameter `dx` und `dy` hat, die die Bewegungsrichtung angeben:

   - links: `dx`=-1 und `dy`=0
   - rechts: `dx`=1 und `dy`=0
   - oben: `dx`=0 und `dy`=-1
   - unten: `dx`=0 und `dy`=1
   
4. Die Funktion `all_boxes_on_target` soll implementiert werden, damit das Erreichen des Level-Ziels auch festgestellt wird. Die Funktion soll 1 zurückgeben, wenn alle Kisten auf Zielfeldern stehen (andernfalls 0).

5. Vervollständigen Sie die Funktion `read_board` zum Einlesen eines Levels aus einer Datei. Die gegebene Version kann noch nicht damit umgehen, dass Kisten oder Spielfigur zu Beginn auf Zielfeldern stehen. Testen Sie Ihre Implementierung mit Level 15 aus *Original.txt* (Dateinamen in der `main`-Funktion ändern). 

6. Lagern Sie die Funktion `get_keypress` in eine separate Quelltext-Datei *keypress.c* (mit dazugehörigem Header) aus. Lagern Sie die Funktionen `read_board` und `read_boards` in eine separate Quelltext-Datei *board.c* aus.

Zusatz-Aufgabe für Fortgeschrittene:

7. Implementieren Sie die Funktionalität, dass die gemachten Züge abgespeichert werden und beim Erreichen des Level-Ziels ausgegeben werden ([Solution-Format](http://sokobano.de/wiki/index.php?title=Solution_format)).

8. Realisieren Sie auf dieser Basis eine *Undo*-Funktion, mit der ein (oder auch mehrere) Züge zurückgenommen werden können.
