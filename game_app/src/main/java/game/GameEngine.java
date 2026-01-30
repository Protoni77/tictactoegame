package game;

import java.io.File;

public class GameEngine {
    
    static {
        try {
            // Próba załadowania z target/classes/native (dla mvn exec:java)
            String libraryPath = "target/classes/native/libtictactoe_engine.so";
            File libFile = new File(libraryPath);
            
            if (!libFile.exists()) {
                // Próba załadowania z resources (dla JAR)
                libraryPath = "src/main/resources/native/libtictactoe_engine.so";
                libFile = new File(libraryPath);
            }
            
            if (libFile.exists()) {
                System.load(libFile.getAbsolutePath());
                System.out.println("Biblioteka natywna załadowana z: " + libFile.getAbsolutePath());
            } else {
                throw new UnsatisfiedLinkError("Nie znaleziono biblioteki libtictactoe_engine.so");
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new UnsatisfiedLinkError("Błąd ładowania biblioteki: " + e.getMessage());
        }
    }
    
    public native void initGame();
    public native boolean placeMarker(int row, int col, char player);
    public native char checkWinner();
    public native char getCell(int row, int col);
    public native void resetGame();
    public native boolean isGameOver();
    public native int countMoves();
}
