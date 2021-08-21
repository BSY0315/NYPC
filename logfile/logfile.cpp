#include <iostream>

using namespace std;

typedef struct element
{
    int time;
    int start_or_end;
    bool not_start;
} element;

element log_files[101];
bool is_error = false;

int main(void)
{
    int userCount, recordCount;
    cin >> userCount >> recordCount;

    for (size_t i = 1; i <= userCount; i++)
    {
        log_files[i].not_start = true;
    }
    for (size_t i = 0; i < recordCount; i++)
    {
        int t, u, b;
        cin >> t >> u >> b;
        if (log_files[u].not_start)
        {
            log_files[u].time = t;
            if (b == 1)
            {
                is_error = true;
            }
            log_files[u].start_or_end = b;
            log_files[u].not_start = false;
        }
        else
        {
            if (t - log_files[u].time < 60 || log_files[u].start_or_end == b)
            {
                is_error = true;
            }
            log_files[u].time = t;
            log_files[u].start_or_end = b;
        }
    }

    for (size_t i = 1; i <= userCount; i++)
    {
        if (!log_files[i].not_start && log_files[i].start_or_end == 0)
        {
            is_error = true;
        }
    }
    is_error ? cout << "NO" : cout << "YES";
    return 0;
}