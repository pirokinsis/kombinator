#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

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
        public:
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


            int no_rounds;
            vector <debate> rounds[10];
            team teams[1000];

seed_redak seed [1000];


int read_teams()
    {
        string line;
        ifstream stream ("ekipe.txt");
        int i =0;
        while (getline(stream,line))
            {
                teams[i].name=line;
                teams[i].id=i;
                teams[i].active_flag=1;
                stream>>teams[i].klub;
                stream.ignore();
                cout<<teams[i].name<<" "<<teams[i].id<<" "<<teams[i].klub<<endl;
                i++;
            }
        return i;

    }

bool check_constraint (team a,team b)
{
	if (a.klub==b.klub) return true;
	for (int i=0;i<no_rounds;i++)
	{
		for (int j=0;j<rounds[i].size();j++)
			{
			if ((a.id==rounds[i][j].prop) and (b.id==rounds[i][j].opp)) return true;
			if ((a.id==rounds[i][j].opp) and (b.id==rounds[i][j].prop)) return true;
			}
	}

	return false;
}



bool cmp(seed_redak a, seed_redak b)
{
    if (a.wins==b.wins)
        {
            if (a.points==b.points) return a.id>b.id;
            else return a.points>b.points;
        }
    else return a.wins>b.wins;

}






int main()
{

}



/*
    +check constraints funkcija
            - fali side contraint !!!!!!!!!!!!!
    generate seed funkcija sort(s,s+5,cmp)

    random round funkcija
    high low round funkcija
    high high round funkcija
*/

