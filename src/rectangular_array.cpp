#include "rectangular_array.hpp"

template<typename T>
RectangularArray<T>::RectangularArray(size_t x, size_t y) 
    :   _wArr(std::make_unique<std::unique_ptr<T[]>[]>(x))
{
    for (size_t i = 0; i < x; ++i)
    {
        _wArr[i] = std::make_unique<T[]>(y);
    }
}


template<typename T>
RectangularArray<T>::RectangularArray(const RectangularArray& recArr) 
{
    _wArr = std::make_unique<std::unique_ptr<T[]>[]>(x);
    for (size_t i = 0; i < x; ++i)
    {
        _wArr[i] = std::make_unique<T[]>(y);
        for (size_t j = 0; j < x; ++j)
        {
            _wArr[i][j] = recArr._wArr[i][j]
        }
    }
}


template<typename T>
RectangularArray<T>::RectangularArray(RectangularArray&& recArr) 
    :   _wArr(std::move(recArr._wArr))
{
}


template<typename T>
RectangularArray<T>& RectangularArray<T>::operator =(const RectangularArray& recArr) 
{
    if (this != &recArr)
    {
        _wArr = std::make_unique<std::unique_ptr<T[]>[]>(x);
        for (size_t i = 0; i < x; ++i)
        {
            _wArr[i] = std::make_unique<T[]>(y);
            for (size_t j = 0; j < x; ++j)
            {
                _wArr[i][j] = recArr._wArr[i][j]
            }
        }
    }
    return *this;
}


template<typename T>
RectangularArray<T>& RectangularArray<T>::operator =(RectangularArray&& recArr) 
{
    if (this != &recArr)
    {
        _wArr = std::move(recArr._wArr);
    }
    return *this;
}


///< -------------


template<typename T>
std::unique_ptr<T[]> RectangularArray<T>::getRow() const
{

}


template<typename T>
T& RectangularArray<T>::operator ()(int i, int j) 
{
    return _wArr[i][j];
}
