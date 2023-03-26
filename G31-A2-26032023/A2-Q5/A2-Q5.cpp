/// Utilize c++'s standard thread library to perform some statistical analysis on a list of numbers fed via command line arguments
#include <thread>
#include <list>
#include <iostream>
using namespace std;

// Globals
int globalMin;
int globalMax;
double globalMean;

// function declarations
void findMax(list<int> numbers);
void findMin(list<int> numbers);
void findMean(list<int> numbers);

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        cerr << "Must pass at least one integer command line argument" << endl;
        return 1;
    }
    list<int> numbers;

    //add each command line argument to our list
    for (int i = 1; i < argc; i++)
    {
        numbers.push_back(atoi(argv[i]));
    }
    //define threads for our tasks
    thread maxThread(findMax, numbers);
    thread minThread(findMin, numbers);
    thread meanThread(findMean, numbers);

    //startup threads
    maxThread.join();
    minThread.join();
    meanThread.join();

    //the threads will have prepared our global variables with the values they need
    cout << "Minimum number is " << globalMin << endl;
    cout << "Maximum number is " << globalMax << endl;
    cout << "Mean number is " << globalMean << endl;
    return 0;
}

// find the average of a list of numbers
void findMean(list<int> numbers) {
    double sum = 0;
    for (const auto& number : numbers)
    {
        sum += number;
    }
    globalMean = sum / numbers.size();
}

// find the smallest number in a list
void findMin(list<int> numbers) {
    int min = numbers.front();
    for (const auto& number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
    }
    globalMin =  min;
}

// find the largest number in a list
void findMax(list<int> numbers) {
    int max = numbers.front();
    for (const auto& number : numbers)
    {
        if (number > max)
        {
            max = number;
        }
    }
    globalMax = max;
}