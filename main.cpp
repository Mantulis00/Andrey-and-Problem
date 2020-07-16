#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


double getProb(int n, vector<double> probs)
{
    double maxSum = 0;

    for (int x=0; x<=n; x++)
    {
        double k=1;
        for (int y=0; y<=n; y++)
        {
            if (x == y)
            {
                k*=probs[y];
            }
            else
            {
                k*=(1-probs[y]);
            }
        }
        maxSum += k;
    }

    return maxSum;
}


int main()
{
    double maxSum = 0, maxOverHalf = 0;
    double k;
    vector<double> probs1, probs2;
    int n;

    cin >> n;

    // inputs; sort probs that are less than half
    for (int x=0; x<n; x++)
    {
        cin >> k;
        if (k< 0.5)
            probs1.push_back(k);
        else
        {
            if (k > maxOverHalf) maxOverHalf = k;
        }
    }
    // sort less then halfs
    sort(probs1.begin(), probs1.end(), greater<double>());

    if (maxOverHalf == 0) // we cant get more than half from less then half sums
    {
       for (int x=0; x<probs1.size(); x++)
        {
            double k = getProb(x, probs1); // check if we add probability if sum goes up
            if (k > maxSum) maxSum = k;
            else break;
        }
        cout <<fixed<< setprecision(9)<< maxSum << endl;
    }
    else
        cout <<fixed<< setprecision(9)<< maxOverHalf << endl;




    return 0;
}
