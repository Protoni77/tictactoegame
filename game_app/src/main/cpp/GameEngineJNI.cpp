#include <jni.h>
#include <cstring>

extern void initEngine();
extern bool placeMarker(int row, int col, char player);
extern char getCell(int row, int col);
extern char checkWinner();
extern bool getWinningLine(int* outLine);
extern void resetGame();
extern int getMoveCount();
extern bool isGameOver();

extern "C" {

JNIEXPORT void JNICALL Java_game_GameEngine_initGame
  (JNIEnv *, jobject) {
    initEngine();
  }

JNIEXPORT jboolean JNICALL Java_game_GameEngine_placeMarker
  (JNIEnv *env, jobject  obj, jint row, jint col, jchar player) {
    result = placeMarker(row, col, player);
    return result ? JNI_TRUE : JNI_FALSE;
  }

JNIEXPORT jchar JNICALL Java_game_GameEngine_checkWinner
  (JNIEnv *env, jobject obj) {
    char winner = checkWinner();
    return (jchar)winner;
  }

JNIEXPORT jchar JNICALL Java_game_GameEngine_getCell
  (JNIEnv *env, jobject obj, jint row, jint col) {
    char cell = getCell(row, col);
    return (jchar)cell;
  }


JNIEXPORT void JNICALL Java_game_GameEngine_resetGame
  (JNIEnv *env, jobject obj) {
    resetGame();
  }


JNIEXPORT jboolean JNICALL Java_game_GameEngine_isGameOver
  (JNIEnv *env, jobject obj) {
    bool result = isGameOver();
    return result ? JNI_TRUE : JNI_FALSE;
  }


JNIEXPORT jint JNICALL Java_game_GameEngine_countMoves
  (JNIEnv *env, jobject obj) {
    int count = getMoveCount();
    return count;
}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    return JNI_VERSION_1_8;
}

}
