struct full_name {
    char first_name[30], middle_name[30], last_name[30];
};

struct bank_user {
    unsigned card_number;
    struct full_name user_full_name;
}; 