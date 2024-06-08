#pragma once
#include <glm/glm.hpp>
#include <string>
#include <vector>

void ReadPositions(std::vector<glm::vec2>& positions, std::string filename);
void ReadHighscores(std::vector<std::string>& vecStrings, std::string highscoreFile);
glm::vec2 Seek(glm::vec2& currentPos, glm::vec2 targetPos);

std::vector<glm::vec2> generateCirclePoints(double cx, double cy, double radius, int numPoints, double startAngleDeg, bool clockwise);
