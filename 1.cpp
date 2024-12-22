#include "1.h"


int count(char* str1, char* str2)
{
    int cnt = NULL;
    int len_1 = std::strlen(str1);
    int len_2 = std::strlen(str2);

    for (int c1 : std::views::iota(0) | std::views::take(len_1))
    {
        if (str1[c1] == str2[NULL] && len_2 != 1) {
            int ind = c1 + 1;
            for (int c2 : std::views::iota(1) | std::views::take(len_2 - 1))
            {
                if (str1[ind] == str2[c2])
                {
                    if (c2 == len_2 - 1)
                        cnt++;
                }
                else
                    break;
                ind++;
            }
        }
        else if (str1[c1] == str2[NULL] && len_2 == 1)
            cnt++;
    }



    return cnt;
}