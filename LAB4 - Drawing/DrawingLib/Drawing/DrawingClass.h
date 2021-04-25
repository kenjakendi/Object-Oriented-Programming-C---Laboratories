#pragma once
#include <ctime>
#include <vector>
#include "IFigure.h"

class Drawing
{
private:
	std::vector <IFigure> collection;
	void saveChange() const;
	std::time_t getTime() const;

public:
	Drawing(std::vector <IFigure> collection);
	std::vector <IFigure> getCollection() const;
	void setCollection(std::vector <IFigure> const new_collection);
	void saveSvg() const;

};
