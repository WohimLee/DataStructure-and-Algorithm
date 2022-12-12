// #include <stdio.h>
// #include <stdlib.h>


#include <malloc.h>

typedef struct Student
{
    unsigned int age;
    struct Student *next;
}Student;

Student *CreateLinkList(int count)
{
    if (count <= 0)
        return NULL;
    
    Student *pHead = NULL;
    Student *pPrev = NULL;
    for (int i =0; i < count; i++)
    {
        Student *pNode = (Student*)malloc(sizeof(Student));

        if (pNode == NULL)
            return 0;
        
        if (i == 0)
        {
            
        }

        
    }
}

int main()
{
    int size = 0;
    scanf("%d", &size);
    if (size <= 0)
        return 0;
    
    Student *pHead = CreateLinkList(size);

    return 0;
}

