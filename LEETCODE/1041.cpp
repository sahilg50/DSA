class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int dirX = 0, dirY = 1; // Indicates the direction.
        int x = 0, y = 0;       // Indicates the position.
        int temp;               //Temporary variable.

        for (char &ins : instructions)
        {
            if (ins == 'G')
            {
                x += dirX;
                y += dirY;
            }
            else if (ins == 'L')
            {
                temp = dirX;
                dirX = -1 * dirY; //According to the linear algebra rule.
                dirY = temp;
            }
            else
            {
                temp = dirX;
                dirX = dirY;
                dirY = -1 * temp;
            }
        }

        // Return true if the position is unchanged.
        // Return true if the direction is not north.
        // Return false in every other case.
        if ((x == 0 && y == 0) || !(dirX == 0 && dirY == 1))
            return true;
        else
            return false;
    }
};

/*
TC: O(N) where N is the size of the input string.
SC: O(1)
*/