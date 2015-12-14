// =====================================================================================
// 
//       Filename:  FileDeal.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  12/08/2015 03:00:42 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Junxing Lu (SIS), StoryInStone@outlook.com
//        Company:  
// 
// =====================================================================================


#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#define I 13                                    // 股票数据样本容量
#define C 300                                   // 股票总数
using namespace std;

vector<double> GetShareData(string code)
{
    string line;
    string url = "./lnShare/"+code+".txt";
    const char *ch = url.c_str();
    ifstream file (ch);
    if (file.is_open())
    {
        getline(file, line);
    }
    file.close();
    for (unsigned int j=0; j<line.length(); j++)
    {
        if (line[j] == ',')
            line[j] = ' ';
    }
    vector<double> arr;
    string tmp;
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < I)
    {
        ssin >> tmp;
        arr.push_back(atof(tmp.c_str()));
        ++i;
    }
    return arr;
}

vector<string> GetShareCode()
{
    string line;
    ifstream file ("./hs300_code.txt");
    if (file.is_open())
    {
        getline(file, line);
    }
    file.close();
    for (unsigned int j=0; j<line.length(); j++)
    {
        if (line[j] == ',')
            line[j] = ' ';
    }
    vector<string> arr;
    string tmp;
    int i = 0;
    stringstream ssin(line);
    while (ssin.good() && i < C)
    {
        ssin >> tmp;
        arr.push_back(tmp);
        ++i;
    }
    return arr;
}
