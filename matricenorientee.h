#ifndef MATRICENORIENTEE_H
#define MATRICENORIENTEE_H
#include <matrice.h>


class MatriceNOrientee : public Matrice
{
public:
    typedef Matrice super; // note that it could be hidden in

    MatriceNOrientee(vector<float>);
    void linkTo(int a, int b, int value) override;
};

#endif // MATRICENORIENTEE_H
