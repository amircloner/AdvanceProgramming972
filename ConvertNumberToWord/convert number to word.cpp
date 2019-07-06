#include <iostream>
#include<string.h>
using namespace std;

long long int sad(long long int);
long long int hezar(long long int);
long long int million(long long int);
long long int milyard(long long int);

int main()
{

    long long int number;
    cin>>number;
    long long int tmp=number;
    int i=0;

    long long int swap =number;
    long long int tenth_digit=swap/1000000000;
    swap=swap%1000000000;
    long long int ninth_digit=swap/100000000;
    swap=swap%100000000;
    long long int eighth_digit=swap/10000000;
    swap=swap%10000000;
    long long int seventh_digit=swap/1000000;
    swap=swap%1000000;
    long long int sixth_digit=swap/100000;
    swap=swap%100000;
    long long int fifth_digit=swap/10000;
    swap=swap%10000;
    long long int fourth_digit=swap/1000;
    swap=swap%1000;
    long long int third_digit=swap/100;
    swap=swap%100;
    long long int second_digit=swap/10;
    swap=swap%10;
    long long int first_digit=swap;


    while(tmp!=0)
    {
        tmp=tmp/10;
        i++;
    }

    if (i<=3)
    {
        sad(number);
    }
    else if(3<i && i<=6)
    {
        int hez=number/1000;
        hezar(hez);

        if (third_digit==0 && second_digit==0 && first_digit==0)
            cout<<" hezar";
        else{
            cout<<" hezar o ";
            int sa=number%1000;
            sad(sa);}
    }
    else if(6<i && i<=9)
    {
        int mil = number/1000000;
        million(mil);

        if (third_digit==0 && second_digit==0 && first_digit==0 && fourth_digit==0 && fifth_digit==0 && sixth_digit==0)
            cout<<" milioon";
        else{
            cout<<" milioon o ";

        int  hez = number%1000000;
        hez = hez /1000;
        hezar(hez);
        ///************************************************************
        if (fourth_digit!=0 && fifth_digit!=0 && sixth_digit!=0){
        if (third_digit==0 && second_digit==0 && first_digit==0)
            cout<<" hezar";
        else{
            cout<<" hezar o ";}}
        int  sa = number%1000000;
        sa = sa %1000;
        sad(number);}
    }
    else if(9<i && i<=12)
    {
        int mily=number/1000000000;

        milyard(mily);

        if (third_digit==0 && second_digit==0 && first_digit==0 && fourth_digit==0 && fifth_digit==0 && sixth_digit==0 && seventh_digit==0 && eighth_digit==0 && ninth_digit==0)
            cout<<" milyard";
        else{
            cout<<" milyard o ";

        int mil = number%1000000000;
        mil=mil/1000000;

        million(mil);


        if (third_digit==0 && second_digit==0 && first_digit==0 && fourth_digit==0 && fifth_digit==0 && sixth_digit==0)
            cout<<" milioon";
        else if (seventh_digit!=0 || eighth_digit!=0 || ninth_digit!=0){
            cout<<" milioon o ";

        int hez = number%1000000000;
        hez=hez%1000000;
        hez=hez/1000;
        hezar(hez);


        if (third_digit==0 && second_digit==0 && first_digit==0)
            cout<<" hezar";
        else if(fourth_digit!=0 || fifth_digit!=0 || sixth_digit!=0){
            cout<<" hezar o ";}}}

        int sa = number%1000000000;
        sa=sa%1000000;
        sa=sa%1000;
        sad(sa);

    }


return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////////////




long long int sad(long long int number)
{
long long int swap =number;
long long int third_digit=swap/100;
swap=swap%100;
long long int second_digit=swap/10;
swap=swap%10;
long long int first_digit=swap;
///

        switch(third_digit)
        {
            case 1:
                if (second_digit==0 && first_digit==0)
                    cout<<"sad";
                else
                    cout<<"sad o ";
                break;
            case 2:
                if (second_digit==0 && first_digit==0)
                    cout<<"devist";
                else
                    cout<<"devist o ";
                break;
            case 3:
                if (second_digit==0 && first_digit==0)
                    cout<< "sisad";
                else
                    cout<< "sisad o ";
                break;
            case 4:
                if (second_digit==0 && first_digit==0)
                    cout<<"charsad";
                else
                    cout<<"charsad o ";
                break;
            case 5:
                if (second_digit==0 && first_digit==0)
                    cout<<"pansad";
                else
                    cout<<"pansad o ";
                break;
            case 6:
                if (second_digit==0 && first_digit==0)
                    cout<<"sheshsad";
                else
                    cout<<"sheshsad o ";
                break;
            case 7:
                if (second_digit==0 && first_digit==0)
                    cout<<"haftsad";
                else
                    cout<<"haftsad o ";
                break;
            case 8:
                if (second_digit==0 && first_digit==0)
                    cout <<"hahtsad";
                else
                    cout <<"hahtsad o ";
                break;
            case 9:
                if (second_digit==0 && first_digit==0)
                    cout <<"nohsad";
                else
                    cout <<"nohsad o ";
                break;
        }

        if(second_digit==1)
    {
        switch(first_digit)
        {
            case 1:
                cout<<"yazdah";
                break;
            case 2:
                cout<<"davazdah";
                break;
            case 3:
                cout<<"sizdah";
                break;
            case 4:
                cout<<"chardah";
                break;
            case 5:
                cout<<"panzdah";
                break;
            case 6:
                cout<<"shanzdah";
                break;
            case 7:
                cout<<"hefdah";
                break;
            case 8:
                cout<<"hejdah";
                break;
            case 9:
                cout<<"noozdah";
                break;
        }
    }
    {
        switch(second_digit)
        {
            case 1:
                if(first_digit == 0)
                    cout<<"dah";
                break;
            case 2:
                if(first_digit == 0)
                    cout<<"bist";
                else
                    cout<<"bist o ";
                break;
            case 3:
                if(first_digit == 0)
                    cout<< "si";
                else
                    cout<<"si o ";
                break;
            case 4:
                if(first_digit == 0)
                    cout<<"chehel";
                else
                    cout<<"chehel o ";
                break;
            case 5:
                if(first_digit == 0)
                    cout<<"panjah";
                else
                    cout<<"panjah o ";
                break;
            case 6:
                if(first_digit == 0)
                    cout<<"shast";
                else
                    cout<<"shast o ";
                break;
            case 7:
                if(first_digit == 0)
                    cout<<"haftad";
                else
                    cout<<"haftad o ";
                break;
            case 8:
                if(first_digit == 0)
                    cout <<"hashtad";
                else
                    cout <<"hashtad o ";
                break;
            case 9:
                if(first_digit == 0)
                    cout<<"navad";
                else
                    cout<<"navad o ";
        }
        if(second_digit!=1)
        switch(first_digit)
        {
            case 1:
                cout<<"yek";
                break;
            case 2:
                cout<<"do";
                break;
            case 3:
                cout<<"se";
                break;
            case 4:
                cout<<"char";
                break;
            case 5:
                cout<<"panj";
                break;
            case 6:
                cout<<"shesh";
                break;
            case 7:
                cout<<"haft";
                break;
            case 8:
                cout<<"hasht";
                break;
            case 9:
                cout<<"noh";
                break;
            default:
                break;
        }
    }
return 0;
///
}


/////////////////////////////////////////////////////////////////////////////////////////////////////



long long int hezar(long long int number)
{

long long int swap =number;
long long int third_digit=swap/100;
swap=swap%100;
long long int second_digit=swap/10;
swap=swap%10;
long long int first_digit=swap;
///

        switch(third_digit)
        {
            case 1:
                if (second_digit==0 && first_digit==0)
                    cout<<"sad";
                else
                    cout<<"sad o ";
                break;
            case 2:
                if (second_digit==0 && first_digit==0)
                    cout<<"devist";
                else
                    cout<<"devist o ";
                break;
            case 3:
                if (second_digit==0 && first_digit==0)
                    cout<< "sisad";
                else
                    cout<< "sisad o ";
                break;
            case 4:
                if (second_digit==0 && first_digit==0)
                    cout<<"charsad";
                else
                    cout<<"charsad o ";
                break;
            case 5:
                if (second_digit==0 && first_digit==0)
                    cout<<"pansad";
                else
                    cout<<"pansad o ";
                break;
            case 6:
                if (second_digit==0 && first_digit==0)
                    cout<<"sheshsad";
                else
                    cout<<"sheshsad o ";
                break;
            case 7:
                if (second_digit==0 && first_digit==0)
                    cout<<"haftsad";
                else
                    cout<<"haftsad o ";
                break;
            case 8:
                if (second_digit==0 && first_digit==0)
                    cout <<"hahtsad";
                else
                    cout <<"hahtsad o ";
                break;
            case 9:
                if (second_digit==0 && first_digit==0)
                    cout <<"nohsad";
                else
                    cout <<"nohsad o ";
                break;
        }

        if(second_digit==1)
    {
        switch(first_digit)
        {
            case 1:
                cout<<"yazdah";
                break;
            case 2:
                cout<<"davazdah";
                break;
            case 3:
                cout<<"sizdah";
                break;
            case 4:
                cout<<"chardah";
                break;
            case 5:
                cout<<"panzdah";
                break;
            case 6:
                cout<<"shanzdah";
                break;
            case 7:
                cout<<"hefdah";
                break;
            case 8:
                cout<<"hejdah";
                break;
            case 9:
                cout<<"noozdah";
                break;
        }
    }
    {
        switch(second_digit)
        {
            case 1:
                if(first_digit == 0)
                    cout<<"dah";
                break;
            case 2:
                if(first_digit == 0)
                    cout<<"bist";
                else
                    cout<<"bist o ";
                break;
            case 3:
                if(first_digit == 0)
                    cout<< "si";
                else
                    cout<<"si o ";
                break;
            case 4:
                if(first_digit == 0)
                    cout<<"chehel";
                else
                    cout<<"chehel o ";
                break;
            case 5:
                if(first_digit == 0)
                    cout<<"panjah";
                else
                    cout<<"panjah o ";
                break;
            case 6:
                if(first_digit == 0)
                    cout<<"shast";
                else
                    cout<<"shast o ";
                break;
            case 7:
                if(first_digit == 0)
                    cout<<"haftad";
                else
                    cout<<"haftad o ";
                break;
            case 8:
                if(first_digit == 0)
                    cout <<"hashtad";
                else
                    cout <<"hashtad o ";
                break;
            case 9:
                if(first_digit == 0)
                    cout<<"navad";
                else
                    cout<<"navad o ";
        }
        if(second_digit!=1)
        switch(first_digit)
        {
            case 1:
                cout<<"yek";
                break;
            case 2:
                cout<<"do";
                break;
            case 3:
                cout<<"se";
                break;
            case 4:
                cout<<"char";
                break;
            case 5:
                cout<<"panj";
                break;
            case 6:
                cout<<"shesh";
                break;
            case 7:
                cout<<"haft";
                break;
            case 8:
                cout<<"hasht";
                break;
            case 9:
                cout<<"noh";
                break;
            default:
                break;
        }
    }
return 0;
///
}


////////////////////////////////////////////////////////////////////////////////////////////////////


long long int million(long long int number)
{

long long int swap =number;
long long int third_digit=swap/100;
swap=swap%100;
long long int second_digit=swap/10;
swap=swap%10;
long long int first_digit=swap;
///

        switch(third_digit)
        {
            case 1:
                if (second_digit==0 && first_digit==0)
                    cout<<"sad";
                else
                    cout<<"sad o ";
                break;
            case 2:
                if (second_digit==0 && first_digit==0)
                    cout<<"devist";
                else
                    cout<<"devist o ";
                break;
            case 3:
                if (second_digit==0 && first_digit==0)
                    cout<< "sisad";
                else
                    cout<< "sisad o ";
                break;
            case 4:
                if (second_digit==0 && first_digit==0)
                    cout<<"charsad";
                else
                    cout<<"charsad o ";
                break;
            case 5:
                if (second_digit==0 && first_digit==0)
                    cout<<"pansad";
                else
                    cout<<"pansad o ";
                break;
            case 6:
                if (second_digit==0 && first_digit==0)
                    cout<<"sheshsad";
                else
                    cout<<"sheshsad o ";
                break;
            case 7:
                if (second_digit==0 && first_digit==0)
                    cout<<"haftsad";
                else
                    cout<<"haftsad o ";
                break;
            case 8:
                if (second_digit==0 && first_digit==0)
                    cout <<"hahtsad";
                else
                    cout <<"hahtsad o ";
                break;
            case 9:
                if (second_digit==0 && first_digit==0)
                    cout <<"nohsad";
                else
                    cout <<"nohsad o ";
                break;
        }

        if(second_digit==1)
    {
        switch(first_digit)
        {
            case 1:
                cout<<"yazdah";
                break;
            case 2:
                cout<<"davazdah";
                break;
            case 3:
                cout<<"sizdah";
                break;
            case 4:
                cout<<"chardah";
                break;
            case 5:
                cout<<"panzdah";
                break;
            case 6:
                cout<<"shanzdah";
                break;
            case 7:
                cout<<"hefdah";
                break;
            case 8:
                cout<<"hejdah";
                break;
            case 9:
                cout<<"noozdah";
                break;
        }
    }
    {
        switch(second_digit)
        {
            case 1:
                if(first_digit == 0)
                    cout<<"dah";
                break;
            case 2:
                if(first_digit == 0)
                    cout<<"bist";
                else
                    cout<<"bist o ";
                break;
            case 3:
                if(first_digit == 0)
                    cout<< "si";
                else
                    cout<<"si o ";
                break;
            case 4:
                if(first_digit == 0)
                    cout<<"chehel";
                else
                    cout<<"chehel o ";
                break;
            case 5:
                if(first_digit == 0)
                    cout<<"panjah";
                else
                    cout<<"panjah o ";
                break;
            case 6:
                if(first_digit == 0)
                    cout<<"shast";
                else
                    cout<<"shast o ";
                break;
            case 7:
                if(first_digit == 0)
                    cout<<"haftad";
                else
                    cout<<"haftad o ";
                break;
            case 8:
                if(first_digit == 0)
                    cout <<"hashtad";
                else
                    cout <<"hashtad o ";
                break;
            case 9:
                if(first_digit == 0)
                    cout<<"navad";
                else
                    cout<<"navad o ";
        }
        if(second_digit!=1)
        switch(first_digit)
        {
            case 1:
                cout<<"yek";
                break;
            case 2:
                cout<<"do";
                break;
            case 3:
                cout<<"se";
                break;
            case 4:
                cout<<"char";
                break;
            case 5:
                cout<<"panj";
                break;
            case 6:
                cout<<"shesh";
                break;
            case 7:
                cout<<"haft";
                break;
            case 8:
                cout<<"hasht";
                break;
            case 9:
                cout<<"noh";
                break;
            default:
                break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////


long long int milyard(long long int number)
{

long long int swap =number;
long long int third_digit=swap/100;
swap=swap%100;
long long int second_digit=swap/10;
swap=swap%10;
long long int first_digit=swap;
///

        switch(third_digit)
        {
            case 1:
                if (second_digit==0 && first_digit==0)
                    cout<<"sad";
                else
                    cout<<"sad o ";
                break;
            case 2:
                if (second_digit==0 && first_digit==0)
                    cout<<"devist";
                else
                    cout<<"devist o ";
                break;
            case 3:
                if (second_digit==0 && first_digit==0)
                    cout<< "sisad";
                else
                    cout<< "sisad o ";
                break;
            case 4:
                if (second_digit==0 && first_digit==0)
                    cout<<"charsad";
                else
                    cout<<"charsad o ";
                break;
            case 5:
                if (second_digit==0 && first_digit==0)
                    cout<<"pansad";
                else
                    cout<<"pansad o ";
                break;
            case 6:
                if (second_digit==0 && first_digit==0)
                    cout<<"sheshsad";
                else
                    cout<<"sheshsad o ";
                break;
            case 7:
                if (second_digit==0 && first_digit==0)
                    cout<<"haftsad";
                else
                    cout<<"haftsad o ";
                break;
            case 8:
                if (second_digit==0 && first_digit==0)
                    cout <<"hahtsad";
                else
                    cout <<"hahtsad o ";
                break;
            case 9:
                if (second_digit==0 && first_digit==0)
                    cout <<"nohsad";
                else
                    cout <<"nohsad o ";
                break;
        }

        if(second_digit==1)
    {
        switch(first_digit)
        {
            case 1:
                cout<<"yazdah";
                break;
            case 2:
                cout<<"davazdah";
                break;
            case 3:
                cout<<"sizdah";
                break;
            case 4:
                cout<<"chardah";
                break;
            case 5:
                cout<<"panzdah";
                break;
            case 6:
                cout<<"shanzdah";
                break;
            case 7:
                cout<<"hefdah";
                break;
            case 8:
                cout<<"hejdah";
                break;
            case 9:
                cout<<"noozdah";
                break;
        }
    }
    {
        switch(second_digit)
        {
            case 1:
                if(first_digit == 0)
                    cout<<"dah";
                break;
            case 2:
                if(first_digit == 0)
                    cout<<"bist";
                else
                    cout<<"bist o ";
                break;
            case 3:
                if(first_digit == 0)
                    cout<< "si";
                else
                    cout<<"si o ";
                break;
            case 4:
                if(first_digit == 0)
                    cout<<"chehel";
                else
                    cout<<"chehel o ";
                break;
            case 5:
                if(first_digit == 0)
                    cout<<"panjah";
                else
                    cout<<"panjah o ";
                break;
            case 6:
                if(first_digit == 0)
                    cout<<"shast";
                else
                    cout<<"shast o ";
                break;
            case 7:
                if(first_digit == 0)
                    cout<<"haftad";
                else
                    cout<<"haftad o ";
                break;
            case 8:
                if(first_digit == 0)
                    cout <<"hashtad";
                else
                    cout <<"hashtad o ";
                break;
            case 9:
                if(first_digit == 0)
                    cout<<"navad";
                else
                    cout<<"navad o ";
        }
        if(second_digit!=1)
        switch(first_digit)
        {
            case 1:
                cout<<"yek";
                break;
            case 2:
                cout<<"do";
                break;
            case 3:
                cout<<"se";
                break;
            case 4:
                cout<<"char";
                break;
            case 5:
                cout<<"panj";
                break;
            case 6:
                cout<<"shesh";
                break;
            case 7:
                cout<<"haft";
                break;
            case 8:
                cout<<"hasht";
                break;
            case 9:
                cout<<"noh";
                break;
            default:
                break;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
