#include <stdlib.h>
#include "1_SString.h"


void printElem(SString S)
{
    for (int i = 1; i <= S[0]; i++)
        printf("%c", S[i]);
    printf("\n");
}

// (1) 初始化
Status StrAssign(SString T, const char* chars)
{
    int len = (int)strlen(chars);

    // chars 过长
    if (len > MAXSTRLEN)
    {
        printf("[WARNING]: OVER SIZE!\n");
        return ERROR;
    }

    T[0] = len;
    for (int i = 1; i <= len; i++)
    {
        T[i] = chars[i-1];
    }
    return OK;
}

// (2) 清空
Status ClearString(SString S)
{
    // 只需要将长度置为 0 就可以
    S[0] = 0;
}

// (3) 判空
Status StrEmpty(SString S)
{
    return S[0] == 0 ? TRUE : FALSE;
}

// (4) 计数
int StrLength(SString S)
{
    return S[0];
}

// (5) 求子串
Status SubString(SString Sub, SString S, int pos, int len)
{
    if (StrEmpty(S))
    {
        printf("[WARNING]: EMPTY STRING!\n");
    }
    if (pos < 1 || pos > S[0])
    {
        printf("[WARNING]: POSITION IS NOT VALID!\n");
        return ERROR;
    }
    if (len < 0 || pos + len - 1 > S[0])
    {
        printf("[WARNING]: LENGTH IS NOT VALID!\n");
        return ERROR;
    }

    // 复制元素
    for (int i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];

    // 确定新长度
    Sub[0] = len;
    return OK;
}

// (6) 查找
int Index_1(SString S, SString T, int pos)
{
    if (StrEmpty(S))
    {
        printf("[WARNING]: EMPTY STRING!\n");
    }
    if (pos < 1 || pos > S[0])
    {
        printf("[WARNING]: POSITION IS NOT VALID!\n");
        return ERROR;
    }

    SString sub;
    int i = pos;
    int len_s = StrLength(S);
    int len_t = StrLength(T);

    // 保证长度不越界
    while (i <= len_s - len_t + 1)
    {
        // 获取 S[i, i + m-1]
        SubString(sub, S, i, len_t);
        // 如果子串与模式串不匹配，则需要继续推进
        if (StrCompare(sub, T) != 0)
            ++i;
        else   
            return i;
    }
    return 0;
}

int Index_2(SString S, SString T, int pos)
{
    if (StrEmpty(S))
    {
        printf("[WARNING]: EMPTY STRING!\n");
    }
    if (pos < 1 || pos > S[0])
    {
        printf("[WARNING]: POSITION IS NOT VALID!\n");
        return ERROR;
    }

    int move_s = pos;
    int move_t = 1;

    while (move_s <= S[0] && move_t <= T[0])
    {   // 遇到相同字符，则继续比较后续字符
        if (S[move_s] == T[move_t])
        {
            move_s++;
            move_t++;
        }
        else
        {   // 遇到不同的字符，则游标需要回退，重新比较
            move_s = move_s - (move_t - 1) + 1;
            move_t = 1;
        }
    }

    // 增加了一个 T[0]>0 的判断
    if ( move_t > T[0] && T[0] > 0) // T 不为空串
        return move_s - T[0];       // 匹配成功
    else
        return 0;
}
