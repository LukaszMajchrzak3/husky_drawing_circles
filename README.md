# husky_drawing_circles

## Opis paczki
Niniejsza paczka pozwala na sterowanie platformą Husky (A200) na podstawie symulacji dostarczonej przez Clearpath Robotics (https://docs.clearpathrobotics.com/docs/ros/). Możliwe jest nie tylko kręcenie "bączków", ale również jazda do przodu, z lekkim skrętem itd. Definiuje to użytkownik. 

## Jak zainstalować paczkę
1. W swoim workspace'ie utwórz nowe repozytorium np. używając polecenie: ros2 pkg create --build-type ament_cmake --license Apache-2.0 drawing_circles (najlepiej jakby nazwa paczki wyglądała właśnie w ten sposób).
2. Pobierz pliki z repozytorium
3. W twoim workspace'ie, w folderze src zamień folder z nazwą paczki "drawing_circles" na ten z repozytorium.
4. Spróbuj zbudować paczkę w terminalu. Jeśli paczka nie chce się zbudować, powtórz wszystkie czynności jeszcze raz.
5. Z poziomu workspace'a wejdź do następującej lokalizacji: /install/drawing_circles/share/drawing_circles. Następnie przenieś do tejże lokalizacji folder launch.
6. Mając otwartą symulację, po odpowiednim ponownym zbudowaniu paczki i użyciu komendy source, można uruchomić zainstalowaną paczkę. Uczynić to można za pomocą dwóch komend: ros2 launch drawing_circles launch_drawing_circles.launch.py my_parameter:=2.0 ang_velocity:=2.0 run_the_code:=true  lub   ros2 run drawing_circles dr_circles_node --ros-args -p my_parameter:=2.0 -p ang_velocity:=2.0 -p run_the_code:=true . Parametry my_parameter oraz ang_velocity służą do ustalania odpowiednio prędkości liniowej oraz prędkośći kątowej platformy.
