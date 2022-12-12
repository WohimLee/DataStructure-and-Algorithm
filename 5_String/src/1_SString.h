#ifndef SSTRING_H
#define SSTRING_H

#include "Status.h"

/* 宏定义 */
#define MAXSTRLEN 255       // 顺序串的最大串长

/*
 * 串的顺序存储类型定义
 * 注：有效元素从SString的1号单元开始存储
 *     SString的0号单元用来存储其长度
 */
typedef unsigned char SString[MAXSTRLEN + 1];       // 0号单元存放串的长度


void printElem(SString S);

/* (1) 初始化
 * 构造一个值为 chars 的串 T。
 *【注】
 * 该操作属于最小操作子集
 */
Status StrAssign(SString T, const char* chars);


/* (2) 清空
 * 将串S清空。
 */
Status ClearString(SString S);


/* (3) 判空
 * 判断串S中是否包含有效数据。
 * 返回值：
 * TRUE : 串S为空
 * FALSE: 串S不为空
 */
Status StrEmpty(SString S);

/* (4) 计数
 * 返回串S中元素的个数。
 *【注】
 * 该操作属于最小操作子集
 */
int StrLength(SString S);

/* (5) 求子串
 * 用 Sub 返回 S[pos, pos+len-1]。
 * 返回值指示是否截取成功。
 *【注】
 * 该操作属于最小操作子集
 */
Status SubString(SString Sub, SString S, int pos, int len);

/* (6) 查找
 * 从 pos 处开始搜索模式串T在主串S中首次出现的位置，如果不存在，则返回0。
 * 如果查找成功，返回匹配的位置。
 *【注】
 * 1.此实现需要依赖串的最小操作子集
 * 2.该实现比较低效
 */
int Index_1(SString S, SString T, int pos);

int Index_2(SString S, SString T, int pos);

/*
 * 插入
 *
 * 将串T插入到主串S的pos位置处。
 */
Status StrInsert(SString S, int pos, SString T);

/*
 * 删除
 *
 * 删除 S[pos, pos+len-1]。
 */
Status StrDelete(SString S, int pos, int len);

/*
 * 比较
 *
 * 比较串S和串T，返回比较结果。
 *
 *【注】
 * 该操作属于最小操作子集
 */
int StrCompare(SString S, SString T);

/* 复制
 * 将串S复制到串T。
 */
Status StrCopy(SString T, SString S);

/* 替换
 * 用V替换主串S中出现的所有与T相等的且不重叠的子串。
 *
 *【注】
 * 该操作依赖最小操作子集，效率较低。
 */
Status Replace(SString S, SString T, SString V);

/* 串联接
 *
 * 联接S1和S2，并存储到T中返回。如果联接后的长度溢出，则只保留未溢出的部分。
 * 返回值表示联接后的串是否完整。
 *
 *【注】
 * 该操作属于最小操作子集
 */
Status Concat(SString T, SString S1, SString S2);


#endif // SSTRING_H