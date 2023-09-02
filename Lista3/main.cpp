#include <iostream>
#include <vector>

using namespace std;

void pim_game(){
    for (int i=1; i<=50; ++i){
        if (i%4 == 0){
            cout << "PIM \n";
        }else{
            cout << i << endl;
        }
    }
}


double calculateMean(const vector<int> &values) {
    int total = 0;
    for( int value: values){
        total += value;
    }
    double mean = static_cast<double>(total) / values.size();
    return mean;
}


int sumEvenNumber(const vector<int>& values){
    int evenSum = 0;
    for (int value : values){
        if(value%2 == 0){
            evenSum += value;
        }
    }
    return evenSum;
}


int higherInvestment(double investmentJhon, double rateJhon, double investmentMary,double rateMary){
    int months = 0;
    while(investmentMary <= investmentJhon){
        investmentJhon += investmentJhon * (rateJhon / 100.0);
        investmentMary += investmentMary * (rateMary / 100.0);
        months++;
    }
    return months;
}


long long calculateFactorial(int number){
    if(number == 0 || number ==1){
        return 1;
    }else{
        return number * calculateFactorial(number - 1);
    }
}


int main()
{
    int opc = -1;

    do {
        cout << "1-PIM Game \n";
        cout << "2-Calculate mean \n";
        cout << "3-Sum of even numbers \n";
        cout << "4-Months until higher investment \n";
        cout << "5-Calculate factorial \n";
        cout << "Choose an option: ";
        cin >> opc;

        if (opc == 1){
            pim_game();
            break;

        } else if(opc == 2){
            vector<int> values;

            for (int i = 0; i < 20; ++i) {
                int value;
                cout << "Enter the " << i + 1 << "th integer value: ";
                cin >> value;
                values.push_back(value);
            }

            double calculatedMean = calculateMean(values);
            cout << "The mean of the values is: " << fixed << calculatedMean << endl;
            break;

        }else if(opc == 3){
            int numCount;
            cout << "Enter the number of values you want to input: ";
            cin >> numCount;

            vector<int> values;
            for(int i=0; i<numCount; ++i){
                int value;
                cout << "Enter value " << i+1 << ": ";
                cin >> value;
                values.push_back(value);
            }
            int evenSum = sumEvenNumber(values);
            cout << "The sum of even numbers is: " << evenSum << endl;
            break;

        }else if(opc == 4){
            double investmentJhon = 1000.0;
            double rateJhon = 0.5;
            double investmentMary = 100.0;
            double rateMary = 1.0;

            int months = higherInvestment(investmentJhon, rateJhon, investmentMary, rateMary);
            cout << "Maria will have more money than João in " << months << " months." << endl;
            break;

        }else if(opc == 5){
            int number;

            cout << "Enter a number to calculate it factorial: ";
            cin >> number;

            if(number<0){
                cout << "Factorial is not defined for negative numbers." << endl;
            }else{
                long long factorial = calculateFactorial(number);
                cout << "The factorial of " << number << " is: " << factorial << endl;
                break;

            }

        }





    } while (opc != 0);

    return 0;
}
