package game;

public class GameController {

    private GameView view;
    private GameEngine engine;
    private boolean gameRunning = true;
    private char currentPlayer = 'X';

    public GameController(GameView view) {
        this.view = view;
        this.engine = new GameEngine();
        this.engine.initGame(); 

    }

    public void handleCellClick(int row, int col) {
        if (!gameRunning) {
            return;
        }
        else {

            boolean success = engine.placeMarker(row, col, currentPlayer);

            if (success) {
                System.out.println("marker placed!");
                return;
            } else {
                System.out.println("marker could not be placed!");
                return;
            }
        }
    }

    public void resetGame() {
        view.clearBoard();
        engine.resetGame();
        currentPlayer = 'X';
        gameRunning = true;
    }

    public char getCurrentPlayer() {
        return currentPlayer;
    }

    public boolean isGameRunning() {
        return gameRunning;
    }
}
