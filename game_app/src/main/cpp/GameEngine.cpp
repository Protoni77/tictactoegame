class TicTacToeEngine {
private:
    char board[3][3];
    int moveCount;

public:
    TicTacToeEngine() {
        initBoard();
    }

    void initBoard() {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                board[i][j] = '-';
            }
        }
        moveCount = 0;
    }


    bool placeMarker(int row, int col, char player) {
        if (row < 0 || row > 2 || col < 0 || col > 2 ) {
            return false;
        }
        if (board[row][col] != '-') {
            return false;
        }
        board[row][col] = player;
        moveCount++;
        return true;
    }

    char getCell(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 ) {
            return '-';
        }
        return board[row][col];
    }

    char checkWinner() {
        for (int i=0; i<3; ++i) {
            if (board[i][0] != '-' &&
                board[i][1] == board[i][0] &&
                board[i][2] == board[i][1]) 
            {
                return board[i][0];
            }
        }
        for (int i=0; i<3; ++i) {
            if (board[0][i] != '-' &&
                board[1][i] == board[0][i] &&
                board[2][i] == board[1][i]) 
            {
                return board[0][i];
            }
        }

        if (board[0][0] != '-' &&
            board[1][1] == board[0][0] &&
            board[2][2] == board[1][1])
        {
            return board[0][0];
        }

        if (board[2][0] != '-' &&
            board[1][1] == board[2][0] &&
            board[0][2] == board[1][1])
        {
            return board[2][0];
        }

        return '-';
    }

    int getMoveCount() {
        return moveCount;
    }

    void reset() {
        initBoard();
    }

    bool isGameOver()  {
        if (moveCount == 9) return true;
        if (checkWinner() != '-') return true;
        return false;
    }

};

static TicTacToeEngine* g_engine = nullptr;


void initEngine() {
    if (g_engine == nullptr) {
        g_engine = new TicTacToeEngine();
    } else {
        g_engine->reset();
    }
}

TicTacToeEngine* getEngine() {
    if (g_engine == nullptr) {
        initEngine();
    }
    return g_engine;
}


bool placeMarker(int row, int col, char player) {
    TicTacToeEngine* engine = getEngine();
    bool result = g_engine->placeMarker(row, col, player);
    return result;
}

void resetGame() {
    g_engine->reset();
}

char checkWinner() {
    return g_engine->checkWinner();
}

char getCell(int row, int col) {
    return g_engine->getCell(row, col);
}

bool isGameOver() {
    return g_engine->isGameOver();
}

int getMoveCount() {
    return g_engine->getMoveCount();
}

