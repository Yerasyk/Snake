#include "ConsoleRenderer.h"
#include <iostream>

ConsoleRenderer::ConsoleRenderer(int w, int h) : width(w), height(h){
	buffer.resize(width * height, ' ');
}

void ConsoleRenderer::Clear() {
	std::fill(buffer.begin(), buffer.end(), ' ');
};


void ConsoleRenderer::Draw(int x, int y, char symbol) {
	if ((x >= 0 && x < width) && (y >= 0 && y < height)) {
		buffer[y * width + x] = symbol;
	}
};

void ConsoleRenderer::DrawString(int x, int y, const std::string& text) {
    for (size_t i = 0; i < text.length(); ++i) {
        Draw(x + (int)i, y, text[i]);
    }
}

void ConsoleRenderer::DrawGameOver(int y) {
 
    DrawString(0, y, "============================");
    DrawString(0, y + 1, "       GAME OVER          ");
    DrawString(0, y + 2, "============================");
    DrawString(0, y + 3, "+ Press R to restart");
    DrawString(0, y + 4, "+ Press Q to quit");
}

void ConsoleRenderer::Display() {
    printf("\033[H");
    
    std::string output = "";
    // 2. Build a single string to print everything at once
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            output += buffer[y * width + x];
        }
        output += '\n'; // End of row
    }
    std::cout << output;
};