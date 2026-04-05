#include "ConsoleRenderer.h"
#include <iostream>

namespace {
    char GetSymbol(CellType cell) {
        switch (cell) {
            case CellType::Empty: return ' '; break;
            case CellType::Food: return 'O'; break;
            case CellType::SnakeBody: return '#'; break;
            case CellType::SnakeHead: return '@'; break;
            case CellType::Wall: return 'X'; break;
            default: return '?';
        }
    };
}


ConsoleRenderer::ConsoleRenderer(int w, int h) : width(w), height(h){
	buffer.resize(width * height, ' ');
    std::cout << "\033[?25l"; // hide cursor
}

ConsoleRenderer::~ConsoleRenderer() {
    std::cout << "\033[?25l"; // show cursor
}

void ConsoleRenderer::Clear() {
	std::fill(buffer.begin(), buffer.end(), ' ');
};


void ConsoleRenderer::DrawCell(int x, int y, CellType cell) {
	if ((x >= 0 && x < width) && (y >= 0 && y < height)) {
		buffer[y * width + x] = GetSymbol(cell);
	}
};

void ConsoleRenderer::DrawChar(int x, int y, char symbol) {
    if ((x >= 0 && x < width) && (y >= 0 && y < height)) {
        buffer[y * width + x] = symbol;
    }
};

void ConsoleRenderer::DrawString(int x, int y, const std::string& text) {
    for (size_t i = 0; i < text.length(); ++i) {
        DrawChar(x + (int)i, y, text[i]);
    }
}

void ConsoleRenderer::Display() {
    printf("\033[H");
    
    std::string output;
    output.reserve(width * height + height);
    // 2. Build a single string to print everything at once
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            output += buffer[y * width + x];
        }
        output += '\n'; // End of row
    }
    //std::cout << output;
    std::cout << output << std::flush;
};