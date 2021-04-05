Autor: Michał Laskowski nr albumu: 310181

Użyte środowisko: VisualStudio

Opis:

Główne pliki:
    InvoiceApp:
        -InvoiceApp.cpp     -> zawiera prosty szkielet funkcji main, który służył mi m.in. do sprawdzenia działania operatorów wejścia i wyjścia
    InvoiceLib:
        Klasa Invoice: (Ta klasa jest głównym rozwiązaniem zadania Lab3, przyjmuje 3 parametry name, adress i items, z czego ostatni jest opcjonalny)
        -InvoiceClass.h     -> zawiera nagłówek klasy Invoice, razem z komentarzami do każdej z metod
        -InvoiceClass.cpp   -> zawiera definicje konstruktora, metod oraz operatorów klasy Invoice
        Klasa Item: (Ta klasa jest dodatkowa i służy możliwości dalszego rozwijania projektu, dzięki niej lista przedmiotów przetrzymuje nie tylko nazwę przedmiotu, ale cały obiekt klasy Item)
        -ItemClass.h        -> zawiera nagłówek klasy Item, razem z komentarzami do metod
        -ItemClass.cpp      -> zawiera definicje konstruktora, metod oraz operatorów klasy Item

Sposób testowania:
    InvoiceUnitTest:
        -InvoiceUnitTest.cpp-> zawiera łącznie 36 testów jednostkowych sprawdzających działanie wszystkich metod i operatorów klasy Invoice oraz funkcję umożliwiającą porównanie dwóch wektorów
