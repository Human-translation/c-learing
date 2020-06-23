class Solution {
public:
    void Init(vector<vector<int>>& arr, vector<vector<int>> image, int Length, int Width)
    {
        for (int i = 0; i < Length + 2; i++)
        {
            arr[i].resize(Width + 2);
        }
    }

    int MyAdd(vector<vector<int>> num,int i,int j)
    {
        int count = 0;
        if (i - 1 >= 0 && j - 1 >= 0 && num[i - 1][j - 1] == 1)
            count++;
        if (i - 1 >= 0 && num[i - 1][j] == 1)
            count++;
        if (i - 1 >= 0 && j + 1 < num[0].size() && num[i - 1][j + 1] == 1)
            count++;
        if (j - 1 >= 0 && num[i][j - 1] == 1)
            count++;
        if (j + 1 < num[0].size() && num[i][j + 1] == 1)
            count++;
        if (i + 1 < num.size() && j - 1 >= 0 && num[i + 1][j - 1] == 1)
            count++;
        if (i + 1 < num.size() && num[i + 1][j] == 1)
            count++;
        if (i + 1 < num.size() && j + 1 < num[0].size() && num[i + 1][j + 1] == 1)
            count++;
        return count;
    }

    void jishu(vector<vector<int>>& arr, vector<vector<int>> image, int Length, int Width)
    {
        for (int i = 0; i < Length; i++)
        {
            for (int j = 0; j < Width; j++)
            {
                arr[i + 1][j + 1] = MyAdd(image,i,j);
            }
        }
    }

    void zhuanhuan(vector<vector<int>>& arr, vector<vector<int>>& image, int Length, int Width)
    {
        for (int i = 0; i < Length; i++)
        {
            for (int j = 0; j < Width; j++)
            {
                if (arr[i + 1][j + 1] == 3)
                    image[i][j] = 1;
                else if (arr[i + 1][j + 1] < 2 || arr[i + 1][j + 1]>3)
                    image[i][j] = 0;
            }
        }
    }

    void print(vector<vector<int>>& arr, int Length, int Width)
    {
        for (int i = 0; i < Length; i++)
        {
            for (int j = 0; j < Width; j++)
            {
                cout << ' '<< arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

    void gameOfLife(vector<vector<int>>& board) 
    {
        int Length = board.size();
        int Width = board[0].size();
            vector<vector<int>> arr(Length + 2);
            Init(arr, board, Length, Width);
            jishu(arr, board, Length, Width);
            zhuanhuan(arr, board, Length, Width);
    }
};