#pragma once
#include <ctime>
#include <vector>
#include "IFigure.h"
#include <iostream>

class Drawing
{
private:
	std::string name;
	float width;
	float height;
	std::vector <IFigure*> collection;
	void saveChange(std::string const message) const;
	std::time_t getTime() const;

public:
	Drawing(std::string name, float width, float height, std::vector <IFigure*> collection = {});
	
	std::string getName() const;
	float getWidth() const;
	float getHeight() const;
	std::vector <IFigure*> getCollection() const;
	
	void setName(std::string const new_name);
	void setWidth(float const new_width);
	void setHeight(float const new_height);
	void setCollection(std::vector <IFigure*> const new_collection);
	
	std::string svgText() const;
	void saveSvg(std::string const file_name) const;
	void clearLog() const;

	friend std::ostream& operator<<(std::ostream& os, const Drawing& drawing);
};
