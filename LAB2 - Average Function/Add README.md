Autor: Michał Laskowski nr albumu: 310282

Użyte środowisko: VisualStudio

Opis:

Główne pliki:
    AverageLib:
        -AverageLib.cpp     ->  Zawiera dwie główne funkcje: average i count_inner_sum
                                1. Average tworzy główny szkielet, przechodzi po kązdym elemecie w tablicy dwuwymiarowej.
                                   Później wywołuje funkcje count_inner_sum i sprawdza czy ta suma wewnętrzna elementu jest parzysta.
                                   Jeżeli tak to dodaje element do głównej sumy, a także liczy ilość kwalifikujących się elementów.
                                   Na końcu oblicza i zwraca średnią wybranych elementów. 
                                   (Jeżeli tablica jest pusta, albo jej elementy nie spełniają warunków, funkcja zwraca 0)
                                2. Count_inner_sum pobiera element z tablicy w formie stringa. 
                                   Oblicza sumę cyfr na pozycjach parzystch i zwraca ją.
        -AverageLib.h       ->  Zawiera nagłówki funkcji

Sposób testowania:
    AverageUnitTest:
        -AverageUnitTest.cpp->  Zawiera testy jednostkowe dla funkcji
                                1. 4 testy dla funkcji average sprawdzające ją przy:
                                        -normalnych wartościach
                                        -pustej tablicy
                                        -braku kwalifikujących się elementów
                                        -innej wielkości tablicy
                                2. 3 testy dla funkcji count_inner_sum sprawdzające ją:
                                        -kiedy suma wychodzi parzysta
                                        -kiedy suma wychodzi nieparzysta
                                        -kiedy obliczany element jest cyfrą
