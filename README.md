# Touch-emAll
gra zręcznościowa

## Instrukcja

**Witaj użytkowniku!**
W tej grze przegrywasz, gdy czarny prostokąt dojedzie do końca planszy.
Odznacz je wszystkie za pomocą myszki. Z czasem będzie coraz trudniej. 
Zbieraj bonusy!
- **CZERWONY** daje Ci dodatkowe życie,
- **ZIELONY** chwilowo przyśpiesza grę,
- **NIEBIESKI** spowalnia, 
- **FIOLETOWY** daje Ci 'bombę', którą zdetonować możesz spacją. 
Po prawej stronie planszy znajduje się pas doświadczenia. Nie pozwól, by załadował się cały.
Wtedy gra dramatycznie przyśpieszy!
Aby tego uniknąć, odpowiednio wczesnie zdetonuj bombę (to rozładuje pas oraz chwilowo spowolni grę).
**Postaraj się przetrwać jak najdłużej. 
POWODZENIA!**

### Kompilacja i uruchomienie 
$ g++ -o TouchEmAll main.cpp -lGL -lGLU -lglut gra.cpp plansza.cpp prostokat.cpp
$ ./TouchEmAll