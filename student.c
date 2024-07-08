#include "header.h"

int main()
{
    char op;
    SLL *hprt = 0;
    while (1)
    {
        printf("\033[33m !================ Menu ================! \033[0m \n");
        printf("\033[35m \t A. Add_New_Record\n\t D. Delete_a_Record\n \t S. Show_The_List\n\t M. Modify_a_Record\n\t V. Save\n\t E. Exit\n\t T. Sort_The_List\n\t L. Delete_All_The_Record\n\t R. Reverse_The_List \033[0m \n");
        printf("\033[33m !================ *** ================! \033[0m \n");
        scanf(" %c", &op);
        switch (op)
        {
        case 'a':
            stud_add(&hprt);
            break;
        case 'd':
            stud_del(&hprt);
            break;
        case 's':
            stud_show(hprt);
            break;
        case 'm':
            stud_mod(&hprt);
            break;
        case 'v':
            save_list(hprt);
            break;
        case 'e':
            printf("\033[34m \t ******Thank You******  \033[0m \n");
            exit(0);
            break;
        case 't':
            sort_list(&hprt);
            break;
        case 'l':
            stud_delete_all(&hprt);
            break;

        case 'r':
            stud_rev(&hprt);
            break;

        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
    return 0;
}
/*====================== Function Declration ====================*/
/*====================== 1.Add ====================*/
void stud_add(SLL **ptr)
{
    char op;
    while (1)
    {

        printf("\033[34m O. Old_Data\t N. New_Data\t T. Terminate\033[0m \n");
        scanf(" %c", &op);
        switch (op)
        {
        case 'n':
            static int rn;
            SLL *new = 0;
            new = malloc(sizeof(SLL));
            printf("Enter the Name & Marks\n");
            scanf("%s%f", new->name, &new->marks);
            new->rollNo = ++rn;
            new->next = 0;
            if (*ptr == 0)
            {
                *ptr = new;
            }
            else
            {
                SLL *last = *ptr;
                while (last->next)
                {
                    last = last->next;
                }
                last->next = new;
            }
            break;
        case 'o':
            new = malloc(sizeof(SLL));
            printf("Enter the Roll No, Name & Marks\n");
            scanf("%d%s%f", &new->rollNo, new->name, &new->marks);
            if ((*ptr == 0) || new->rollNo < (*ptr)->rollNo)
            {
                new->next = *ptr;
                *ptr = new;
            }
            else
            {
                SLL *last = *ptr;
                while (last->next != 0 && new->rollNo > last->next->rollNo)
                {
                    last = last->next;
                }
                new->next = last->next;
                last->next = new;
            }

            break;
        case 't':
            goto l1;
            break;
        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
l1:
    return;
}
/*====================== 2.Delete_A_Record  ====================*/
void stud_del(SLL **ptr)
{
    if (*ptr != 0)
    {
        char op;
        printf("\033[34mR. Roll No\tN. Name\t M.Marks\t\033[0m \n");
        scanf(" %c", &op);
        SLL *prev, *del = *ptr;
        switch (op)
        {
        case 'r':
            int no;
            printf("Enter the Roll No to Delete\n");
            scanf("%d", &no);
            while (del)
            {
                if (no == del->rollNo)
                {
                    if (*ptr == del)
                    {
                        *ptr = del->next;
                    }
                    else
                    {
                        prev->next = del->next;
                    }
                    free(del);
                    return;
                }
                prev = del;
                del = del->next;
            }
            printf("\033[31m Roll No not found! \033[0m \n");
            break;
        case 'n':
            char s[25];
            printf("Enter the Name to Delete\n");
            scanf("%s", s);
            while (del)
            {
                if (strcmp(s, del->name) == 0)
                {
                    if (*ptr == del)
                    {
                        *ptr = del->next;
                    }
                    else
                    {
                        prev->next = del->next;
                    }
                    free(del);
                    return;
                }
                prev = del;
                del = del->next;
            }
            printf("\033[31m Name not found! \033[0m \n");
            break;
        case 'm':
            float mrks;
            printf("Enter the Marks to Delete\n");
            scanf("%f", &mrks);
            while (del)
            {
                if (mrks == del->marks)
                {
                    if (*ptr == del)
                    {
                        *ptr = del->next;
                    }
                    else
                    {
                        prev->next = del->next;
                    }
                    free(del);
                    return;
                }
                prev = del;
                del = del->next;
            }
            printf("\033[31m  Marks not found! \033[0m \n");
            break;
        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n\n");
        return;
    }
}
/*====================== 3.Show  ====================*/
void stud_show(SLL *ptr)
{
    if (ptr != 0)
    {
        while (ptr)
        {
            printf("%d  %s  %.2f %%\n", ptr->rollNo, ptr->name, ptr->marks);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n");
        return;
    }
}
/*====================== 4.Mod  ====================*/
void stud_mod(SLL **ptr)
{
    char op;
    while (1)
    {
        printf("\033[35mA. Add_New_Record\t D. Delete_a_Record\t S. Search_Node\t E.Exit \033[0m \n");
        scanf(" %c", &op);
        switch (op)
        {
        case 's':
            search_node(*ptr);
            break;
        case 'a':
            stud_add(ptr);
            break;
        case 'd':
            stud_del(ptr);
            break;
        case 'e':
            goto l1;
            break;
        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
l1:
    return;
}
/*====================== 5.Save_List  ====================*/
void save_list(SLL *ptr)
{
    if (ptr != 0)
    {
        char op;
        printf("\033[34m S. Save_And_Exit \t E. Exit\033[0m \n");

        scanf(" %c", &op);
        switch (op)
        {
        case 's':
            FILE *fp;
            fp = fopen("student.txt", "w+");
            fprintf(fp, "Roll No.   Name   Marks(%%)\t\n");
            if (fp != 0)
            {
                while (ptr)
                {
                    fprintf(fp, "   %d       %s     %.2f %%\n", ptr->rollNo, ptr->name, ptr->marks);
                    ptr = ptr->next;
                }
                fclose(fp);
                printf("\033[32m Success: Data Copied...!  \033[0m \n");
            }
            else
            {
                printf("\033[31m Warning: No File Found..!  \033[0m \n");
                return;
            }
            break;

        case 'e':
            return;
            break;

        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n");
        return;
    }
}
/*====================== 7.Sort_List  ====================*/
void sort_list(SLL **ptr)
{
    if (*ptr != 0)
    {
        SLL *p = *ptr, *q, t;
        int c = stud_count(*ptr), i, j;
        char op;
        printf("\033[34mR. Roll No  \tN. Sort_With_Name  \tP. Sort_With_Percentage\033[0m \n");
        scanf(" %c", &op);
        switch (op)
        {
        case 'r':
            for (i = 0; i < c - 1; i++)
            {
                q = p->next;
                for (j = 0; j < c - 1 - i; j++)
                {
                    if (p->rollNo > q->rollNo)
                    {
                        t.rollNo = p->rollNo;
                        strcpy(t.name, p->name);
                        t.marks = p->marks;

                        p->rollNo = q->rollNo;
                        strcpy(p->name, q->name);
                        p->marks = q->marks;

                        q->rollNo = t.rollNo;
                        strcpy(q->name, t.name);
                        q->marks = t.marks;
                    }
                    q = q->next;
                }
                p = p->next;
            }
            break;
        case 'n':
            for (i = 0; i < c - 1; i++)
            {
                q = p->next;
                for (j = 0; j < c - 1 - i; j++)
                {
                    if (strcmp(p->name, q->name) > 0)
                    {
                        t.rollNo = p->rollNo;
                        strcpy(t.name, p->name);
                        t.marks = p->marks;

                        p->rollNo = q->rollNo;
                        strcpy(p->name, q->name);
                        p->marks = q->marks;

                        q->rollNo = t.rollNo;
                        strcpy(q->name, t.name);
                        q->marks = t.marks;
                    }

                    q = q->next;
                }
                p = p->next;
            }
            break;
        case 'p':
            for (i = 0; i < c - 1; i++)
            {
                q = p->next;
                for (j = 0; j < c - 1 - i; j++)
                {
                    if (p->marks > q->marks)
                    {
                        t.rollNo = p->rollNo;
                        strcpy(t.name, p->name);
                        t.marks = p->marks;

                        p->rollNo = q->rollNo;
                        strcpy(p->name, q->name);
                        p->marks = q->marks;

                        q->rollNo = t.rollNo;
                        strcpy(q->name, t.name);
                        q->marks = t.marks;
                    }
                    q = q->next;
                }
                p = p->next;
            }
            break;
        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n\n");
        return;
    }
}
/*====================== 8.Delete_All  ====================*/
void stud_delete_all(SLL **ptr)
{
    if (ptr != 0)
    {
        SLL *del = *ptr;
        int c = 1;
        while (del)
        {
            *ptr = del->next;
            printf("%d Nodes are Deleted\n", c++);
            sleep(2);
            free(del);
            del = *ptr;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n");
        return;
    }
}
/*====================== 9.Stud_Rev  ====================*/
void stud_rev(SLL **ptr)
{
    if (*ptr != 0)
    {
        int i = 0, c = stud_count(*ptr);
        if (c > 1)
        {
            SLL **a, *b = *ptr;
            a = malloc(sizeof(SLL *) * c);
            while (b)
            {
                a[i++] = b;
                b = b->next;
            }
            for (i = 1; i < c; i++)
            {
                a[i]->next = a[i - 1];
            }
            a[0]->next = 0;
            *ptr = a[c - 1];
            free(a);
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n");
        return;
    }
}
/*====================== 10.Stud_Count  ====================*/
int stud_count(SLL *ptr)
{
    int c = 0;
    if (ptr != 0)
    {
        while (ptr)
        {
            c++;
            ptr = ptr->next;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n");
        return 0;
    }
    return c;
}
/*====================== 11.Stud_Search  ====================*/
void search_node(SLL *ptr)
{
    if (ptr != 0)
    {
        SLL *p = ptr;
        int f = 0;
        char op;

        printf("\033[34mR.To_Search_Roll No \tN.To_Search_Name \tP.To_Search_Percentage \033[0m \n");
        scanf(" %c", &op);
        switch (op)
        {
        case 'r':
            int rn;
            printf("Enter the Roll number to search \n");
            scanf("%d", &rn);
            while (p)
            {
                if (rn == p->rollNo)
                {
                    printf("%d  %s  %.2f %%\n", p->rollNo, p->name, p->marks);
                    f++;
                }
                p = p->next;
            }
            if (f == 0)
            {
                printf("\033[31m Warning: No Data Found..!  \033[0m \n");
                return;
            }
            break;
        case 'n':
            char na[15];

            printf("Enter the Name to search \n");
            scanf("%s", &na);
            while (p)
            {
                if (strcmp(na, p->name) == 0)
                {
                    printf("%d  %s  %.2f %%\n", p->rollNo, p->name, p->marks);
                    f++;
                }
                p = p->next;
            }
            if (f == 0)
            {
                printf("\033[31m Warning: No Data Found..!  \033[0m \n");
                return;
            }
            break;
        case 'p':
            float mrks;
            printf("Enter the Marks to search \n");
            scanf("%f", &mrks);
            while (p)
            {
                if (mrks == p->marks)
                {
                    printf("%d  %s  %.2f %%\n", p->rollNo, p->name, p->marks);
                    f++;
                }
                p = p->next;
            }
            if (f == 0)
            {
                printf("\033[31m Warning: No Data Found..!  \033[0m \n");
                return;
            }
            break;

        default:
            printf("\033[31m Warning: Worng_Choice  \033[0m \n");
            break;
        }
    }
    else
    {
        printf("\033[31m Warning: No Data Found..!  \033[0m \n");
        return;
    }
}
