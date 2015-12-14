// =====================================================================================
// 
//       Filename:  main.cc
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  12/08/2015 03:48:31 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Junxing Lu (SIS), StoryInStone@outlook.com
//        Company:  
// 
// =====================================================================================

#include "./CorrelationCalculator.h"
#include "./FileDeal.cc"
#include "./Mst.h"
#include <math.h>


using namespace std;
int main() {
    Calculator calc;
    Mst m;
    double cor[V][V];
    vector<string> hs300;
    hs300 = GetShareCode();
    string share[V];
    for (vector<double>::size_type ix = 1; ix != hs300.size(); ++ix)
    {
        share[ix-1] = hs300[ix];
    }
    int count = hs300.size() - 1;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            double xvalues[I];
            double yvalues[I]; 
            vector<double> xv;
            vector<double> yv;
            xv = GetShareData(share[i]);
            yv = GetShareData(share[j]);
            for (vector<double>::size_type ix = 1; ix != xv.size(); ++ix)
            {
                xvalues[ix] = xv[ix];
            }
            for (vector<double>::size_type ix = 1; ix != yv.size(); ++ix)
            {
                yvalues[ix] = yv[ix];
            }
            calc.SetValues(xvalues, yvalues, I);
            cor[i][j] = fabs(calc.Calculate_Correlation());
        }
    }
    m.createGraph(cor);
    m.primMST();
    return 0;
}
