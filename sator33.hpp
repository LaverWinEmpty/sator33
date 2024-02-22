/**
 * @file    sator33.hpp
 * @author  LaverWinEmpty
 * @brief   3 x 3 size sator maker
 * @version 1.0
 * @date    2024-02-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LWE__SATOR_33_HPP
#define LWE__SATOR_33_HPP

#include "string"
#include "vector"

#ifndef IN
#    define IN
#endif

#ifndef OUT
#    define OUT
#endif

using namespace std;

class Sator33
{
public:
    enum EResult
    {
        OK,
        DUPLICATED,
        INVALID,
    };

public:
    /**
     * @brief get string from external
     */

    /**
     * @brief get string from external
     *
     * @param  str [in] wchar string
     * @return EResult result
     */
    EResult Input(IN const std::wstring& str);

    /**
     * @brief making and saving a sator square
     */
    void Make();

    /**
     * @brief get square 3x3
     *
     * @param  index [in]
     * @return 3 string references
     */
    std::vector<std::wstring> GetResult(IN size_t index) {}

    /**
     * @brief get square amount
     *
     * @return size_t
     */
    size_t GetSqareAmount() const { return square; }

    /**
     * @brief get input words count
     *
     * @return size_t
     */
    size_t GetInputCount() const { return list.size(); }

private:
    size_t loop   = 0;
    size_t square = 0;

private:
    vector<std::wstring> list;
    vector<std::wstring> result;
};

#endif