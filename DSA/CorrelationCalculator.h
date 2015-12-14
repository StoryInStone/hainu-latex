// =====================================================================================
// 
//       Filename:  StdDeviation.h
// 
//    Description:  
// 
//        Dersion:  1.0
//        Created:  12/08/2015 02:15:06 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Junxing Lu (SIS), StoryInStone@outlook.com
//        Company:  
// 
// =====================================================================================


#include <math.h>

#define D 100                                   // 最大样本数据


class StdDeviation
{
    private:
        int max;
        double value[D];
        double mean;
    public:
        double CalculateMean()
        {
            double sum = 0;
            for(int i = 0; i < max; i++)
                sum += value[i];
            return (sum / max);
        }
        double CalculateVariane()
        {
            mean = CalculateMean();
            double temp = 0;
            for(int i = 0; i < max; i++)
                temp += (value[i] - mean) * (value[i] - mean) ;
            return temp / max;
        }
        double CalculateSampleVariane()
        {
            mean = CalculateMean();
            double temp = 0;
            for(int i = 0; i < max; i++)
                temp += (value[i] - mean) * (value[i] - mean) ;
            return temp / (max - 1);
        }
        int SetValues(double *p, int count)
        {
            if(count > D)
                return -1;
            max = count;
            for(int i = 0; i < count; i++)
                value[i] = p[i];
            return 0;
        }
        double Calculate_StandardDeviation()
        {
            return sqrt(CalculateVariane());
        }
        double Calculate_SampleStandardDeviation()
        {
            return sqrt(CalculateSampleVariane());
        }
};

class Calculator
{
    private:
        double XSeries[D];
        double YSeries[D];
        int max;
        StdDeviation x;
        StdDeviation y;
    public:
        void SetValues(double *xvalues, double *yvalues, int count)
        {
            for(int i = 0; i < count; i++)
            {
                XSeries[i] = xvalues[i];
                YSeries[i] = yvalues[i];
            }
            x.SetValues(xvalues, count);
            y.SetValues(yvalues, count);
            max = count;
        }
        double Calculate_Covariance()
        {
            double xmean = x.CalculateMean();
            double ymean = y.CalculateMean();
            double total = 0;
            for(int i = 0; i < max; i++)
            {
                total += (XSeries[i] - xmean) * (YSeries[i] - ymean);
            }
            return total / max;
        }
        double Calculate_Correlation()
        {
            double cov = Calculate_Covariance();
            double correlation = cov / (x.Calculate_StandardDeviation() * y.Calculate_StandardDeviation());
            return correlation;
        }
};
