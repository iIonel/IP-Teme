int scari(int a)
{
    if(a == 1) return 1;
    if(a == 2) return 2;
    return scari(a - 1) + scari(a - 2);
}
