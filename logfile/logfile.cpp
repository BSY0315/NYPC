#include <iostream>

using namespace std;

#define START (0)
#define END (1)

typedef struct element
{
    int time;
    int start_or_end;
    bool not_start;
} element;

element log_files[201];
bool is_error = false;

int main(void)
{
    int usercount, recordcount;
    cin >> usercount >> recordcount;

    for (size_t i = 1; i <= usercount; i++)
    {
        log_files[i].not_start = true;
    }
    for (size_t i = 0; i < recordcount; i++)
    {
        int t, u, b;
        cin >> t >> u >> b;
        if (!is_error)
        {
            if (log_files[u].not_start)
            {
                log_files[u].time = t;
                if (b == END)
                {
                    is_error = true;
                }
                log_files[u].start_or_end = b;
                log_files[u].not_start = false;
            }
            else
            {
                if (log_files[u].start_or_end == b)
                {
                    is_error = true;
                }
                else if (t - log_files[u].time < 60 && b == END)
                {
                    is_error = true;
                }
                log_files[u].time = t;
                log_files[u].start_or_end = b;
            }
        }
    }

    for (size_t i = 1; i <= usercount; i++)
    {
        if (!log_files[i].not_start && log_files[i].start_or_end == START)
        {
            is_error = true;
        }
    }
    cout << (is_error ? "NO" : "YES");
    return 0;
}