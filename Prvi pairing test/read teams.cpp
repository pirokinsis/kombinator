#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class team
    {
            public:
            string name;
            int id;
            int klub;
            int active_flag;
    };


class debate
    {
        int prop;
        int opp;
        float prop_points;
        float opp_points;
    };


struct seed_redak
    {
        int id;
        int wins;
        float points;
    };


class tournament
    {
            public:
            int no_rounds;
            vector <debate> rounds[10];
            team teams[1000];
    };

seed_redak seed [1000];


int read_teams()
    {
        tournament t;
        string line;
        ifstream stream ("ekipe.txt");
        int i =0;
        while (getline(stream,line))
            {
                t.teams[i].name=line;
                t.teams[i].id=i;
                t.teams[i].active_flag=1;
                stream>>t.teams[i].klub;
                stream.ignore();
                cout<<t.teams[i].name<<" "<<t.teams[i].id<<" "<<t.teams[i].klub<<endl;
                i++;
            }
        return i;
    }

int main()
{
    printf ("\nread:%d",read_teams());
}



/*
    check constraints funkcija
    generate seed funkcija sort(s,s+5,cmp)

    random round funkcija
    high low round funkcija
    high high round funkcija
*/

bool cmp(seed_redak a, seed_redak b)
{
    if (a.wins==b.wins)
        {
            if (a.points==b.points) return a.id>b.id;
            else return a.points>b.points;
        }
    else return a.wins>b.wins;

}
