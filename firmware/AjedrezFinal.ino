#include "LedControl.h"

// Pines para el MAX7219
#define PIN_DIN 12
#define PIN_CS  10
#define PIN_CLK 11

// Inicializa el controlador de matriz LED
LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, 1);

// Tablero 8x8: 0 = vacío, 1 = pieza
int board[8][8] = {
  {1, 1, 1, 1, 1, 1, 1, 1}, // Fila 7 (A8-H8)
  {1, 1, 1, 1, 1, 1, 1, 1}, // Fila 6 (A7-H7)
  {0, 0, 0, 0, 0, 0, 0, 0}, // Fila 5
  {0, 0, 0, 0, 0, 0, 0, 0}, // Fila 4
  {0, 0, 0, 0, 0, 0, 0, 0}, // Fila 3
  {0, 0, 0, 0, 0, 0, 0, 0}, // Fila 2
  {1, 1, 1, 1, 1, 1, 1, 1}, // Fila 1 (A2-H2)
  {1, 1, 1, 1, 1, 1, 1, 1}  // Fila 0 (A1-H1)
};

// Actualiza la matriz LED según el arreglo 'board'
void updateDisplay() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, board[row][col] == 1);
    }
  }
}

// Movimiento genérico de pieza
void movePiece(int fromRow, int fromCol, int toRow, int toCol) {
  board[fromRow][fromCol] = 0;
  board[toRow][toCol] = 1;
  updateDisplay();

  Serial.print("Movimiento: ");
  Serial.print("De [");
  Serial.print(fromRow);
  Serial.print(",");
  Serial.print(fromCol);
  Serial.print("] a [");
  Serial.print(toRow);
  Serial.print(",");
  Serial.print(toCol);
  Serial.println("]");
}

void setup() {
  Serial.begin(9600);

  lc.shutdown(0, false);   // Activa el MAX7219
  lc.setIntensity(0, 8);   // Brillo medio
  lc.clearDisplay(0);      // Limpia la matriz

 updateDisplay();
  Serial.println("Tablero inicial cargado.");
}

void loop() {
  delay(3000); // Espera para visualizar

  // Movimiento 1: E2 a E4 → Fila 1, Col 4 → Fila 3, Col 4
  movePiece(1, 4, 3, 4);

  delay(3000); // Espera para visualizar

  // Movimiento 2: D7 a D5 → Fila 6, Col 3 → Fila 4, Col 3
  movePiece(6, 3, 4, 3);

  while (true); // Detiene el loop
}