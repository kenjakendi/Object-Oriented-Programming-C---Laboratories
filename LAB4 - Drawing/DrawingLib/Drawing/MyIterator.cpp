#include "IFigure.h"
#include <string>
#include <vector>

template<typename T, typename Collection, typename Iterator>
class FigureCollection : public Collection
{
public:
	class FigureIterator
	{
		friend FigureCollection;

		Iterator current;
		Collection & collection;

	public:

		FigureIterator(Collection& col, Iterator i) : collection(col)
		{
			this->current = i;
		}

		std::string & operator*()
		{
			T current_figure = *current;
			return current_figure->getId()[1];
		}

		int getMaxNumb()
		{
			Iterator max = collection.begin();
			T value_max = *max;
			int max_numb = std::stoi(value_max->getId()[0]);
			for (Iterator i = collection.begin(); i != collection.end(); ++i)
			{
				T value_i = *i;
				int i_numb = std::stoi(value_i->getId()[0]);
				if (i_numb > max_numb)
				{
					max_numb = i_numb;
				}
			}
			return max_numb;
		}

		FigureIterator& operator++()
		{
			T value_current = *current;
			int current_numb = std::stoi(value_current->getId()[0]);

			for (Iterator i = current + 1; i != collection.end(); ++i)
			{
				T value_i = *i;
				int i_numb = std::stoi(value_i->getId()[0]);
				if(i_numb==current_numb)
				{
					current = i;
					return *this;
				}
			}

			Iterator min;
			int max_numb = getMaxNumb();
			int local_max = max_numb+1;
			for (Iterator i = collection.begin(); i != collection.end(); ++i)
			{
				T value_i = *i;
				int i_numb = std::stoi(value_i->getId()[0]);
				if (current_numb == max_numb)
				{
					min = collection.end();
				}
				else if (i_numb > current_numb && i_numb<local_max)
				{
					min = i;
					local_max = i_numb;
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
		Iterator min = this->begin();
		for (Iterator i = this->begin(); i != this->end(); ++i)
		{
			T value_i = *i;
			T value_min = *min;
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