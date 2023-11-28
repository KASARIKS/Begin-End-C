struct month_name
{
    char full_name[12][15];
    int days[12];
};

const struct month_name names = {
    {"January", "February", "March", "April", "May", "June", "Jule", "August", "September", "October", "November", "December"},
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};