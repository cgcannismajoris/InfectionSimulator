#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

class orderedPair
{

    private:
        double xComponent;
        double yComponent;

    public:
        orderedPair(double x = 0.0, double y = 0.0);
        ~orderedPair();

        double getX();
        void   setX(double xComponent);
        double getY();
        void   setY(double yComponent);

        void swap();
};

#endif // ORDEREDPAIR_H
