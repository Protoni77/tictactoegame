echo "==Budowanie Projektu=="

echo "Kompilacja Javy za pomoca Maven"
mvn clean compile

echo "Sprawdzanie nagłówka JNI"
if [ ! -f "target/generated-sources/jni/game_GameEngine.h" ]; then
    echo "Błąd: brak nagłówka JNI! Maven nie wygenerował pliku."
    exit 1
fi

echo "Kompilacja plików C++"
if [ -z "$JAVA_HOME" ]; then
    echo "OSTRZEŻENIE: JAVA_HOME nie ustawione, próbuję znaleźć JDK..."
    JAVA_HOME=$(dirname $(dirname $(readlink -f $(which javac))))
    echo "Znaleziono JDK: $JAVA_HOME"
fi

mkdir -p build

g++ -fPIC -c src/main/cpp/GameEngine.cpp -o build/GameEngine.o 

g++ -fPIC -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -Itarget/generated-sources/jni -c src/main/cpp/GameEngineJNI.cpp -o build/GameEngineJNI.o

echo "Tworzenie biblioteki .so i przenoszenie jej do resources/native"
g++ -shared build/GameEngine.o build/GameEngineJNI.o -o build/lib/libtictactoe_engine.so

cp build/lib/libtictactoe_engine.so src/main/resources/native/libtictactoe_engine.so

if [ "$1" = "run" ]; then 
    echo "Uruchamianie aplikacji..."
    mvn exec:java -Dexec.mainClass=\"game.TicTacToeApp\"
    exit 0
fi
echo "Uruchom gre:"
echo "  mvn exec:java -Dexec.mainClass=\"game.TicTacToeApp\""