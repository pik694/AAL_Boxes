# Ortodoksyjny kolekcjoner kartonów
### Autor : Piotr Żelazko 277373 PW 2018
### Program rozwiązuje problem ortodoksyjnego kolekcjonera tekturowych kartonów.

## Uruchamianie
Opcje uruchomienia (poniżej pomoc wyświetlona poprzez uruchomienie programu z opcją -h (--help)) :
```
Allowed options:
  -h [ --help ]               Show this help message
  -i [ --in ] arg             Specify path to the input file
  -o [ --out ] arg            Specify path to the output file
  -m [ --mode ] arg           Choose execution mode (look size option):
                              0 - generate problem,
                              1 - generate and solve,
                              2 - solve given problem
                              
  -s [ --size ] arg           Specifies generated problem size
  -a [ --algorithm ] arg (=0) Select algorithm:
                              0 - brut force(default),
                              1 - max volume first
```
## Dane
Dane wejściowe składają się z :
	- liczby n, określającej ilość kartonów (wielkość problemu)
	- n-linii, a w każdej z nich trzy liczby naturalne określające wymiary danego kartonu;

Dane wyjściowe składają się z :
- ciąg liczb, określających permutację kartonów, będącą odpowiedzią;
- dwie liczby oddzielone "->", pierwsza z nich oznacza początkową objętość,
  a druga oznacza objętość zajętą przez kartony po upakowaniu;
  
## Algorytmy
Na rozwiązanie składają się 3 algorytmy:
- pierwszy z nich to algorytm typu brute-force - sprawdza wszystkie
  możliwe upakowania i wybiera najlepsze;
- kolejny jest usprawnieniem powyższego, analizuje sytuacje,
  w których podjęcie decyzji jest proste, zmniejszając tym 
  samym wielkość problemu przekazaną do algorytmu brut-force;
- trzeci algorytm jest heurystyką, wykorzystującą zbudowany 
  graf opisany w dokumentacji, nie rozwiązuje on pewnej klasy podproblemów,
  na dużym zbiorze testowym, popełnia błędy w ok 10% przypadków.

## Moduły
Program został podzielony na moduły zajmujące się odpowiednio:
- dostarczeniem danych (wczytanie oraz generacja)
- wypisaniem wyniku programu
- sterowaniem wykonania programu
- rozwiązaniem problemu algorytmicznego
## Uwagi
W przypadku metody brut-force program nie potrafi rozwiązać w rozsądnym czasie problemu o wielkości n = 14.
