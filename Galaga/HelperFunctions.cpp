#include "HelperFunctions.h"
#include <fstream>
#include "sstream"
#include "iostream"
#include "DeltaTime.h"

void ReadPositions(std::vector<glm::vec2>& positions, std::string filename)
{
	//!!!!!!!!!!most of it is from chat gpt with some changes i made!!!!!!!!!!!
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file!" << std::endl;
	}

	std::string line;
	while (std::getline(file, line)) {
		// Remove possible whitespace at the beginning and end of the line
		line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char ch) {
			return !std::isspace(ch);
			}));
		line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
			}).base(), line.end());

		// Skip empty lines
		if (line.empty()) {
			continue;
		}

		std::stringstream ss(line);
		float x, y;
		if (ss >> x >> y) {
			positions.emplace_back(glm::vec2(x, y));
		}
	}
}

void ReadHighscores(std::vector<std::string>& vecStrings, std::string highscoreFile)
{
	std::ifstream file(highscoreFile);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file!" << std::endl;
	}

	std::string line;
	while (std::getline(file, line))
	{
		vecStrings.emplace_back(line);
	}
}

//!!!!!!!!!!!!This function Comes from chat gpt!!!!!!!!!!!!!!!!!!!!!!!!!!!!
std::vector<glm::vec2> generateCirclePoints(double cx, double cy, double radius, int numPoints, double startAngleDeg, bool clockwise)
{
	std::vector<glm::vec2> points;
	double angleIncrement = 360.0 / numPoints; // Angle between each point

	for (int i = 0; i < numPoints; ++i) {
		double angleDeg = 0.00;
		if (clockwise == true)
		{
			angleDeg = startAngleDeg + i * angleIncrement;
		}
		else
		{
			angleDeg = startAngleDeg - i * angleIncrement; // Current angle in degrees
		}
		double angleRad = angleDeg * 3.14159 / 180.0; // Convert angle to radians

		double x = cx + radius * cos(angleRad);
		double y = cy + radius * sin(angleRad);

		points.emplace_back(glm::vec2{ x, y });
	}

	return points;
}

//seek helperfunction
glm::vec2 Seek(glm::vec2& currentPos, glm::vec2 targetPos)
{
	glm::vec2 dir = currentPos - targetPos;
	dir = glm::normalize(dir);

	glm::vec2 nextPos = currentPos;
	nextPos -= dir * 150.0f * dae::DeltaTime::GetInstance().GetDeltaTime();
	return nextPos;
}
