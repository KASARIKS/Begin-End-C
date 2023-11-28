#include "player.h"
#include <stdio.h>
#include <string.h>
#define MAX 10

int is_there(struct player players[MAX], int count_players, char first_name[30], char last_name[30]) {
    for (int i = 0; i < count_players; ++i) {
        if (!strcmp(players[i].first_name, first_name) && !strcmp(players[i].second_name, last_name)) return i;
    }
    return -1;
}

int main(void) {
    struct player players[MAX];
    int count_players;
    FILE *fp = fopen("players.txt", "r");
    int EOF_value;
    
    char first_name[30], last_name[30];
    int balls, walks, runs;

    for (count_players = 0; EOF_value != EOF; ++count_players) {
        EOF_value = fscanf(fp, "%*d %s %s %d %*d %d %d", first_name, last_name, &balls, &walks, &runs);
        int check_player = is_there(players, count_players, first_name, last_name);
        if (check_player == -1) {
            strcpy(players[count_players].first_name, first_name);
            strcpy(players[count_players].second_name, last_name);
            players[count_players].balls = balls;
            players[count_players].walks = walks;
            players[count_players].runs = runs;
        } else {
            players[check_player].balls += balls;
            players[check_player].walks += walks;
            players[check_player].runs += runs;
            --count_players;
        }
    }
    for (int i = 0; i < count_players; ++i) {
        printf("%s %s %d %d %d\n", 
        players[i].first_name, players[i].second_name,
        players[i].balls, players[i].walks, players[i].runs);
    }
    return 0;
}