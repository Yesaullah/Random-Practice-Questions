#include <iostream>
#include <cmath>
using namespace std;

class StatisticalAnalyzer{
    public:
    static double ComputeAverage(double arr[], int size){
        double sum = 0;
        int i;
        for(i=0; i<size; i++){
            sum += arr[i];
        }
        double average = sum/size;
        return average;
    }

    double CalculateStandardDeviation(double arr[], int size){
        double mean;
        mean = ComputeAverage(arr, size);
        cout<<"Mean: "<<mean<<endl;
        int i;
        double temp=0;
        for(i=0; i<size; i++){
            temp += (arr[i]-mean)*(arr[i]-mean);
        }
        double deviation = sqrt(temp / (size-1));
        return deviation;
    }
};
int main(){
    StatisticalAnalyzer A1;
    double array[] = {23.5, 45.6, 34.5, 237.7, 98};
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"Standard Deviation = "<<A1.CalculateStandardDeviation(array, size);
}
