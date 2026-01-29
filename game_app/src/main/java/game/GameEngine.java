package game;

public class GameEngine {
    public native void initGame();
    public native boolean placeMarker(int row, int col, char player);
    public native char checkWinner();
    public native char getCell(int row, int col);
    public native void resetGame();
    public native boolean isGameOver();
    public native int countMoves();
}
