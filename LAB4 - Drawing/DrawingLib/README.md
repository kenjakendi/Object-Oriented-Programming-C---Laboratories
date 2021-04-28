Autor: Michał Laskowski nr albumu: 310181

Użyte środowisko: VisualStudio

Główne projekty:
1.Drawing -> biblioteka statyczna zawierająca klasy i nagłówki klas
2.DrawingApp -> aplikacja konsoli która może wykorzystywać klasy z biblioteki
3.DrawingUnitTest -> testy jednostkowe klasy Drawing

1:
-Circle, Rectangle i Line:
    Klasy dziedziczące po klasie abstrakcyjnej IFigure, zawierają swoje parametry potrzebne do  zapisu svg oraz parametr oznaczający kolejność w jakiej będą sortowane przez iterator. Posiadają również metody zwracające tekst svg lub id w postaci numeru i opisującego tekstu. Dziedziczą również operator wyjścia.

-Drawing:
    Jest to klasa zawierająca wektor wspomnianych figur Przyjmuje parametry nazwy, wysokości i szerokości svg oraz wektora figur. W konstruktorze wektor domyślnie przyjmuje wektor pusty. klasa zawiera settery i gettery do każdego parametru oraz zawiera publiczne metody svgText-zwracający tekst pliku svg, saveSvg-zapisuje tekst svg do pliku, clearLog-czyści zapisane zmiany.Zawiera również prywatne metody getTime-zwraca aktualny czas systemu (potrzebne do zapisania zmian w logu), saveChange-Zapisuje zadany komunikat do pliku log razem z czasem zmiany.

-MyIterator:
    Plik z klasą zawierającą schemat kolekcji figur oraz iteratora który ma za zadanie brać pokolei figury, gdzie kolejność jest określona przez parametr w ich klasach. Zawiera operatory ++, *, != oraz metodę zwracającą największą wartość parametru figur z kolekcji. A klasa FigureCollection zawiera metody myBegin i myEnd.

2:
DrawingApp zawiera krótkie linie kodu sprawdzające działanie operatorów wyjścia oraz dzaiłąnie iteratora.

3:
DrawingUnitTest zawiera testy jednostkowe sprawdzające najważneijsze metody klasy drawing(konstruktor, settery, gettery, metody zwracające tekst svg), a zarazem też konstruktory klas figur.
