#include "IFigure.h"
#include <string>
#include <vector>

template<typename Collection>
class FigureCollection : public Collection
{
public:
	class FigureIterator
	{
		friend FigureCollection;

		std::vector<IFigure*>::iterator current;
		std::vector<IFigure*> & collection;

	public:

		FigureIterator(std::vector<IFigure*>& col, std::vector<IFigure*>::iterator i) : collection(col)
		{
			this->current = i;
		}

		std::string & operator*()
		{
			IFigure* current_figure = *current;
			return current_figure->getId()[1];
		}

		FigureIterator& operator++()
		{
			IFigure* value_current = *current;
			int current_numb = std::stoi(value_current->getId()[0]);

			for (std::vector<IFigure*>::iterator i = current + 1; i != collection.end(); ++i)
			{
				IFigure* value_i = *i;
				int i_numb = std::stoi(value_i->getId()[0]);
				if(i_numb==current_numb)
				{
					current = i;
					return *this;
				}
			}
			std::vector<IFigure*>::iterator min = collection.end();
			for (std::vector<IFigure*>::iterator i = collection.begin(); i != collection.end(); ++i)
			{
				IFigure* value_i = *i;
				IFigure* value_min = *min;
				int i_numb = std::stoi(value_i->getId()[0]);
				int min_numb = std::stoi(value_min->getId()[0]);
				if ((i_numb > current_numb) && (min == collection.end() || i_numb < min_numb))
				{
					min = i;
				}
			}
			current = min;
			return *this;
		}

		bool operator!=(FigureIterator const& i) const
		{
			return current != i.current;
		}
	};

	FigureIterator myBegin()
	{
		std::vector<IFigure*>::iterator min = this->begin();
		for (std::vector<IFigure*>::iterator i = this->begin(); i != this->end(); ++i)
		{
			IFigure* value_i = *i;
			IFigure* value_min = *min;
			int i_numb = std::stoi(value_i->getId()[0]);
			int min_numb = std::stoi(value_min->getId()[0]);
			if (i_numb < min_numb)
			{
				min = i;
			}
		}
		return FigureIterator(*this, min);
	}

	FigureIterator myEnd()
	{
		return FigureIterator(*this, this->end());
	}
};