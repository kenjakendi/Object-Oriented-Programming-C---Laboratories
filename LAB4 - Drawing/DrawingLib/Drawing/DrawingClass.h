#pragma once
#include <ctime>
#include <vector>
#include "IFigure.h"
#include <iostream>

class Drawing
{
private:
	// Parameters
	std::string name;
	float width;
	float height;
	std::vector <IFigure*> collection;

	// Private methods
	void saveChange(std::string const message) const;
	std::time_t getTime() const;

public:
	// Constructor
	Drawing(std::string name, float width, float height, std::vector <IFigure*> collection = {});
	
	// Getters
	std::string getName() const;
	float getWidth() const;
	float getHeight() const;
	std::vector <IFigure*> getCollection() const;
	
	// Setters
	void setName(std::string const new_name);
	void setWidth(float const new_width);
	void setHeight(float const new_height);
	void setCollection(std::vector <IFigure*> const new_collection);
	
	// Saving methods
	std::string svgText() const;
	void saveSvg(std::string const file_name) const;
	void clearLog() const;

	// Operator
	friend std::ostream& operator<<(std::ostream& os, const Drawing& drawing);
};
