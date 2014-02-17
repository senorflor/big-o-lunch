#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// could be more efficient here by passing pointer to output vector instead of returning it
vector<unsigned int> buildSolution(unsigned int start, const unsigned int k) {
    vector<unsigned int> sol;

    unsigned int end = start + k;
    for(unsigned int i = start; i < end; i++) {
        sol.push_back(i);
    }

   return sol;
}

// assumes non-empty vector
vector<unsigned int> minfree(vector<unsigned int> &v, const unsigned int k) {
    sort(v.begin(), v.end());

    // check if it fits at the beginning
    if(k <= v[0]) {
         return buildSolution(0, k);
    }

    //  see if it fits in the middle
    for(unsigned int i = 0; i < v.size() - 1; i++) {
        int diff = v[i + 1] - v[i];

        if(k < diff) {
            return buildSolution(v[i] + 1, k);
        }
    }

    // else it must be at the end
    unsigned int lastVal = v[v.size() - 1];
    return buildSolution(lastVal + 1, k);
}

void printVector(vector<unsigned int> vec) {
    cout << "{ ";

    for(auto v : vec) {
        cout << v << " ";
    }

    cout << "}" << endl;
}

int main () {
    // didn't want to bother parsing input...
    vector<unsigned int> v0 = { 2, 3, 1 };
    vector<unsigned int> v1 = { 4, 5, 2, 0 };
    vector<unsigned int> v2 = { 5, 1 };

    printVector(minfree(v0, 1));
    printVector(minfree(v1, 2));
    printVector(minfree(v2, 3));
    
    return 0;
}

