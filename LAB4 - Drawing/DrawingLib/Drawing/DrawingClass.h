#pragma once
#include <ctime>
#include <vector>
#include "IFigure.h"
#include <iostream>

class Drawing
{
private:
	float width;
	float height;
	std::vector <IFigure> collection;
	void saveChange() const;
	std::time_t getTime() const;

public:
	Drawing(float width, float height, std::vector <IFigure> collection);
	std::vector <IFigure> getCollection() const;
	void setCollection(std::vector <IFigure> const new_collection);
	std::string svgText() const;
	void saveSvg() const;

	friend std::ostream& operator<<(std::ostream& os, const Drawing& drawing);
};
