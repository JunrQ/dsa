typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items; // an array to ht_item*
} ht_hash_table;

ht_hash_table* ht_new();
static ht_item* ht_new_item(const char* k, const char* v);
static void ht_del_item(ht_item* i);
void ht_del_hash_table(ht_hash_table* ht);
