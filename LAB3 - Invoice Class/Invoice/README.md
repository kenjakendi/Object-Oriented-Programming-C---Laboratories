Autor: Michał Laskowski nr albumu: 310181

Użyte środowisko: VisualStudio

Opis:

Główne pliki:
    InvoiceApp:
        -InvoiceApp.cpp     -> zawiera prosty szkielet funkcji main, który służył mi m.in. do sprawdzenia działania operatorów wejścia i wyjścia
    InvoiceLib:
        -InvoiceClass.h     -> zawiera nagłówek klasy Invoice, razem z komentarzami do każdej z metod
        -InvoiceClass.cpp   -> zawiera definicje konstruktora, metod oraz operatorów klasy Invoice
        -ItemClass.h        -> zawiera nagłówek klasy Item, razem z komentarzami do metod
        -ItemClass.cpp      -> zawiera definicje konstruktora, metod oraz operatorów klasy Item

Sposób testowania:
    InvoiceUnitTest:
        -InvoiceUnitTest.cpp-> zawiera łącznie 36 testów jednostkowych sprawdzających działanie wszystkich metod i operatorów klasy Invoice oraz funkcję umożliwiającą porównanie dwóch wektorów
