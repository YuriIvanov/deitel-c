#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 12

static const char* DAYS_TO_STRINGS[MAX_DAYS + 1] = {
    "",
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth",
    "seventh",
    "eighth",
    "ninth",
    "tenth",
    "eleventh",
    "twelfth",
};

static const char FIRST_DAY_GIFTS[] =
    "A partridge in a pear tree";

static const char SECOND_DAY_GIFTS[] =
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char THIRD_DAY_GIFTS[] =
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char FOURTH_DAY_GIFTS[] =
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char FIFTH_DAY_GIFTS[] =
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char SIXTH_DAY_GIFTS[] =
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char SEVENTH_DAY_GIFTS[] =
    "Seven swans a-swimming\n"
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char EIGTH_DAY_GIFTS[] =
    "Eight maids a-milking\n"
    "Seven swans a-swimming\n"
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char NINTH_DAY_GIFTS[] =
    "Nine ladies dancing\n"
    "Eight maids a-milking\n"
    "Seven swans a-swimming\n"
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char TENTH_DAY_GIFTS[] =
    "Ten lords a-leaping\n"
    "Nine ladies dancing\n"
    "Eight maids a-milking\n"
    "Seven swans a-swimming\n"
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char ELEVENTH_DAY_GIFTS[] =
    "Eleven pipers piping\n"
    "Ten lords a-leaping\n"
    "Nine ladies dancing\n"
    "Eight maids a-milking\n"
    "Seven swans a-swimming\n"
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char TWELFTH_DAY_GIFTS[] =
    "Twelve drummers drumming\n"
    "Eleven pipers piping\n"
    "Ten lords a-leaping\n"
    "Nine ladies dancing\n"
    "Eight maids a-milking\n"
    "Seven swans a-swimming\n"
    "Six geese a-laying\n"
    "Five golden rings\n"
    "Four calling birds\n"
    "Three french hens\n"
    "Two turtle doves, and\n"
    "A partridge in a pear tree";

static const char* GIFTS_BY_DAYS[MAX_DAYS + 1] = {
    NULL,
    FIRST_DAY_GIFTS,
    SECOND_DAY_GIFTS,
    THIRD_DAY_GIFTS,
    FOURTH_DAY_GIFTS,
    FIFTH_DAY_GIFTS,
    SIXTH_DAY_GIFTS,
    SEVENTH_DAY_GIFTS,
    EIGTH_DAY_GIFTS,
    NINTH_DAY_GIFTS,
    TENTH_DAY_GIFTS,
    ELEVENTH_DAY_GIFTS,
    TWELFTH_DAY_GIFTS
};

static void assertDay(const int day) {
    if (day < 1 || day > MAX_DAYS) {
        puts("Day should be between 1 and 12.");
        exit(-1);
    }
}

static const char* const dayToString(const int day) {
    assertDay(day);
    return DAYS_TO_STRINGS[day];
}

static const char* const getGiftsByDay(const int day) {
    assertDay(day);
    return GIFTS_BY_DAYS[day];
}

int main(void) {
    for (int day = 1; day <= 12; ++day) {
        printf("On the %s day of Christmas\n"
               "my true love sent to me:\n"
               "%s\n",
               dayToString(day),
               getGiftsByDay(day));
        puts("");
    }

    return EXIT_SUCCESS;
}
