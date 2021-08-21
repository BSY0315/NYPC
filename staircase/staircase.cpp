#include <iostream>

using namespace std;

int main(void)
{
    int M, F, N;
    cin >> M >> F >> N;

    printf("%d", N / (M - 1) + 1);
    return 0;
}