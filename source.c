#include <stdio.h>
#include <stdlib.h>

unsigned int strana_susediaca_na_zvazku(unsigned int page, unsigned int no_pages, unsigned int bundle_size)
{
    unsigned int next=0;
    unsigned int one_sheet=bundle_size*4;
    unsigned int max_sheets=no_pages/one_sheet+1;
    unsigned int sheet=((page-1)/one_sheet)+1;

    unsigned int last_sheet_size=(((no_pages+1)%one_sheet)/2)*2;
    unsigned int page_in_sheet;
    unsigned int next_in_sheet;

    if (last_sheet_size==0)
        last_sheet_size=one_sheet;

    page_in_sheet=((page-1)%one_sheet)+1;

    if (sheet==max_sheets)
        next_in_sheet=last_sheet_size-page_in_sheet+1;
    else
        next_in_sheet=one_sheet-page_in_sheet+1;
    
    next=(sheet-1)*one_sheet+next_in_sheet;

    return next;
}

int main(void)
{
    unsigned int page, no_pages, bundle_size;

    page = 38;
    no_pages = 48;
    bundle_size = 4;

    printf("Sused pre %u je %u", page,strana_susediaca_na_zvazku(page,no_pages,bundle_size));

    return 0;
}