#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int>> arr) 
{
    int way_paving(vector<vector<int>> arr);
    return way_paving(arr);
}
int way_paving(vector<vector<int>> arr)
{
    int hourglass_obj(vector<vector<int>> arr, int i_center, int j_center);
    int max = INT_MIN;
    for(auto i = 1; i < (int)arr.size() - 1; i++)
    {
        for(auto j = 1; j < (int)arr.size() - 1; j++)
        {
            if(hourglass_obj(arr, i, j) > max) max = hourglass_obj(arr, i, j);
            /* hourglass illustration
            cout << arr[i - 1][j - 1] << " " << arr[i - 1][j] << " " << arr[i - 1][j + 1] << endl;
            cout << " " << arr[i][j] << " " << endl;
            cout << arr[i + 1][j - 1] << " " << arr[i + 1][j] << " " << arr[i + 1][j + 1] << endl;
            */
        }
    }

    /* applied center area
    vector<int> v;
    for(auto i = 1; i < (int)arr.size() - 1; i++)
    {
        v = arr[i];
        v.pop_back();
        v.erase(v.begin());
        for (auto j : v)
        {
        cout << j << ' ';
        }
        cout << endl;
    }
    */

    return max;
}

int hourglass_obj(vector<vector<int>> arr, int i_center, int j_center)
{
    int hg_center[] = {i_center, j_center};

    // accumulates range [first, last)
    int sum = 
    {
        accumulate \
        (arr[hg_center[0] - 1].begin() + hg_center[1] - 1,
        arr[hg_center[0] - 1].begin() + hg_center[1] + 2, 0) + \
        accumulate \
        (arr[hg_center[0] + 1].begin() + hg_center[1] - 1, 
        arr[hg_center[0] + 1].begin() + hg_center[1] + 2, 0) + \
        arr[hg_center[0]][hg_center[1]]
    };
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
