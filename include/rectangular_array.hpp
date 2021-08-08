#ifndef RECTANGULAR_ARRAY_HPP
#define RECTANGULAR_ARRAY_HPP

#include <memory>


/**
 * @brief 
 * 
 * @tparam T 
**/
template<typename T>
class RectangularArray
{
public:

    /**
     *  @brief 
     *      Construct a new Rectangular Array object
    **/
    RectangularArray() = default;


    /**
     *  @brief 
     *      Construct a new Rectangular Array object
     * 
     *  @param x 
     *  @param y 
    **/
    explicit RectangularArray(size_t x, size_t y);


    /**
     *  @brief 
     *      Destroy the Rectangular Array object
     * 
    **/
    ~RectangularArray() = default;

    /**
     * @brief Construct a new Rectangular Array object
     * 
     * @param recArr 
     */
    RectangularArray(const RectangularArray& recArr);


    /**
     * @brief Construct a new Rectangular Array object
     * 
     * @param recArr 
     */
    RectangularArray(RectangularArray&& recArr);


    /**
     * @brief 
     * 
     * @param recArr 
     * @return RectangularArray& 
     */
    RectangularArray& operator =(const RectangularArray& recArr);


    /**
     * @brief 
     * 
     * @param recArr 
     * @return RectangularArray& 
     */
    RectangularArray& operator =(RectangularArray&& recArr);

    ///< End Lİfe Time Management


    ///< !Delete 
    ///< Other Methods
    std::unique_ptr<T[]> getRow() const;


    ///< Overloading Operator
    T& operator ()(int i, int j);

private:
    std::unique_ptr<std::unique_ptr<T[]>[]> _wArr;
};

#endif /* end of include guard :  RECTANGULAR_ARRAY_HPP */