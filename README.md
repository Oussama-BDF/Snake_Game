# Snake_Game
Un jeu du serpent classique réalisé en C++ et la bibliothèque SFML

### Pour compiler et exécuter le projet, utilisez simplement ces lignes dans votre terminal :
#### g++ -c .\main.cpp .\Board.cpp .\Food.cpp .\Snake.cpp .\GameLogic.cpp -I<the path of the SFML>/include -DSFML_STATIC -I<the path of the workspace folder>/include
  
#### g++ .\main.o .\Board.o .\Food.o .\Snake.o .\GameLogic.o -o mySG -L<the path of the SFML>/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32
  
#### .\mySG.exe
