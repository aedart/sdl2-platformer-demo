#ifndef POSITION_H
#define POSITION_H

/**
 * Position
 */
class Position
{
    public:
        /**
         * X Position
         */
        int x;

        /**
         * Y Position
         */
        int y;

        /**
         * Constructor
         */
        Position();

        /**
         * Constructor
         *
         * @param x The X position
         * @param y The Y position
         */
        Position(int x, int y);

        /**
         * Prints position to stdout
         */
        void print() const;
};

#endif  // POSITION_H
