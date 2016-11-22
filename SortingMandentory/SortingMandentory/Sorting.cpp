#include "Sorting.h"



Sorting::Sorting(vector<int> sample)
{
	samples = sample;
}

Sorting::Sorting(vector<Point> samples) :
    points{ samples }
{}

bool Sorting::quadraticSort(int k)
{

	for (auto i : samples)
	{
		for (auto j : samples)
		{
			if (i + j == k)
			{
				return true;
			}
		}
	}
	
	return false;
}

void Sorting::sort()
{
	make_heap(samples.begin(), samples.end());
	sort_heap(samples.begin(), samples.end());
}

void Sorting::print()
{
	for (auto i : samples)
	{
        cout << i << ",";
	}
	cout << endl;
}

bool Sorting::linearSearch(int k)
{
	int front = 0;
	int back = samples.size() - 1;

	bool match = false;

	while(!match)
	{
		static int sum;
		sum = samples[front] + samples[back];

		if (front == back && sum != k)
			break;
		
		if (sum < k)
			front++;
		else if (sum > k)
			back--;
		else if (sum == k)
			return true;
	}
}

void Sorting::sortNFalseBeforeTrue()
{
    int front = 0;
    int back = samples.size() - 1;
    int temp;

    bool running = true;

    int count = 0;

    while(running)
    {
        count++;
        if (front == back)
            running = false;

        if (samples[front] == samples[back] && samples[front] == 0)
            front++;
        else if (samples[front] == samples[back] && samples[front] == 1)
            back--;
        else if (samples[front] > samples[back])
        {
            //if front > back
            temp = samples[front];
            samples[front] = samples[back];
            samples[back] = temp;
            
            front++;
        }
        else if (samples[front] < samples[back])
        {
            //case where front = 0, back = 1. Both is correct.
            front++;
        }
    }
    cout << "DEBUG: While loop repeated: " << count << " times. On vector with: " << samples.size() << " elements" << endl;
}

vector<Line> Sorting::findLinesBySortAndSlope()
{
    //Outer loop that goes though all points
    //Then calculates the slopes for all points from the selected point
    //when every slope is calculated from selected point, sort and see if more than 4 points have same slope. If they do there is a line, and you create a line object and append result list
   
    //result vector
    vector<Line> lines;

    for (auto fP = 0; fP < points.size(); fP++)
    {
        Point firstP = points[fP];
        for (int sP = 0; sP < points.size(); sP++)
        {
            //Can't calculate slope with itself
            if (sP == fP)
                continue;

            //select second point
            Point secondP = points[sP];
            double slope;
            if (secondP.x == firstP.x)
                slope = 10000; //infinity. Vertical line
            else
                slope = (double)(secondP.y - firstP.y) / (secondP.x - firstP.x);

            points[sP].slope = slope;
        }

        //All slopes have been calculated, now check if lines exists by sorting 
        sortPoints();

        //Can now go though and check if lines exist with more than 4 points
        
        //loop, while they have equal slope, add them to line object. 
        //When new slope appears, count objects on line vector. if > 4, save line, else discard line.        
        Line newL;
        for (int i = 0; i < points.size(); i++)
        {   
            static double firstSlope = points[i].slope;
            if (points[i].slope == firstSlope)
            {
                //add to line
                newL.addPoint(points[i]);
            }
            else
            {
                //new slope, check if line can be saved
                if (newL.getSize() >= 4)
                    lines.push_back(newL);

                //clear line to check for new slope
                newL.clear();

                //save new slope 
                firstSlope = points[i].slope;
                newL.addPoint(points[i]);
            }            
        }
    }
        return lines;
}

void Sorting::sortPoints()
{
    make_heap(points.begin(), points.end(), greaterP());
    sort_heap(points.begin(), points.end(), greaterP());
}

Sorting::~Sorting()
{
}
