#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 100000
using namespace std;

string arr[MAX];
pair<string, int> arr1[MAX];

int binery(int start, int end, const string& d)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr1[mid].first == d)
        {
            return arr1[mid].second;
        }
        else if (arr1[mid].first > d)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    string answer;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr1[i] = { arr[i], i };
    }
    sort(arr1, arr1 + N);

    for (int i = 0; i < M; i++)
    {
        cin >> answer;
        if (isdigit(answer[0]))
        {
            int index = stoi(answer) - 1;
            cout << arr[index] << '\n';
        }
        else
        {
            int index = binery(0, N - 1, answer);
            cout << index + 1 << '\n';
        }
    }
    return 0;
}