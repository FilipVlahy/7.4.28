#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int strana_susediaca_na_zvazku(unsigned int page, unsigned int no_pages, unsigned int bundle_size)
{    
    unsigned int one_sheet=bundle_size*4;
    unsigned int empty_pages_added=0;

    while (no_pages % one_sheet != 0)
    {
        no_pages++;
        empty_pages_added++;
    }
    if (empty_pages_added!=0)
        printf("Total number of pages has been changed.\n%u empty pages have been added to balance your book by bundle_size.\n", empty_pages_added);

    double no_sheets=no_pages/(bundle_size*4);
    unsigned int sheet[one_sheet];

    
    unsigned int next=0;
    unsigned int start=1;
    unsigned int end=bundle_size*4;


    unsigned int book[(int)no_sheets][one_sheet/2][2];

    //memset(book,0,sizeof(book));

    int i=0;

    for (int j=0;j<one_sheet;j++)
    {
        sheet[j]= end;
        sheet[j+1]= start;

        end--;
        start++;
        j++;
    }

    int p=0;

    for (int j=0;j< one_sheet/2;j++)
    {
        book[i][j][0]=sheet[p];
        book[i][j][1]=sheet[p+1];
        p+=2;
    }

    for (int j=0;j< one_sheet;j++)
    {
        if (book[i][j][0]==page)
        {
            next = book[i][j][1];

            return next;
            break;
        }
        if (book[i][j][1]==page)
        {
            next = book[i][j][0];

            return next;
            break;
        }
    }

    start=1;
    end=one_sheet;

    for (i=1;i<no_sheets;i++)
    {    
        start+=one_sheet;
        end+=one_sheet;

        for (int j=0;j<one_sheet;j++)
        {
            sheet[j]= end;
            sheet[j+1]= start;

            end--;
            start++;
            j++;
        }

        int p=0;

        for (int j=0;j< one_sheet/2;j++)
        {
            book[i][j][0]=sheet[p];
            book[i][j][1]=sheet[p+1];
            p+=2;
        }
    
        for (int j=0;j< one_sheet;j++)
        {
            if (book[i][j][0]==page)
            {
                next = book[i][j][1];

                return next;
                break;
            }
            if (book[i][j][1]==page)
            {
                next = book[i][j][0];

                return next;
                break;
            }
        }

    }

    return next;
}

int main(void)
{
    unsigned int page, no_pages, bundle_size;

    page = 1;
    no_pages = 16;
    bundle_size = 4;

    printf("Sused pre %u je %u", page,strana_susediaca_na_zvazku(page,no_pages,bundle_size));

    return 0;
}