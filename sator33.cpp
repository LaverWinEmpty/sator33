#include "sator33.hpp"

Sator33::EResult Sator33::Input(IN const std::wstring& str)
{
    if(str.size() != 3) {
        return INVALID;
    }

    int size = list.size();
    for(int i = 0; i < size; ++i) {
        if(!str.compare(list[i])) {
            return DUPLICATED;
        }
    }

    list.push_back(str);
    return OK;
}

void Sator33::Make()
{
    size_t size = list.size();

    if(loop == size) {
        return;
    }

    // start from the beginning
    for(int i = 0; i < size; ++i) {

        // continue
        for(int j = loop; j < size; ++j) {
            if(i == j) {
                continue;
            }

            if(list[i][2] == list[j][0]) {
                for(int k = 0; k < size; ++k) {
                    // make
                    if(list[i][1] == list[k][0] && list[j][1] == list[k][2]) {
                        result.push_back(list[i]);
                        result.push_back(list[k]);
                        result.push_back(list[j]);
                    }
                }
            }
        }
    }

    // update
    loop   = size;
    square = result.size() / 3;
}

std::vector<std::wstring> Sator33::GetResult(IN size_t index)
{
    std::vector<std::wstring> vec;

    index *= 3;
    vec.push_back(result[index]);
    vec.push_back(result[index + 1]);
    vec.push_back(result[index + 2]);
    return vec;
}