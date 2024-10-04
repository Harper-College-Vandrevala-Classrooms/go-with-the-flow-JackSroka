#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class HeatFlow {
public:
    HeatFlow(int sections, double initialTemp, double k)
        : sections(sections), k(k), temp(sections, initialTemp) {}

    void setHeatSource(int sectionIndex, double temperature) {                                   // set heat to chosen section (first one in this case)
        if (sectionIndex >= 0 && sectionIndex < sections) {
            temp[sectionIndex] = temperature;
        }
    }

    void tick() {                                                                                // calculates temperature
        vector<double> newTemp = temp;

        for (int i = 1; i < sections - 1; ++i) {
            newTemp[i] = temp[i] + k * (temp[i + 1] - 2 * temp[i] + temp[i - 1]);
        }
        temp = newTemp;
    }

    void pretty_print() {                                                                        // prints out temperatures
        for (double& temp : temp) {
            cout << fixed << setprecision(2) << "| " << temp << " ";                             // puts dividers between the temps for each column
        }
        cout << "|" << endl;                                                                     // puts divider at the final temp for each column
    }

private:
    int sections;
    double k;
    vector<double> temp;
};

int main() {
    int sections = 8;
    double initialTemp = 30;
    double k = 0.4;
    cout << "--------------------------------------------------------------------" << endl;     // divider for first line of temps for each row
    HeatFlow heatFlow(sections, initialTemp, k);
    heatFlow.setHeatSource(0, 250);                                                             // Set heat source for first section
    heatFlow.pretty_print();

    for (int n = 0; n < 10; ++n) {                                                              // temp change over set time n
        cout << "--------------------------------------------------------------------" << endl; // top divider for each line of temps for each row
        cout << endl;
        heatFlow.tick();
        cout << endl;
        cout << "--------------------------------------------------------------------" << endl; // bottom divider for each line of temps for each row
        heatFlow.pretty_print();
    }
    cout << "--------------------------------------------------------------------" << endl;     // divider for last line of temps for each row

    return 0;
}