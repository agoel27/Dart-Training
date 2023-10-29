// You will start out with 𝑀 points. 
// If you hit a sector with 𝑝𝑖 points, he will then subtract 𝑝𝑖 points from your score. 
// However, in the event that you hit a sector that makes you subtract more points than you currently have, you must reset your points to 𝑀
// and continue throwing the rest of your darts. The goal is to minimize your score as much as possible.

// You may hit the same sector multiple times. You may also miss the target on purpose. If you miss, you will not subtract anything from your score.

// Input
// The first line contains 𝑁 (1≤𝑁≤1000), which is the number of sectors in the dartboard and 
// 𝑀 (1≤𝑀≤108) which is the initial number of points that Leonard has.

// The next 𝑁 lines each contain an integer 𝑝𝑖 (1≤𝑝𝑖≤108) which represents the number of points that Leonard can subtract by hitting the 𝑖-th sector.

// Output
// Your output should be 4 integers which represent what sector on the dartboard that each of Leonard's darts hit. 
// In the case that you miss, output a 0.

// Note that the output does not have to be sorted. If there are multiple sectors with the same point value, you may output any of them.

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int numSectors = 0;
    cin >> numSectors;

    int leonardPoints = 0;
    cin >> leonardPoints;

    vector<int> v(numSectors+1);
    v[0] = 0;

    for(int i=1; i<numSectors+1; i++) {
        cin >> v[i];
    }

    int sector1, sector2, sector3, sector4 = -1;
    int minDiff = INT_MAX;
    for(int i=0; i<numSectors+1; i++) {
        for(int j=0; j<numSectors+1; j++) {
            for(int k=0; k<numSectors+1; k++) {
                for(int l=0; l<numSectors+1; l++) {
                    int difference = leonardPoints - (v[i]+v[j]+v[k]+v[l]);
                    //std::cout << difference << " " << i << " " << j << " " << k << " " << l << "\n";
                    if(difference >= 0 && difference < minDiff) {
                        sector1 = i;
                        sector2 = j;
                        sector3 = k;
                        sector4 = l;
                        //std::cout << difference << " " << sector1 << " " << sector2 << " " << sector3 << " " << sector4 << "\n";
                        minDiff = difference;
                    }
                }
            }
        }
    }

    std::cout << sector1 << " " << sector2 << " " << sector3 << " " << sector4 << "\n";
}