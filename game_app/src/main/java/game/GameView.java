package game;

import java.awt.BorderLayout;
import java.awt.Color;
import java.util.HashSet;
import java.util.Set;

import javax.swing.*;

public class GameView  extends JFrame{

    private JButton[][] cells;
    private JLabel statusLabel;
    private JButton restartButton;
    private GameController controller;
    private final int BOARD_SIZE = 3;
    private final int CELL_SIZE = 100;
    private final int FONT_SIZE = 40;
    private final String FONT_NAME = "Ubuntu";
    
    private Set<String> occupiedCells = new HashSet<>();

    public GameView() {
        setupUI();
        this.controller = new GameController(this);
        controller.resetGame();
    }

    private void setupUI() {
        setTitle("Tic Tac Toe");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 450);
        setLocationRelativeTo(null);

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout(10, 10));
        mainPanel.setBackground(Color.LIGHT_GRAY);
        mainPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // TODO: dodaj planszę (grid 3x3 z przyciskami)
        // TODO: dodaj status label na górze
        // TODO: dodaj przycisk restart na dole
        
        add(mainPanel);
        setVisible(true);

    }

    public void clearBoard() {
        ;
    }

}
