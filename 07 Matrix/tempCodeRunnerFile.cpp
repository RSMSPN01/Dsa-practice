for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(arr[i][j], arr[n - j - 1][i]);
        }
    }