#ifndef STATUS_H
#define STATUS_H

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0

#ifndef OVERFLOW
#define OVERFLOW -2
#endif // OVERFLOW

#ifndef NULL
#define NULL ((void*)0)
#endif // NULL

typedef int Status;

#endif // STATUS_H