# Aufgabe 06: ASCII-Grafik

Zur grafischen Darstellung von Funktionen soll eine Reihe von Funktionen erstellt werden. Um diese voll portabel zu halten, soll nur Standard-C benutzt werden und zur Darstellung lediglich ASCII-Zeichen genutzt werden.

Grundprinzip: Die gegebene Vorlage enthält bereits das Grundgerüst für die gewünschte Bibliothek: Der Bildschirminhalt wird in einem zweidimensionalen Array `char screen[NUM_COLUMNS][NUM_ROWS]` zunächst gespeichert, der mit den zu entwickelnden Funktionen geändert wird. Dabei muss `NUM_COLUMNS` auf die Breite des Konsolenfensters und NUM_ROWS auf die Höhe des Konsolenfesters gesetzt werden. Durch Aufruf von `update_screen()` wird dann der Inhalt dieses Arrays ausgegeben, wobei der obere linke Punkt die Koordinaten (0,0) und der untere rechte Punkt die Koordinaten (`NUM_COLUMNS`-1, `NUM_ROWS`-1) hat. (Beachten Sie, dass die y-Achse in der Computergrafik normalerweise entgegen der in der Mathematik üblichen Weise nach unten zeigt.)

Vorbereitung:

1. Schauen Sie sich die gegebene Vorlage an, in der die grundlegende Ansteuerung bereits implementiert ist. Dies ist die Voraussetzung für die weiteren Aufgaben, in denen Funktionen zum Schreiben des Arrays `screen` realisiert werden.

2. Implementieren Sie eine Funktion `in_screen()`, die für einen gegebenen Punkt bestimmt, ob sich dieser im Bildschirm befindet.

3. Nutzen Sie diese Funktion bei der Implementierung von `draw_pixel()` zum Setzen eines einzigen Pixels mit gegebenem Zeichen und `clear_pixel()` zum Löschen. Prüfen Sie jetzt - und bei allen folgenden Teilaufgaben - jeweils anhand der unten gegebenen Ausgabe die Korrektheit Ihrer Funktion.

4. Implementieren Sie zwei Funktionen `draw_horizontal_line()` und `draw_vertical_line()` zum Zeichen von horizontalen und vertikalen Linien. Damit sollten dann auch die Funktionen `draw_horizontal_arrow()` und `draw_vertical_arrow()` funktionieren.

in der Übung:

5. Implementieren Sie die Funktion `draw_rectangle()` zum Zeichen von Rechtecken (ohne Füllung).

6. Implementieren Sie ein Funktion `draw_filled_rectangle()` zum Zeichnen von Rechtecken mit Füllung.

7. Implementieren Sie eine Funktion `draw_line()`, die eine Linie mit zwei beliebigen Endpunkten zeichnet. *Tipp*: Versuchen Sie, durch das Zeichnen von hinreichend vielen Punkten eine Linie zu zeichnen. Wenn man zum Beispiel eine Linie zwischen (4,2) und (20,10) mit 5 Punkten zeichnet, sollten die Punkte (4,2), (8,4), (12,6), (16,8) und (20,10) gesetzt werden. Sie können diese [einfache Methode](https://de.wikipedia.org/wiki/Rasterung_von_Linien) hier nachlesen.

Zusatz-Aufgaben für Fortgeschrittene:

8. Implementieren Sie eine Funktion `draw_line()` mit Hilfe des [Bresenham-Algorithmus](https://de.wikipedia.org/wiki/Bresenham-Algorithmus).

9. Implementieren Sie eine Funktion `flood_fill()`, die eine begrenzte Fläche füllt. Die Füllung soll alle Leerzeichen überschreiben, bis eine Abgrenzung (Linie und Bildschirmrand) erreicht ist.

```
------------------------------------------------------------------------------->
|..........................................................................***  
|........................+------------------------------------------+..****     
|..#####.................|                                          ***         
|..#####.................|                                       ***|           
|........................|                                   ****   |           
|........................|                                ***       |           
|........................|                             ***          |           
|.......+++..............+--------------------------***-------------+           
|..........+++++................................****                            
|...............++++++........1..............***                                
|.....................+++++...............***                                   
|..........................+++++......****                                      
|...............................++++++                                          
|...............................***   +++++                                     
|...................2.......****           +++                                  
|........................***                                                    
|.....................***                                                       
|..................***                                                          
|..............****                                                             
|...........***                                                            3    
|........***                                                                    
|....****                                                                       
|.***                                   <---------------------------------------
v*                                                                              
```