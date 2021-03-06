#define VT_POINT 1
#define VT_LINE 2
#define VT_POLYGON 3

#define VT_END 0
#define VT_MOVETO 1
#define VT_LINETO 2
#define VT_CLOSEPATH 7

#define VT_STRING 1
#define VT_NUMBER 2
#define VT_BOOLEAN 7

struct pool;

void serialize_int(FILE *out, int n, long long *fpos, const char *fname);
void serialize_long_long(FILE *out, long long n, long long *fpos, const char *fname);
void serialize_byte(FILE *out, signed char n, long long *fpos, const char *fname);
void serialize_uint(FILE *out, unsigned n, long long *fpos, const char *fname);
void serialize_string(FILE *out, const char *s, long long *fpos, const char *fname);

void deserialize_int(char **f, int *n);
void deserialize_long_long(char **f, long long *n);
void deserialize_uint(char **f, unsigned *n);
void deserialize_byte(char **f, signed char *n);
struct pool_val *deserialize_string(char **f, struct pool *p, int type);

long long write_tile(char **geom, char *metabase, char *stringpool, unsigned *file_bbox, int z, unsigned x, unsigned y, int detail, int min_detail, int basezoom, struct pool **file_keys, char **layernames, sqlite3 *outdb, double droprate, int buffer, const char *fname, FILE **geomfile, int file_minzoom, int file_maxzoom, double todo, char *geomstart, long long along, double gamma, int nlayers, char *prevent, char *additional);

int traverse_zooms(int *geomfd, off_t *geom_size, char *metabase, char *stringpool, struct pool **file_keys, unsigned *midx, unsigned *midy, char **layernames, int maxzoom, int minzoom, sqlite3 *outdb, double droprate, int buffer, const char *fname, const char *tmpdir, double gamma, int nlayers, char *prevent, char *additional, int full_detail, int low_detail, int min_detail);

extern unsigned initial_x, initial_y;
extern int geometry_scale;
extern int quiet;

extern int CPUS;
extern int TEMP_FILES;
