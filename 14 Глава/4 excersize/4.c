#include <stdio.h>
#include <string.h>
#include "bank_user.h"

void output(struct bank_user user) {
    char middle_name_short[3];
    if (strlen((user.user_full_name).middle_name) > 0) {
        middle_name_short[0] = (user.user_full_name).middle_name[0];
        middle_name_short[1] = '.';
    } else {
        middle_name_short[0] = '\0';
    }
    printf("%s, %s, %s -- %d\n", (user.user_full_name).first_name, 
    (user.user_full_name).last_name, middle_name_short,
     user.card_number);
}

int main(void) {
    //struct bank_user simple_structure = {302039823, {"Dribble", "Markovich", "Flossie"}};
    struct bank_user bank_users[5] = {
        {302039823, {"Dribble", "Markovich", "Flossie"}},
        {422039879, {"Yaroslav", "Igorevich", "Golovko"}},
        {592039821, {"Ivan", "Ivanovich", "Ivanovich"}},
        {682039850, {"Natalya", "Sashovna", "Cikun"}},
        {732039818, {"Vovan", "Albertovich", "Enshtein"}},
    };
    for (int i = 0; i < 5; ++i) {
        output(bank_users[i]);
    }
    return 0;
}